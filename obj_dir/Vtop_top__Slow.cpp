// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_top___ctor_var_reset(Vtop_top* vlSelf);

Vtop_top::Vtop_top() = default;
Vtop_top::~Vtop_top() = default;

void Vtop_top::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_top___ctor_var_reset(this);
}

void Vtop_top::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_top::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
