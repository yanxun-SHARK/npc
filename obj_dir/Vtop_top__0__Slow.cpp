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

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_top____Vdpiimwrap_my_LSU__DOT__pmem_read_TOP__top(
                                                           (vlSymsp->__Vscopep_top__my_LSU), 
                                                           "vsrc/LSU.v", 0x0000000fU, vlSelfRef.__PVT__mem_addr, vlSelfRef.__Vfunc_my_LSU__DOT__pmem_read__2__Vfuncout);
    vlSelfRef.__PVT__mem_rdata = vlSelfRef.__Vfunc_my_LSU__DOT__pmem_read__2__Vfuncout;
    vlSelfRef.pc_ = vlSelfRef.__PVT__my_MBU__DOT__my_pc__DOT__pc;
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
    vlSelf->__Vfunc_my_LSU__DOT__pmem_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_my_IFU__DOT__pmem_read__4__Vfuncout = 0;
}
