#define VCD_TRACE true
//#define PRINTF_CODE true
#include <stdio.h>
#include <stdbool.h>
#include "verilated_vcd_c.h"
#include "Vtop.h"  
#include "Vtop_top.h"    
#include "trace/trace.h"
#include "trace/disasm.h"
  // 根据你自己的模块名替换
#define VTOP Vtop        // 根据你自己的模块名替换
#define TIMESCALE 5
//enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };
#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;45m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE


extern "C" size_t pmem_load(const char* filename);
static bool ebreak_tip = false;
extern "C" void ebreak_notice (int halt_code){
        ebreak_tip = true;
};
IFDEF(CONFIG_DIFFTEST, void init_difftest(long img_size, int port);)
IFDEF(CONFIG_DIFFTEST, void difftest_step();)
void sdb_mainloop();
void sdb_set_batch_mode();
void NPC_exec(int n );
int  check_watchpoints();
void init_itrace();
size_t img_size ;
#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)

#define __IGNORE(...)
#define __KEEP(...) __VA_ARGS__

#define __P_DEF_false X,
#define __P_DEF_true  X,

#define CHOOSE_B(A, B, ...) B
#define CALL_CHOOSE_B(A, B, ...) CHOOSE_B(A, B, __VA_ARGS__)        // 保证concat在调用CHOOSE_B前完成
//#define IFDEF(macro, ...) CALL_CHOOSE_B(concat(__P_DEF_, macro) __KEEP, __IGNORE)(__VA_ARGS__)
// 如果用宏定义macro为true或false, 则有以下过程
// IFDEF(macro, ...) -> __KEEP(...) -> ...

bool init_sim(VTOP **dut/*device under test*/, VerilatedContext **contextp/*context pointer*/
#ifdef VCD_TRACE
, VerilatedVcdC **tfp        // trace file pointer
#endif
){
        printf("Sim init start\n");
        const char* ftraceFileName = "Top_trace.vcd";
        *contextp = new VerilatedContext;
        (*contextp)->randReset(2);        // 使用随机初始值, 需要开启--x-assign unique 选项
        (*contextp)->randSeed(12345);
        *dut = new VTOP{*contextp};
#ifdef VCD_TRACE
        Verilated::traceEverOn(true);
        *tfp = new VerilatedVcdC;
        (*dut)->trace((*tfp), 0);        // 需要开启verilator 的 --trace-vcd 选项
        (*tfp)->open(ftraceFileName);
        if((*tfp)->isOpen()){
                printf("Open VCD trace file %s success\n", ftraceFileName);
        }else {
                printf("Open VCD trace file %s failed \n", ftraceFileName);
                return false;
        }
#endif
        printf("Sim init end\n");
        return true;
}



void finish(VTOP **dut, VerilatedContext **contextp
#ifdef VCD_TRACE
, VerilatedVcdC **tfp
#endif
){
        delete *dut;
        delete *contextp;
        #ifdef VCD_TRACE
        (*tfp)->close();
        #endif
        printf("Sim finished\n");
}
int NPC_state = NPC_RUNNING; 
uint32_t nn =0;
VTOP *top;
VerilatedContext *contextp;
#ifdef VCD_TRACE
        VerilatedVcdC *tfp;
#endif



extern "C" int read_reg(int idx) {
    return top->top->my_MBU__DOT__my_reg__DOT__rf[idx];
}

extern "C" int read_pc() {
    return top->pc;
}
int main(int argc, char **argv) {
        if(!init_sim(
                &top, &contextp
#ifdef VCD_TRACE
                , &tfp
#endif
        )){
                return -1;
        }
        char *img_file = NULL;
        if (argc > 1) {
                img_file = argv[1];
                img_size = pmem_load(img_file);
        } else {
                printf("Usage: %s <image_file>\n", argv[0]);
                return -1;
        }
        IFDEF(CONFIG_ITRACE, init_disasm());
        IFDEF(CONFIG_MTRACE, init_mtrace());
        IFDEF(CONFIG_ITRACE, init_itrace());

//        IFDEF(CONFIG_FTRACE, init_ftrace());

#define EvalRst() {        \
        top->rst = 1;        \
        top->clk = 0;        \
        top->eval();        \
        IFDEF(VCD_TRACE, tfp->dump(contextp->time());) \
        \
        top->clk = 1;        \
        top->eval();        \
        contextp->timeInc(TIMESCALE);\
        IFDEF(VCD_TRACE, tfp->dump(contextp->time());) \
        \
        top->rst = 0;        \
}
//        uint32_t reset_cycles = 10;
        
#define EvalOnce() {        \
        top->clk ^= 1;        \
        top->eval();        \
        contextp->timeInc(TIMESCALE);\
        IFDEF(VCD_TRACE, tfp->dump(contextp->time());)\
}       
        EvalRst();
        
        IFDEF(CONFIG_DIFFTEST, init_difftest(img_size, 0);)
        IFDEF(CONFIG_BATCH, sdb_set_batch_mode();)
        sdb_mainloop();
        
        printf("Exit loop: nn=%d, ebreak=%d, halt_code=%d, pc=0x%x\n", nn, top->ebreak, top->halt_code, top->pc);

        if (top->ebreak) {
                if (top->halt_code == 0) {
                        printf(ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) " at pc = 0x%x\n", top->pc);
                } else {
                        printf(ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED) " at pc = 0x%x, halt code = %d\n",
                                top->pc, top->halt_code);
                }
        }
        IFDEF(CONFIG_IRINGBUF, irbuf_dump();)
        finish(
                &top, &contextp
#ifdef VCD_TRACE
                , &tfp
#endif
        );

        return 0;
}
void NPC_exec(int n ) {
        for (int i = 0; (n == -1 || i < n); i++) {
        if (NPC_state == NPC_QUIT) break;
        if (top->ebreak || ebreak_tip) {
            NPC_state = NPC_END;
            break;
        }
        EvalOnce();
        IFDEF(CONFIG_ITRACE,log_itrace(top->pc, top->top_inst);)
        IFDEF(CONFIG_IRINGBUF, {
        char buf[128];
        sprintf(buf, "%08x: %08x", top->pc, top->top_inst);
        make_irbuf(buf);
        })
        EvalOnce();
        nn++;
        IFDEF(CONFIG_DIFFTEST, difftest_step();)
        int wp_no = check_watchpoints();
        if (wp_no >= 0) {
        printf("Watchpoint %d triggered!\n", wp_no);
        NPC_state = NPC_STOP;
        break;
        }
        
        }
}