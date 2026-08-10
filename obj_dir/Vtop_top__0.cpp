// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

extern "C" void ebreak_notice(int halt_code);

void Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ halt_code) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top\n"); );
    // Body
    int halt_code__Vcvt;
    halt_code__Vcvt = halt_code;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    ebreak_notice(halt_code__Vcvt);
}

extern "C" int pmem_read(int raddr);

void Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top\n"); );
    // Body
    int raddr__Vcvt;
    raddr__Vcvt = raddr;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

void Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_write_TOP__top(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_write_TOP__top\n"); );
    // Body
    int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    char wmask__Vcvt;
    wmask__Vcvt = wmask;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

void Vtop_top___ico_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ico_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSelfRef.pc_;
    Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(
                                                           (vlSymsp->__Vscopep_top__my_IFU), 
                                                           "vsrc/IFU.v", 0x0000000bU, vlSelfRef.pc_, vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__4__Vfuncout);
    vlSelfRef.__PVT__inst = vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__4__Vfuncout;
    vlSelfRef.__PVT__imms = ((0x00000fe0U & (vlSelfRef.__PVT__inst 
                                             >> 0x00000014U)) 
                             | (0x0000001fU & (vlSelfRef.__PVT__inst 
                                               >> 7U)));
    vlSelfRef.__PVT__immb = ((((2U & (vlSelfRef.__PVT__inst 
                                      >> 0x0000001eU)) 
                               | (1U & (vlSelfRef.__PVT__inst 
                                        >> 7U))) << 0x0000000aU) 
                             | ((0x000003f0U & (vlSelfRef.__PVT__inst 
                                                >> 0x00000015U)) 
                                | (0x0000000fU & (vlSelfRef.__PVT__inst 
                                                  >> 8U))));
    vlSelfRef.__PVT__immj = ((0x00080000U & (vlSelfRef.__PVT__inst 
                                             >> 0x0000000cU)) 
                             | ((0x0007f800U & (vlSelfRef.__PVT__inst 
                                                >> 1U)) 
                                | ((0x00000400U & (vlSelfRef.__PVT__inst 
                                                   >> 0x0000000aU)) 
                                   | (0x000003ffU & 
                                      (vlSelfRef.__PVT__inst 
                                       >> 0x00000015U)))));
    vlSelfRef.__PVT__src1 = (vlSelfRef.my_MBU__DOT__my_reg__DOT__rf
                             [(0x0000001fU & (vlSelfRef.__PVT__inst 
                                              >> 0x0000000fU))] 
                             & (- (IData)((0U != (0x0000001fU 
                                                  & (vlSelfRef.__PVT__inst 
                                                     >> 0x0000000fU))))));
    vlSelfRef.__PVT__src2 = (vlSelfRef.my_MBU__DOT__my_reg__DOT__rf
                             [(0x0000001fU & (vlSelfRef.__PVT__inst 
                                              >> 0x00000014U))] 
                             & (- (IData)((0U != (0x0000001fU 
                                                  & (vlSelfRef.__PVT__inst 
                                                     >> 0x00000014U))))));
}

