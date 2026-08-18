// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(790);
    // Setup sub module instances
    TOP__top.ctor(this, "top");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.top = &TOP__top;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top = new VerilatedScope{this, "top", "top", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top__my_EXU__my_alu = new VerilatedScope{this, "top.my_EXU.my_alu", "my_alu", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top__my_IFU = new VerilatedScope{this, "top.my_IFU", "my_IFU", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top__my_LSU = new VerilatedScope{this, "top.my_LSU", "my_LSU", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_top__my_MBU__my_reg = new VerilatedScope{this, "top.my_MBU.my_reg", "my_reg", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("ebreak", &(TOP.ebreak), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("halt_code", &(TOP.halt_code), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("pc", &(TOP.pc), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_top->varInsert("ebreak", &(TOP__top.ebreak), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_top->varInsert("halt_code", &(TOP__top.halt_code), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_top->varInsert("pc", &(TOP__top.pc), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_top->varInsert("pc_", &(TOP__top.pc_), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 1 ,31,0);
    __Vscopep_top__my_MBU__my_reg->varInsert("rf", &(TOP__top.my_MBU__DOT__my_reg__DOT__rf), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,31,0 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top, __Vscopep_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__my_EXU__my_alu, __Vscopep_top__my_EXU__my_alu = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__my_IFU, __Vscopep_top__my_IFU = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__my_LSU, __Vscopep_top__my_LSU = nullptr);
    VL_DO_CLEAR(delete __Vscopep_top__my_MBU__my_reg, __Vscopep_top__my_MBU__my_reg = nullptr);
    // Tear down sub module instances
    TOP__top.dtor();
}
