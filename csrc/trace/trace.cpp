#include "trace.h"
#include "disasm.h"
static char irbuf[MAX_iringbuf][128];
static int irbuf_i = 0;

static FILE *mtrace_fp = NULL;
static FILE *ftrace_fp = NULL;
static FILE *itrace_fp = NULL;
int JAL_i;
Ftrace_keep ftrace;
void make_irbuf(char *log_buf) {
    strncpy(irbuf[irbuf_i], log_buf, 127);
    irbuf[irbuf_i][127] = '\0';
    irbuf_i = (irbuf_i + 1) % MAX_iringbuf;
}

void irbuf_dump() {
    printf("========== IRINGBUF (recent %d instructions) ==========\n", MAX_iringbuf);
    for (int i = 0; i < MAX_iringbuf; i++) {
        int idx = (irbuf_i + i) % MAX_iringbuf;
        if (irbuf[idx][0] != '\0') {
            printf("# %s\n", irbuf[idx]);
        }
    }
    printf("========================================================\n");
}

void init_mtrace() {
    mtrace_fp = fopen("build/npc-mtrace.txt", "w");
    assert(mtrace_fp);
}

void log_mtrace(paddr_t addr, int len, word_t data) {
    if (mtrace_fp != NULL) {
        fprintf(mtrace_fp, FMT_PADDR ": %d-byte write, data = " FMT_WORD "\n",addr, len, data);
        fflush(mtrace_fp);
    }
}

void init_ftrace(const char *ftrace_file) {
    if (ftrace_file == NULL) return;
    ftrace_fp = fopen(ftrace_file,"rb");
    if (ftrace_fp == NULL) {
        printf("ftrace: cannot open ELF file '%s'\n", ftrace_file);
        return;
    }
    Elf32_Ehdr ehdr;
    int f1 =fread(&ehdr , sizeof(ehdr) , 1 , ftrace_fp);
    assert(f1 == 1);
    if(ehdr.e_ident[0] != '\x7f'||ehdr.e_ident[1] != 'E'||ehdr.e_ident[2] != 'L'||ehdr.e_ident[3] != 'F') {
        printf("error : is not a .elf");
        fclose(ftrace_fp);
        ftrace_fp = NULL;
        return;
    }
    fseek(ftrace_fp , ehdr.e_shoff ,SEEK_SET	);
    Elf32_Shdr shdr[ehdr.e_shnum];
    int f2 =fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, ftrace_fp );
    assert(f2 == ehdr.e_shnum);
    int symtabidx = -1;
    for(int i = 0; i < ehdr.e_shnum ; i++) {
        if(shdr[i].sh_type == SHT_SYMTAB) { symtabidx = i; break; }
    }
    if (symtabidx == -1) {
        printf("ftrace: no symbol table found\n");
        fclose(ftrace_fp);
        ftrace_fp = NULL;
        return;
    }

    Elf32_Shdr shsymtab = shdr[symtabidx];
    Elf32_Sym*  symtab = (decltype(symtab))malloc(shsymtab.sh_size);
    fseek(ftrace_fp,shsymtab.sh_offset,SEEK_SET);
    int f3 = fread(symtab,shsymtab.sh_size,1,ftrace_fp);
    assert(f3 == 1);

    Elf32_Shdr shstrtab = shdr[shsymtab.sh_link];
    char * strtab = (decltype(strtab))malloc(shstrtab.sh_size);
    fseek(ftrace_fp,shstrtab.sh_offset,SEEK_SET);
    int f4 = fread(strtab,shstrtab.sh_size,1,ftrace_fp);
    assert(f4 == 1);
    int tabtab = shsymtab.sh_size/shsymtab.sh_entsize;

    ftrace.func_count = 0;
    for (int i = 0; i < tabtab; i++) {
        if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC) {
            ftrace.funcs[ftrace.func_count].addr = symtab[i].st_value;
            ftrace.funcs[ftrace.func_count].name = strdup(&strtab[symtab[i].st_name]);
            ftrace.func_count++;
        }
    }
    
    free(symtab);
    free(strtab);
    fclose(ftrace_fp);
    ftrace.fp = fopen("build/npc-ftrace.txt", "w");
    assert(ftrace.fp != NULL);
    ftrace.call_stack_top = 0;
}

    
void check_call_ret(uint32_t pc, uint32_t inst, uint32_t next_pc){
    if (ftrace.fp == NULL) return;
    uint32_t opcode , funct3;
    opcode = (inst &0x7f);
    funct3 = (inst >> 12)&0x7;
    if (opcode == 0b1101111) JAL_i = 1;
    else if (opcode == 0b1100111 && funct3 == 0b000) JAL_i = 2; 
    else JAL_i = 0 ;
    uint32_t rs1 = 0,rd= 0,imm12= 0;
    switch (JAL_i) {
        case 2: rs1 = (inst >> 15)&0x1f;imm12 = (inst >> 20) & 0xfff;rd  = (inst >> 7 )&0x1f;break;
        case 1: rd  = (inst >> 7 )&0x1f;break;
        default: break;
    }
    switch (JAL_i) {
        case 2: if (rd == 0 && rs1 == 1 && imm12 == 0) {
            log_ret(pc);
        } else if (rd == 1) {
            log_call(next_pc, pc);
        }
        break;
        case 1: if (rd == 1) {
            log_call(next_pc, pc);
        }
        break;
        default: break;
    }
    
}

