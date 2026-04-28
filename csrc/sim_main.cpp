#define VCD_TRACE true
#include <stdio.h>
#include <stdbool.h>
#include "verilated_vcd_c.h"
#include "Vtop.h"        // 根据你自己的模块名替换
#define VTOP Vtop        // 根据你自己的模块名替换
#define TIMESCALE 5

#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)

#define __IGNORE(...)
#define __KEEP(...) __VA_ARGS__

#define __P_DEF_false X,
#define __P_DEF_true  X,

#define CHOOSE_B(A, B, ...) B
#define CALL_CHOOSE_B(A, B, ...) CHOOSE_B(A, B, __VA_ARGS__)        // 保证concat在调用CHOOSE_B前完成
#define IFDEF(macro, ...) CALL_CHOOSE_B(concat(__P_DEF_, macro) __KEEP, __IGNORE)(__VA_ARGS__)
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

int main(int argc, char **argv) {
  VTOP *top;
  VerilatedContext *contextp;
#ifdef VCD_TRACE
            VerilatedVcdC *tfp;
#endif

        if(!init_sim(
                &top, &contextp
#ifdef VCD_TRACE
                , &tfp
#endif
        )){
                return -1;
        }

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

#define EvalOnce() {        \
        top->clk ^= 1;        \
        top->eval();        \
        contextp->timeInc(TIMESCALE);\
        IFDEF(VCD_TRACE, tfp->dump(contextp->time());)\
}
        EvalRst();
        while (!contextp->gotFinish()) { 
                EvalOnce();
        }

        finish(
                &top, &contextp
#ifdef VCD_TRACE
                , &tfp
#endif
        );

        return 0;
}