#ifndef __TRACE_H__
#define __TRACE_H__

#include <stdio.h>
#include <string.h>
#include "common.h"
#include <elf.h>

#define MAX_iringbuf 100  //最大容量
#define MAX_FUNC     1024 //最大函数

typedef struct {
    uint32_t addr;        //函数地址
    const char* name;     //函数名
}FuncSymbol;

typedef struct{
    FuncSymbol funcs[MAX_FUNC];//函数表
    int func_count;            //函数数量
    FILE *fp;                  //函数文件
    uint32_t call_stack[100];  //栈
    int call_stack_top;        //栈顶

}Ftrace_keep;

extern Ftrace_keep ftrace;

void make_irbuf(char *log_buf);                      //保留近MAX_iringbuf函数
void irbuf_dump();                                   //输出到终端
void init_mtrace();                                  //
void log_mtrace(paddr_t addr, int len, word_t data); //
void init_ftrace(const char *ftrace_file);           //
void check_call_ret(uint32_t pc, uint32_t inst, uint32_t next_pc);
void log_call(uint32_t target_addr , uint32_t pc);
void log_ret(uint32_t pc);
void log_itrace(uint32_t, uint32_t);


#endif
