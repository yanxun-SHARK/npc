// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ clk;
    CData/*0:0*/ rst;
    CData/*0:0*/ ebreak;
    CData/*0:0*/ __PVT__mem_we;
    CData/*0:0*/ __PVT__rf_wen;
    CData/*0:0*/ __PVT__jal;
    CData/*4:0*/ __PVT__rf_waddr;
    CData/*3:0*/ __PVT__mem_wmask;
    CData/*0:0*/ __PVT__ecall;
    SData/*11:0*/ __PVT__imms;
    SData/*11:0*/ __PVT__immb;
    IData/*31:0*/ pc;
    IData/*31:0*/ halt_code;
    IData/*31:0*/ top_inst;
    IData/*19:0*/ __PVT__immj;
    IData/*31:0*/ pc_;
    IData/*31:0*/ __PVT__inst;
    IData/*31:0*/ __PVT__src1;
    IData/*31:0*/ __PVT__src2;
    IData/*31:0*/ __PVT__mem_addr;
    IData/*31:0*/ __PVT__mem_wdata;
    IData/*31:0*/ __PVT__mem_rdata;
    IData/*31:0*/ __PVT__rf_wdata;
    IData/*31:0*/ __PVT__jal_target;
    IData/*31:0*/ __PVT__csr_wdata;
    IData/*31:0*/ __PVT__csr_rdata;
    IData/*31:0*/ __PVT__csr_waddr;
    IData/*31:0*/ __PVT__csr_raddr;
    IData/*31:0*/ __PVT__my_MBU__DOT__my_pc__DOT__pc;
    IData/*31:0*/ __PVT__my_MBU__DOT__my_pc__DOT__pc_4;
    IData/*31:0*/ __PVT__my_CSR__DOT__MCYCLE_reg;
    IData/*31:0*/ __PVT__my_CSR__DOT__MCYCLEH_reg;
    IData/*31:0*/ __PVT__my_CSR__DOT__MSTATUS_reg;
    IData/*31:0*/ __PVT__my_CSR__DOT__MEPC_reg;
    IData/*31:0*/ __PVT__my_CSR__DOT__MCAUSE_reg;
    IData/*31:0*/ __PVT__my_CSR__DOT__MTVEC_reg;
    IData/*31:0*/ __Vfunc_my_LSU__DOT__pmem_read__1__Vfuncout;
    IData/*31:0*/ __Vfunc_my_IFU__DOT__pmem_read__3__Vfuncout;
    VlUnpacked<IData/*31:0*/, 32> my_MBU__DOT__my_reg__DOT__rf;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_top();
    ~Vtop_top();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