void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__my_MBU__DOT__my_pc__DOT__pc_4;
    __Vdly__my_MBU__DOT__my_pc__DOT__pc_4 = 0;
    IData/*31:0*/ __Vdly__halt_code;
    __Vdly__halt_code = 0;
    CData/*0:0*/ __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v0;
    __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v0 = 0;
    IData/*31:0*/ __VdlyVal__my_MBU__DOT__my_reg__DOT__rf__v32;
    __VdlyVal__my_MBU__DOT__my_reg__DOT__rf__v32 = 0;
    CData/*4:0*/ __VdlyDim0__my_MBU__DOT__my_reg__DOT__rf__v32;
    __VdlyDim0__my_MBU__DOT__my_reg__DOT__rf__v32 = 0;
    CData/*0:0*/ __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v32;
    __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v32 = 0;
    // Body
    __Vdly__halt_code = vlSelfRef.halt_code;
    __Vdly__my_MBU__DOT__my_pc__DOT__pc_4 = vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc_4;
    __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v0 = 0U;
    __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v32 = 0U;
    if (vlSelfRef.__PVT__mem_we) {
        Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_write_TOP__top(
                                                                (vlSymsp->__Vscopep_top__my_LSU), 
                                                                "vsrc/LSU.v", 0x00000013U, vlSelfRef.__PVT__mem_addr, vlSelfRef.__PVT__mem_wdata, (IData)(vlSelfRef.__PVT__mem_wmask));
    }
    if (vlSymsp->TOP.rst) {
        vlSelfRef.__PVT__my_MBU__DOT__my_reg__DOT__i = 0x00000020U;
        __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v0 = 1U;
        vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc = 0x80000000U;
        __Vdly__my_MBU__DOT__my_pc__DOT__pc_4 = 0x80000004U;
    } else {
        if (((IData)(vlSelfRef.__PVT__rf_wen) & (0U 
                                                 != (IData)(vlSelfRef.__PVT__rf_waddr)))) {
            __VdlyVal__my_MBU__DOT__my_reg__DOT__rf__v32 
                = vlSelfRef.__PVT__rf_wdata;
            __VdlyDim0__my_MBU__DOT__my_reg__DOT__rf__v32 
                = vlSelfRef.__PVT__rf_waddr;
            __VdlySet__my_MBU__DOT__my_reg__DOT__rf__v32 = 1U;
        }
        if (vlSelfRef.__PVT__jal) {
            vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc 
                = (0xfffffffeU & vlSelfRef.__PVT__jal_target);
            __Vdly__my_MBU__DOT__my_pc__DOT__pc_4 = 
                ((IData)(4U) + (0xfffffffeU & vlSelfRef.__PVT__jal_target));
        } else {
            vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc 
                = vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc_4;
            __Vdly__my_MBU__DOT__my_pc__DOT__pc_4 = 
                ((IData)(4U) + vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc_4);
        }
    }
    vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc_4 
        = __Vdly__my_MBU__DOT__my_pc__DOT__pc_4;
    vlSelfRef.pc_ = vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc;
    if (vlSymsp->TOP.rst) {
        vlSelfRef.__PVT__mem_addr = 0U;
        vlSelfRef.__PVT__mem_wdata = 0U;
        vlSelfRef.__PVT__mem_we = 0U;
        vlSelfRef.__PVT__mem_wmask = 0U;
        vlSelfRef.__PVT__rf_wen = 0U;
        vlSelfRef.__PVT__rf_waddr = 0U;
        vlSelfRef.__PVT__rf_wdata = 0U;
        vlSelfRef.__PVT__jal = 0U;
        vlSelfRef.ebreak = 0U;
        __Vdly__halt_code = 0U;
    } else {
        vlSelfRef.__PVT__mem_we = 0U;
        vlSelfRef.__PVT__mem_wmask = 0U;
        vlSelfRef.__PVT__rf_wen = 0U;
        vlSelfRef.__PVT__jal = 0U;
        vlSelfRef.ebreak = 0U;
        __Vdly__halt_code = 0U;
        if (((((((((0x00100073U == vlSelfRef.__PVT__inst) 
                   | (0x00000063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                  | (0x00001063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                 | (0x00005063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                | (0x00004063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
               | (0x00007063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
              | (0x00006063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
             | (0x00000033U == (0xfe00707fU & vlSelfRef.__PVT__inst)))) {
            if ((0x00100073U == vlSelfRef.__PVT__inst)) {
                Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top(
                                                                                (vlSymsp->__Vscopep_top__my_EXU__my_alu), 
                                                                                "vsrc/EXU.v", 0x0000009eU, vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[10U]);
                vlSelfRef.ebreak = 1U;
                __Vdly__halt_code = vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[10U];
            } else if ((0x00000063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = ((vlSelfRef.__PVT__src1 
                                         == vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else if ((0x00001063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = ((vlSelfRef.__PVT__src1 
                                         != vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else if ((0x00005063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = (VL_GTES_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else if ((0x00004063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = (VL_LTS_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else if ((0x00007063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = ((vlSelfRef.__PVT__src1 
                                         >= vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else if ((0x00006063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.pc 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__immb) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000dU) 
                                                | ((IData)(vlSelfRef.__PVT__immb) 
                                                   << 1U)));
                vlSelfRef.__PVT__jal = ((vlSelfRef.__PVT__src1 
                                         < vlSelfRef.__PVT__src2)
                                         ? 1U : 0U);
            } else {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
            }
        } else if (((((((((0x40000033U == (0xfe00707fU 
                                           & vlSelfRef.__PVT__inst)) 
                          | (0x00003033U == (0xfe00707fU 
                                             & vlSelfRef.__PVT__inst))) 
                         | (0x00004033U == (0xfe00707fU 
                                            & vlSelfRef.__PVT__inst))) 
                        | (0x00006033U == (0xfe00707fU 
                                           & vlSelfRef.__PVT__inst))) 
                       | (0x00001033U == (0xfe00707fU 
                                          & vlSelfRef.__PVT__inst))) 
                      | (0x00007033U == (0xfe00707fU 
                                         & vlSelfRef.__PVT__inst))) 
                     | (0x00002033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) 
                    | (0x00005033U == (0xfe00707fU 
                                       & vlSelfRef.__PVT__inst)))) {
            if ((0x40000033U == (0xfe00707fU & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             - vlSelfRef.__PVT__src2);
            } else if ((0x00003033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = ((vlSelfRef.__PVT__src1 
                                              < vlSelfRef.__PVT__src2)
                                              ? 1U : 0U);
            } else if ((0x00004033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             ^ vlSelfRef.__PVT__src2);
            } else if ((0x00006033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             | vlSelfRef.__PVT__src2);
            } else if ((0x00001033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = VL_SHIFTL_III(32,32,32, vlSelfRef.__PVT__src1, 
                                                          (0x0000001fU 
                                                           & vlSelfRef.__PVT__src2));
            } else if ((0x00007033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             & vlSelfRef.__PVT__src2);
            } else if ((0x00002033U == (0xfe00707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (VL_LTS_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                              ? 1U : 0U);
            } else {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = VL_SHIFTR_III(32,32,32, vlSelfRef.__PVT__src1, 
                                                          (0x0000001fU 
                                                           & vlSelfRef.__PVT__src2));
            }
        } else if (((((((((0x40005033U == (0xfe00707fU 
                                           & vlSelfRef.__PVT__inst)) 
                          | (0x00000067U == (0x0000707fU 
                                             & vlSelfRef.__PVT__inst))) 
                         | (0x0000006fU == (0x0000007fU 
                                            & vlSelfRef.__PVT__inst))) 
                        | (3U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                       | (0x00001003U == (0x0000707fU 
                                          & vlSelfRef.__PVT__inst))) 
                      | (0x00002003U == (0x0000707fU 
                                         & vlSelfRef.__PVT__inst))) 
                     | (0x00004003U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) 
                    | (0x00005003U == (0x0000707fU 
                                       & vlSelfRef.__PVT__inst)))) {
            if ((0x40005033U == (0xfe00707fU & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__src2);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = VL_SHIFTRS_III(32,32,32, vlSelfRef.__PVT__src1, 
                                                           (0x0000001fU 
                                                            & vlSelfRef.__PVT__src2));
            } else if ((0x00000067U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__jal_target = (0xfffffffeU 
                                               & (vlSelfRef.__PVT__src1 
                                                  + 
                                                  (((- (IData)(
                                                               (vlSelfRef.__PVT__inst 
                                                                >> 0x0000001fU))) 
                                                    << 0x0000000cU) 
                                                   | (vlSelfRef.__PVT__inst 
                                                      >> 0x00000014U))));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = ((IData)(4U) 
                                             + vlSelfRef.pc);
                vlSelfRef.__PVT__jal = 1U;
            } else if ((0x0000006fU == (0x0000007fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.__PVT__immj 
                                                                  >> 0x13U)))) 
                                                   << 0x00000015U) 
                                                  | (vlSelfRef.__PVT__immj 
                                                     << 1U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_wdata = ((IData)(4U) 
                                             + vlSelfRef.pc);
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__jal = 1U;
            } else if ((3U == (0x0000707fU & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.__PVT__mem_rdata 
                                                             >> 7U)))) 
                                              << 8U) 
                                             | (0x000000ffU 
                                                & vlSelfRef.__PVT__mem_rdata));
            } else if ((0x00001003U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.__PVT__mem_rdata 
                                                             >> 0x0fU)))) 
                                              << 0x00000010U) 
                                             | (0x0000ffffU 
                                                & vlSelfRef.__PVT__mem_rdata));
            } else if ((0x00002003U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = vlSelfRef.__PVT__mem_rdata;
            } else if ((0x00004003U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (0x000000ffU 
                                             & vlSelfRef.__PVT__mem_rdata);
            } else {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (0x0000ffffU 
                                             & vlSelfRef.__PVT__mem_rdata);
            }
        } else if (((((((((0x00000013U == (0x0000707fU 
                                           & vlSelfRef.__PVT__inst)) 
                          | (0x00002023U == (0x0000707fU 
                                             & vlSelfRef.__PVT__inst))) 
                         | (0x00001023U == (0x0000707fU 
                                            & vlSelfRef.__PVT__inst))) 
                        | (0x00000023U == (0x0000707fU 
                                           & vlSelfRef.__PVT__inst))) 
                       | (0x00000037U == (0x0000007fU 
                                          & vlSelfRef.__PVT__inst))) 
                      | (0x00000017U == (0x0000007fU 
                                         & vlSelfRef.__PVT__inst))) 
                     | (0x00002013U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) 
                    | (0x00003013U == (0x0000707fU 
                                       & vlSelfRef.__PVT__inst)))) {
            if ((0x00000013U == (0x0000707fU & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
            } else if ((0x00002023U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__imms) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000cU) 
                                                | (IData)(vlSelfRef.__PVT__imms)));
                vlSelfRef.__PVT__mem_wdata = vlSelfRef.__PVT__src2;
                vlSelfRef.__PVT__mem_wmask = 0x0fU;
                vlSelfRef.__PVT__mem_we = 1U;
            } else if ((0x00001023U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__imms) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000cU) 
                                                | (IData)(vlSelfRef.__PVT__imms)));
                vlSelfRef.__PVT__mem_wdata = vlSelfRef.__PVT__src2;
                vlSelfRef.__PVT__mem_wmask = 3U;
                vlSelfRef.__PVT__mem_we = 1U;
            } else if ((0x00000023U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelfRef.__PVT__imms) 
                                                                >> 0x0bU)))) 
                                                 << 0x0000000cU) 
                                                | (IData)(vlSelfRef.__PVT__imms)));
                vlSelfRef.__PVT__mem_wdata = vlSelfRef.__PVT__src2;
                vlSelfRef.__PVT__mem_wmask = 1U;
                vlSelfRef.__PVT__mem_we = 1U;
            } else if ((0x00000037U == (0x0000007fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (0xfffff000U 
                                             & vlSelfRef.__PVT__inst);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (0xfffff000U 
                                             & vlSelfRef.__PVT__inst);
            } else if ((0x00000017U == (0x0000007fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (0xfffff000U 
                                             & vlSelfRef.__PVT__inst);
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = ((0xfffff000U 
                                              & vlSelfRef.__PVT__inst) 
                                             + vlSelfRef.pc);
            } else if ((0x00002013U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = (VL_LTS_III(32, vlSelfRef.__PVT__src1, 
                                                        (((- (IData)(
                                                                     (vlSelfRef.__PVT__inst 
                                                                      >> 0x0000001fU))) 
                                                          << 0x0000000cU) 
                                                         | (vlSelfRef.__PVT__inst 
                                                            >> 0x00000014U)))
                                              ? 1U : 0U);
            } else {
                vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                             + (((- (IData)(
                                                            (vlSelfRef.__PVT__inst 
                                                             >> 0x0000001fU))) 
                                                 << 0x0000000cU) 
                                                | (vlSelfRef.__PVT__inst 
                                                   >> 0x00000014U)));
                vlSelfRef.__PVT__rf_wen = 1U;
                vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                             & (vlSelfRef.__PVT__inst 
                                                >> 7U));
                vlSelfRef.__PVT__rf_wdata = ((vlSelfRef.__PVT__src1 
                                              < (vlSelfRef.__PVT__inst 
                                                 >> 0x00000014U))
                                              ? 1U : 0U);
            }
        } else if ((0x00004013U == (0x0000707fU & vlSelfRef.__PVT__inst))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                         ^ (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
        } else if ((0x00006013U == (0x0000707fU & vlSelfRef.__PVT__inst))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                         | (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
        } else if ((0x00007013U == (0x0000707fU & vlSelfRef.__PVT__inst))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = (vlSelfRef.__PVT__src1 
                                         & (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
        } else if ((0x40005013U == (0xfe00707fU & vlSelfRef.__PVT__inst))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = VL_SHIFTRS_III(32,32,12, vlSelfRef.__PVT__src1, 
                                                       (0x001fU 
                                                        & (vlSelfRef.__PVT__inst 
                                                           >> 0x00000014U)));
        } else if ((0x00001013U == (0xfe00707fU & vlSelfRef.__PVT__inst))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = VL_SHIFTL_III(32,32,12, vlSelfRef.__PVT__src1, 
                                                      (0x001fU 
                                                       & (vlSelfRef.__PVT__inst 
                                                          >> 0x00000014U)));
        } else if (VL_LIKELY(((0x00005013U == (0xfe00707fU 
                                               & vlSelfRef.__PVT__inst))))) {
            vlSelfRef.__PVT__mem_addr = (vlSelfRef.__PVT__src1 
                                         + (((- (IData)(
                                                        (vlSelfRef.__PVT__inst 
                                                         >> 0x0000001fU))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.__PVT__inst 
                                               >> 0x00000014U)));
            vlSelfRef.__PVT__rf_wen = 1U;
            vlSelfRef.__PVT__rf_waddr = (0x0000001fU 
                                         & (vlSelfRef.__PVT__inst 
                                            >> 7U));
            vlSelfRef.__PVT__rf_wdata = VL_SHIFTR_III(32,32,12, vlSelfRef.__PVT__src1, 
                                                      (0x001fU 
                                                       & (vlSelfRef.__PVT__inst 
                                                          >> 0x00000014U)));
        } else {
            VL_WRITEF_NX("UNKNOWN INST: pc=%h inst=%h\n",2
                         , '#',32,vlSelfRef.pc, '#',32,vlSelfRef.__PVT__inst);
            vlSelfRef.__PVT__mem_addr = 0U;
            Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top(
                                                                                (vlSymsp->__Vscopep_top__my_EXU__my_alu), 
                                                                                "vsrc/EXU.v", 0x00000178U, vlSelfRef.halt_code);
        }
    }
    vlSelfRef.pc = vlSelfRef.pc_;
    vlSelfRef.halt_code = __Vdly__halt_code;
    if (__VdlySet__my_MBU__DOT__my_reg__DOT__rf__v0) {
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[0U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[1U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[2U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[3U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[4U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[5U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[6U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[7U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[8U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[9U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[10U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[11U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[12U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[13U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[14U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[15U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[16U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[17U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[18U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[19U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[20U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[21U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[22U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[23U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[24U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[25U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[26U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[27U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[28U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[29U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[30U] = 0U;
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[31U] = 0U;
    }
    if (__VdlySet__my_MBU__DOT__my_reg__DOT__rf__v32) {
        vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[__VdlyDim0__my_MBU__DOT__my_reg__DOT__rf__v32] 
            = __VdlyVal__my_MBU__DOT__my_reg__DOT__rf__v32;
    }
    Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(
                                                           (vlSymsp->__Vscopep_top__my_IFU), 
                                                           "vsrc/IFU.v", 0x0000000bU, vlSelfRef.pc_, vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__4__Vfuncout);
    vlSelfRef.__PVT__inst = vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__4__Vfuncout;
    Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(
                                                           (vlSymsp->__Vscopep_top__my_LSU), 
                                                           "vsrc/LSU.v", 0x0000000fU, vlSelfRef.__PVT__mem_addr, vlSelfRef.__Vfunc_my_LSU__DOT__pmem_read__2__Vfuncout);
    vlSelfRef.__PVT__mem_rdata = vlSelfRef.__Vfunc_my_LSU__DOT__pmem_read__2__Vfuncout;
    vlSelfRef.__PVT__imms = ((0x00000fe0U & (vlSelfRef.__PVT__inst 
                                             >> 0x00000014U)) 
                             | (0x0000001fU & (vlSelfRef.__PVT__inst 
                                               >> 7U)));
    vlSelfRef.__PVT__immb = ((((2U & (vlSelfRef.__PVT__inst 
                                      >> 0x0000001eU)) 
                               | (1U & (vlSelfRef.__PVT__inst 
                                        >> 7U))) << 0x0000000aU) 
                             | ((0x000003f0U & (vlSelfRef.__PVT__inst 
                                                >> 0x00000015U)) 
                                | (0x0000000fU & (vlSelfRef.__PVT__inst 
                                                  >> 8U))));
    vlSelfRef.__PVT__immj = ((0x00080000U & (vlSelfRef.__PVT__inst 
                                             >> 0x0000000cU)) 
                             | ((0x0007f800U & (vlSelfRef.__PVT__inst 
                                                >> 1U)) 
                                | ((0x00000400U & (vlSelfRef.__PVT__inst 
                                                   >> 0x0000000aU)) 
                                   | (0x000003ffU & 
                                      (vlSelfRef.__PVT__inst 
                                       >> 0x00000015U)))));
    vlSelfRef.__PVT__src1 = (vlSelfRef.my_MBU__DOT__my_reg__DOT__rf
                             [(0x0000001fU & (vlSelfRef.__PVT__inst 
                                              >> 0x0000000fU))] 
                             & (- (IData)((0U != (0x0000001fU 
                                                  & (vlSelfRef.__PVT__inst 
                                                     >> 0x0000000fU))))));
    vlSelfRef.__PVT__src2 = (vlSelfRef.my_MBU__DOT__my_reg__DOT__rf
                             [(0x0000001fU & (vlSelfRef.__PVT__inst 
                                              >> 0x00000014U))] 
                             & (- (IData)((0U != (0x0000001fU 
                                                  & (vlSelfRef.__PVT__inst 
                                                     >> 0x00000014U))))));
}
