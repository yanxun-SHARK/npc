#include <readline/readline.h>
#include <readline/history.h>
#include "common.h"
#include "Vtop.h"
#define VTOP Vtop
typedef uint32_t word_t;
static int is_batch_mode = false;
word_t expr(char *e, bool *success);

extern VTOP *top;
extern int NPC_state;
extern uint32_t nn;
void NPC_exec(int n);
void init_regex();
void init_wp_pool();
int new_wp(char *args);
void print_wp_list();
void delete_wp(int NO);

static int cmd_help(char *args);
static int cmd_c(char *args);
static int cmd_x(char *args);
static int cmd_info(char *args);
static int cmd_si(char *args);
static int cmd_q(char *args);
static int cmd_p(char *args);

#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_NONE       "\33[0m"
#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  init_wp_pool();
  init_regex();
}

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

extern "C" int read_reg(int idx);

extern "C" int read_pc();

extern "C" int pmem_read(int raddr);

static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}
static int cmd_info (char *args) {
  if(args && strcmp(args, "r") == 0){
    for(int i = 0 ; i < 32 ; i++){
      printf("%3s 0x%08x %010d\n",regs[i],read_reg(i),read_reg(i));
    }
  }
  else if(args && strcmp(args, "w") == 0)print_wp_list();
  return 0;
}
static int cmd_x(char *args){
  int len;
  uint32_t addr;
  sscanf(args, "%d %x", &len, &addr);
  for (int i = 0; i < len; i += 16) {
    printf("0x%08x: ", addr + i);
    for (int j = 0; j < 16 && i + j < len; j++) {
      int word_addr = (addr + i + j) & ~3;
      int byte_off  = (addr + i + j) & 3;
      int word = pmem_read(word_addr);
      uint8_t byte = (word >> (byte_off * 8)) & 0xFF;
      printf("%02x ", byte);
    }
    printf("\n");
  }
  return 0;
}
static int cmd_c(char *args) {
  NPC_exec(-1);
  return 0;
}
static int cmd_si(char *args) {
  int n = (args == NULL) ? 1 : atoi(args);
  NPC_exec(n);
  return 0;
}
static int cmd_q(char *args) {
  NPC_state = NPC_QUIT;
  return -1;
}
static int cmd_p(char *args) {
  char *e = NULL;
    size_t len = 0;
    bool success;
    ssize_t ret = getline(&e, &len, stdin);
    if (ret > 0 && e[ret - 1] == '\n') {
        e[ret - 1] = '\0';
    }
    if (e == NULL) {
        printf("读取输入失败\n");
        return -1;
    }

    word_t result = expr(e, &success);

    if (success) {
        printf("%s = %u\n", e, result);
    } else {
        printf("表达式解析失败: %s\n", e);
    }

    free(e);
    return 0;
}
static int cmd_w(char *args){
  if (args == NULL) {
    printf("Usage: w <expression>\n");
    return 0;
  }
  new_wp(args);
  return 0;
}

static int cmd_d(char *args){
  if (args == NULL) {
    printf("Usage: d <expression>\n");
    return 0;
  }
  int NO = atoi(args);
  delete_wp(NO);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si", "Single-step execution", cmd_si },
  { "info", "View register information", cmd_info },
  { "x", "Scan memory", cmd_x },
  { "p", "Expression Evaluation", cmd_p },
  { "w", "Make Watchpoint", cmd_w },
  { "d", "Delate Watchpoint", cmd_d }
};
#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  welcome();

  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}
