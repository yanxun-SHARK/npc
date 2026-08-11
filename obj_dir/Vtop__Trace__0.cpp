// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__top.__PVT__inst),32);
        bufp->chgCData(oldp+1,((0x0000001fU & (vlSymsp->TOP__top.__PVT__inst 
                                               >> 0x0000000fU))),5);
        bufp->chgCData(oldp+2,((0x0000001fU & (vlSymsp->TOP__top.__PVT__inst 
                                               >> 0x00000014U))),5);
        bufp->chgCData(oldp+3,((0x0000001fU & (vlSymsp->TOP__top.__PVT__inst 
                                               >> 7U))),5);
        bufp->chgSData(oldp+4,((vlSymsp->TOP__top.__PVT__inst 
                                >> 0x00000014U)),12);
        bufp->chgSData(oldp+5,(vlSymsp->TOP__top.__PVT__imms),12);
        bufp->chgSData(oldp+6,(vlSymsp->TOP__top.__PVT__immb),12);
        bufp->chgIData(oldp+7,((vlSymsp->TOP__top.__PVT__inst 
                                >> 0x0000000cU)),20);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__top.__PVT__immj),20);
        bufp->chgIData(oldp+9,(vlSymsp->TOP__top.__PVT__src1),32);
        bufp->chgIData(oldp+10,(vlSymsp->TOP__top.__PVT__src2),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[2U] 
                       | vlSelfRef.__Vm_traceActivity[3U]) 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgBit(oldp+11,(vlSymsp->TOP__top.__PVT__mem_we));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__top.__PVT__rf_wen));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__top.__PVT__jal));
        bufp->chgCData(oldp+14,(vlSymsp->TOP__top.__PVT__rf_waddr),5);
        bufp->chgIData(oldp+15,(vlSymsp->TOP__top.__PVT__mem_addr),32);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__top.__PVT__mem_wdata),32);
        bufp->chgCData(oldp+17,(vlSymsp->TOP__top.__PVT__mem_wmask),4);
        bufp->chgIData(oldp+18,(vlSymsp->TOP__top.__PVT__rf_wdata),32);
        bufp->chgIData(oldp+19,(vlSymsp->TOP__top.__PVT__jal_target),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+20,(vlSymsp->TOP__top.__PVT__my_MBU__DOT__my_pc__DOT__pc),32);
        bufp->chgIData(oldp+21,(vlSymsp->TOP__top.__PVT__my_MBU__DOT__my_pc__DOT__pc_4),32);
        bufp->chgIData(oldp+22,(vlSymsp->TOP__top.__PVT__my_MBU__DOT__my_reg__DOT__i),32);
    }
    bufp->chgBit(oldp+23,(vlSelfRef.clk));
    bufp->chgBit(oldp+24,(vlSelfRef.rst));
    bufp->chgBit(oldp+25,(vlSelfRef.ebreak));
    bufp->chgIData(oldp+26,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+27,(vlSelfRef.halt_code),32);
    bufp->chgBit(oldp+28,(vlSymsp->TOP__top.ebreak));
    bufp->chgIData(oldp+29,(vlSymsp->TOP__top.pc),32);
    bufp->chgIData(oldp+30,(vlSymsp->TOP__top.halt_code),32);
    bufp->chgIData(oldp+31,(vlSymsp->TOP__top.pc_),32);
    bufp->chgIData(oldp+32,(vlSymsp->TOP__top.__PVT__mem_rdata),32);
    bufp->chgIData(oldp+33,(vlSymsp->TOP__top.my_MBU__DOT__my_reg__DOT__rf[10U]),32);
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 34, vlSymsp->TOP__top.my_MBU__DOT__my_reg__DOT__rf);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[0]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
