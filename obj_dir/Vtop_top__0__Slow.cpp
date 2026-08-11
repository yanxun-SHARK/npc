// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_top___eval_initial__TOP__top(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___eval_initial__TOP__top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
    vlSymsp->_traceDumpOpen();
}

void Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, IData/*31:0*/ halt_code);

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc_ = vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc;
    vlSelfRef.pc = vlSelfRef.pc_;
    Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(
                                                           (vlSymsp->__Vscopep_top__my_IFU), 
                                                           "vsrc/IFU.v", 0x0000000bU, vlSelfRef.pc_, vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__3__Vfuncout);
    vlSelfRef.__PVT__inst = vlSelfRef.__Vfunc_my_IFU__DOT__pmem_read__3__Vfuncout;
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
        vlSelfRef.__PVT__jal_target = 0U;
        vlSelfRef.halt_code = 0U;
    } else {
        vlSelfRef.__PVT__mem_we = 0U;
        vlSelfRef.__PVT__mem_wmask = 0U;
        vlSelfRef.__PVT__rf_wen = 0U;
        vlSelfRef.__PVT__jal = 0U;
        vlSelfRef.ebreak = 0U;
        vlSelfRef.__PVT__jal_target = 0U;
        vlSelfRef.halt_code = 0U;
        if (((((((((0x00100073U == vlSelfRef.__PVT__inst) 
                   | (0x00000063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                  | (0x00001063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                 | (0x00005063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
                | (0x00004063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
               | (0x00007063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
              | (0x00006063U == (0x0000707fU & vlSelfRef.__PVT__inst))) 
             | (0x00000033U == (0xfe00707fU & vlSelfRef.__PVT__inst)))) {
            if ((0x00100073U == vlSelfRef.__PVT__inst)) {
                vlSelfRef.ebreak = 1U;
                vlSelfRef.halt_code = vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[10U];
                Vtop_top____Vdpiimwrap_my_EXU__DOT__my_alu__DOT__ebreak_notice_TOP__top(
                                                                                (vlSymsp->__Vscopep_top__my_EXU__my_alu), 
                                                                                "vsrc/EXU.v", 0x000000a0U, vlSelfRef.my_MBU__DOT__my_reg__DOT__rf[10U]);
            } else if ((0x00000063U == (0x0000707fU 
                                        & vlSelfRef.__PVT__inst))) {
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__jal_target = (vlSelfRef.pc 
                                               + ((
                                                   (- (IData)(
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
                vlSelfRef.__PVT__rf_wdata = ((2U & vlSelfRef.__PVT__mem_addr)
                                              ? ((1U 
                                                  & vlSelfRef.__PVT__mem_addr)
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelfRef.__PVT__mem_rdata 
                                                               >> 0x1fU))) 
                                                   << 8U) 
                                                  | (vlSelfRef.__PVT__mem_rdata 
                                                     >> 0x18U))
                                                  : 
                                                 (((- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.__PVT__mem_rdata 
                                                                  >> 0x17U)))) 
                                                   << 8U) 
                                                  | (0x000000ffU 
                                                     & (vlSelfRef.__PVT__mem_rdata 
                                                        >> 0x10U))))
                                              : ((1U 
                                                  & vlSelfRef.__PVT__mem_addr)
                                                  ? 
                                                 (((- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.__PVT__mem_rdata 
                                                                  >> 0x0fU)))) 
                                                   << 8U) 
                                                  | (0x000000ffU 
                                                     & (vlSelfRef.__PVT__mem_rdata 
                                                        >> 8U)))
                                                  : 
                                                 (((- (IData)(
                                                              (1U 
                                                               & (vlSelfRef.__PVT__mem_rdata 
                                                                  >> 7U)))) 
                                                   << 8U) 
                                                  | (0x000000ffU 
                                                     & vlSelfRef.__PVT__mem_rdata))));
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
                vlSelfRef.__PVT__rf_wdata = ((2U & vlSelfRef.__PVT__mem_addr)
                                              ? (((- (IData)(
                                                             (vlSelfRef.__PVT__mem_rdata 
                                                              >> 0x1fU))) 
                                                  << 0x00000010U) 
                                                 | (vlSelfRef.__PVT__mem_rdata 
                                                    >> 0x10U))
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.__PVT__mem_rdata 
                                                                 >> 0x0fU)))) 
                                                  << 0x00000010U) 
                                                 | (0x0000ffffU 
                                                    & vlSelfRef.__PVT__mem_rdata)));
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
                vlSelfRef.__PVT__rf_wdata = ((2U & vlSelfRef.__PVT__mem_addr)
                                              ? ((1U 
                                                  & vlSelfRef.__PVT__mem_addr)
                                                  ? 
                                                 (vlSelfRef.__PVT__mem_rdata 
                                                  >> 0x18U)
                                                  : 
                                                 (0x000000ffU 
                                                  & (vlSelfRef.__PVT__mem_rdata 
                                                     >> 0x10U)))
                                              : ((1U 
                                                  & vlSelfRef.__PVT__mem_addr)
                                                  ? 
                                                 (0x000000ffU 
                                                  & (vlSelfRef.__PVT__mem_rdata 
                                                     >> 8U))
                                                  : 
                                                 (0x000000ffU 
                                                  & vlSelfRef.__PVT__mem_rdata)));
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
                vlSelfRef.__PVT__rf_wdata = ((2U & vlSelfRef.__PVT__mem_addr)
                                              ? (vlSelfRef.__PVT__mem_rdata 
                                                 >> 0x10U)
                                              : (0x0000ffffU 
                                                 & vlSelfRef.__PVT__mem_rdata));
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
                if ((2U & vlSelfRef.__PVT__mem_addr)) {
                    vlSelfRef.__PVT__mem_wdata = (vlSelfRef.__PVT__src2 
                                                  << 0x00000010U);
                    vlSelfRef.__PVT__mem_wmask = 0x0cU;
                } else {
                    vlSelfRef.__PVT__mem_wdata = vlSelfRef.__PVT__src2;
                    vlSelfRef.__PVT__mem_wmask = 3U;
                }
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
                if ((2U & vlSelfRef.__PVT__mem_addr)) {
                    if ((1U & vlSelfRef.__PVT__mem_addr)) {
                        vlSelfRef.__PVT__mem_wdata 
                            = (vlSelfRef.__PVT__src2 
                               << 0x00000018U);
                        vlSelfRef.__PVT__mem_wmask = 8U;
                    } else {
                        vlSelfRef.__PVT__mem_wdata 
                            = (vlSelfRef.__PVT__src2 
                               << 0x00000010U);
                        vlSelfRef.__PVT__mem_wmask = 4U;
                    }
                } else if ((1U & vlSelfRef.__PVT__mem_addr)) {
                    vlSelfRef.__PVT__mem_wdata = (vlSelfRef.__PVT__src2 
                                                  << 8U);
                    vlSelfRef.__PVT__mem_wmask = 2U;
                } else {
                    vlSelfRef.__PVT__mem_wdata = vlSelfRef.__PVT__src2;
                    vlSelfRef.__PVT__mem_wmask = 1U;
                }
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
                                              < (((- (IData)(
                                                             (vlSelfRef.__PVT__inst 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | (vlSelfRef.__PVT__inst 
                                                    >> 0x00000014U)))
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
            vlSelfRef.__PVT__mem_addr = 0U;
            VL_WRITEF_NX("FATAL: UNKNOWN INST at pc=%h inst=%h\n[%0t] %%Fatal: EXU.v:418: Assertion failed in %m: Halting on unknown instruction\n",5, 'M',vlSymsp->name(),"top.my_EXU.my_alu", 'T',-12
                         , '#',32,vlSelfRef.pc, '#',32,vlSelfRef.__PVT__inst
                         , '#',64,VL_TIME_UNITED_Q(1));
            VL_STOP_MT("vsrc/EXU.v", 418, "", false);
        }
    }
}

VL_ATTR_COLD void Vtop_top___ctor_var_reset(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2715241313644402257ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->halt_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 737346242420507211ull);
    vlSelf->top_inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16303268308794302281ull);
    vlSelf->__PVT__mem_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15973559030946811212ull);
    vlSelf->__PVT__rf_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5575201621105883436ull);
    vlSelf->__PVT__jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10255714831327549626ull);
    vlSelf->__PVT__rf_waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12713048650760543444ull);
    vlSelf->__PVT__imms = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14806613354296231200ull);
    vlSelf->__PVT__immb = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14530693561246076256ull);
    vlSelf->__PVT__immj = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 17209886587399115260ull);
    vlSelf->pc_ = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9854086829425932910ull);
    vlSelf->__PVT__inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9812503827101699671ull);
    vlSelf->__PVT__src1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11501994169717294192ull);
    vlSelf->__PVT__src2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3892772694212331581ull);
    vlSelf->__PVT__mem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 326597072690670135ull);
    vlSelf->__PVT__mem_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5431754401481461448ull);
    vlSelf->__PVT__mem_wmask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3532114055872623927ull);
    vlSelf->__PVT__mem_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9659133473039683418ull);
    vlSelf->__PVT__rf_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12502994072091849792ull);
    vlSelf->__PVT__jal_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5012368509880549853ull);
    vlSelf->__PVT__my_MBU__DOT__my_pc__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16563017890665908429ull);
    vlSelf->__PVT__my_MBU__DOT__my_pc__DOT__pc_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5617482701627667033ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->my_MBU__DOT__my_reg__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17552125731258403864ull);
    }
    vlSelf->__PVT__my_MBU__DOT__my_reg__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11435095448336781970ull);
    vlSelf->__Vfunc_my_IFU__DOT__pmem_read__3__Vfuncout = 0;
}