static const char* find_func_name(uint32_t addr) {
    for(int i = 0 ; i < ftrace.func_count ; i++) {
        if(addr == ftrace.funcs[i].addr) return ftrace.funcs[i].name;
    }
    return 0;
}

void log_call(uint32_t target_addr , uint32_t pc) {
    const char* name = find_func_name(target_addr);
    if( name == NULL) name = "???";
    for (int i = 0 ; i < ftrace.call_stack_top ; i++) fprintf(ftrace.fp, "  ");   
    fprintf(ftrace.fp, "0x%08x: call [%s@0x%08x]\n",pc,name,target_addr);
    ftrace.call_stack[ftrace.call_stack_top] = target_addr;
    ftrace.call_stack_top++;

}

void log_ret(uint32_t pc) {
    if(ftrace.call_stack_top == 0) return;
    ftrace.call_stack_top --;
    uint32_t ret_addr = ftrace.call_stack[ftrace.call_stack_top]; 
    const char * name = find_func_name(ret_addr);
    if( name == NULL) name = "???";
    for ( int i = 0; i < ftrace.call_stack_top ; i++) fprintf(ftrace.fp, "  ");
    fprintf(ftrace.fp, "0x%08x: ret [%s@0x%08x]\n",pc,name,ret_addr);
}
void init_itrace() {
    itrace_fp = fopen("build/npc-itrace.txt", "w");
    assert(itrace_fp);
}
void log_itrace(uint32_t pc, uint32_t inst) {
    if(itrace_fp != NULL) {
        uint8_t code[4];
        code[0] = inst & 0xff;
        code[1] = (inst >> 8) & 0xff;
        code[2] = (inst >> 16) & 0xff;
        code[3] = (inst >> 24) & 0xff;

        char buf[128];
        disassemble(buf, sizeof(buf), pc, code, 4);
        fprintf(itrace_fp, "0x%08x: %02x %02x %02x %02x  %s\n",pc, code[0], code[1], code[2], code[3], buf);
        fflush(itrace_fp);
    }
    
}

/*void log_dtrace_r(paddr_t addr, int len, IOMap *map) {
    printf("\n");
    printf("0x%08x: [%s] read  %d-bytes\n",addr,map->name,len);
}
void log_dtrace_w(paddr_t addr, int len, word_t data, IOMap *map) {
    printf("\n");
    printf("0x%08x: [%s] write %d-bytes data = 0x%08u\n",addr,map->name,len,data);
}
*/



