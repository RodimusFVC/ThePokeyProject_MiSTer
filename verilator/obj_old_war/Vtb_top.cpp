// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top.h"
#include "Vtb_top__Syms.h"

//==========

VerilatedContext* Vtb_top::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtb_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_top::eval\n"); );
    Vtb_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/Work/Projects/ThePokeyProject_MiSTer/verilator/tb_top.sv", 6, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtb_top::_eval_initial_loop(Vtb_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/Work/Projects/ThePokeyProject_MiSTer/verilator/tb_top.sv", 6, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtb_top::_sequent__TOP__3(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_sequent__TOP__3\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<11>/*351:0*/ __Vtemp2;
    VlWide<11>/*351:0*/ __Vtemp3;
    // Body
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__irq_n_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__irq_n_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__irq_n_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan1_output_del_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__chan1_output_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan1_output_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan0_output_del_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__chan0_output_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan0_output_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__highpass0_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__highpass0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__highpass0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__highpass1_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__highpass1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__highpass1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_holding_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_holding_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_holding_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg = 0U;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serin_shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serin_shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg = 0xaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg = 0xaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc2_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audc2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audc2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc3_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audc3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audc3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__irqen_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__irqen_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__irqen_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc0_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audc0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audc0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc1_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audc1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audc1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot0_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot1_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot2_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot3_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot4_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot4_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot4_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot5_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot5_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot5_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot6_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot6_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot6_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot7_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot7_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot7_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serin_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serin_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf3_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audf3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audf3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf0_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audf0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audf0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf1_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audf1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audf1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf2_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audf2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audf2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_active_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_active_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_active_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__allpot_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__allpot_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__allpot_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serial_out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serial_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serial_out_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__noise_large_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__noise_5_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__noise_4_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg = 0xaaaaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__irqst_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__irqst_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_next;
        }
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_reset_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_clock_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan3_output_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan3_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan2_output_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan2_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan1_output_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan1_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__chan0_output_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__chan0_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__clock_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__audctl_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__audctl_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__audctl_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg 
                = (1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_reg) 
                          & (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_reg)) 
                         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_reg)));
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__skctl_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__skctl_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__skctl_reg = 0U;
    }
    vlTOPp->irq_n = ((2U & (IData)(vlTOPp->irq_n)) 
                     | (IData)(vlTOPp->tb_top__DOT__old0__DOT__irq_n_reg));
    vlTOPp->out_raw0 = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_reg) 
                         << 0xcU) | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_reg) 
                                      << 8U) | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_reg) 
                                                 << 4U) 
                                                | (IData)(vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_reg))));
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg;
    vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_next = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__chan0_output_del_reg) 
                ^ (IData)(vlTOPp->tb_top__DOT__old0__DOT__highpass0_reg)) 
               | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc0_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_0_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc0_reg));
    }
    vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_next = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__chan1_output_del_reg) 
                ^ (IData)(vlTOPp->tb_top__DOT__old0__DOT__highpass1_reg)) 
               | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc1_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_1_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc1_reg));
    }
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
    vlTOPp->tb_top__DOT__old0__DOT__noise_large_next 
        = ((6U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg) 
                  << 1U)) | (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg));
    vlTOPp->tb_top__DOT__old0__DOT__noise_5_next = 
        ((6U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg) 
                << 1U)) | (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old0__DOT__noise_4_next = 
        ((6U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg) 
                << 1U)) | (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_next 
        = (1U & (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                 >> 9U));
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__feedback 
        = (1U & (~ ((vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                     >> 0xdU) ^ (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                 >> 8U))));
    vlTOPp->tb_top__DOT__old0__DOT__irq_n_next = 0U;
    if ((0xffU == ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_reg) 
                   | (8U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                                >> 3U)) << 3U))))) {
        vlTOPp->tb_top__DOT__old0__DOT__irq_n_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_op_needed_interrupt = 0U;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old0__DOT__serial_op_needed_interrupt = 1U;
            }
        }
    }
    vlTOPp->pot_count0 = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
    vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_next = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__chan3_output_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc3_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_3_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc3_reg));
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_next = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__chan2_output_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc2_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__volume_channel_2_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc2_reg));
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__chan1_output_del_next 
        = vlTOPp->tb_top__DOT__old0__DOT__chan1_output_reg;
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__chan0_output_del_next 
        = vlTOPp->tb_top__DOT__old0__DOT__chan0_output_reg;
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__clock_reg = 1U;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__clock_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf1_reload = 
        (1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg)));
    if (vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n) {
        if ((1U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg 
                = vlTOPp->tb_top__DOT__old0__DOT__serin_clock_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_next = 0U;
    if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next 
        = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                 >> 7U));
    vlTOPp->tb_top__DOT__old0__DOT__highpass0_next 
        = vlTOPp->tb_top__DOT__old0__DOT__highpass0_reg;
    if ((4U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__highpass0_next 
                = vlTOPp->tb_top__DOT__old0__DOT__chan0_output_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__highpass0_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__highpass1_next 
        = vlTOPp->tb_top__DOT__old0__DOT__highpass1_reg;
    if ((2U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__highpass1_next 
                = vlTOPp->tb_top__DOT__old0__DOT__chan1_output_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__highpass1_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf0_reload = 
        (1U & (((((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                      >> 4U)) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg)) 
                 | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                     >> 4U) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg))) 
                | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_next = 0U;
    if ((0x71U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf0_enable = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf0_enable 
            = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf0_enable = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf2_enable = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf2_enable 
            = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf2_enable = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf1_enable = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf1_enable 
            = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf1_enable 
            = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg));
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf3_enable = vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf3_enable 
            = vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((8U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__audf3_enable 
            = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg));
    }
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
            >> 1U))) {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next 
            = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)));
    }
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
            >> 1U))) {
        if ((0U == (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)))) {
            if ((3U != (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                              >> 4U)))) {
                if ((1U == (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                                  >> 4U)))) {
                    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next = 0U;
                }
            }
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot7_next = vlTOPp->tb_top__DOT__old0__DOT__pot7_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot7_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot6_next = vlTOPp->tb_top__DOT__old0__DOT__pot6_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot6_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot5_next = vlTOPp->tb_top__DOT__old0__DOT__pot5_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot5_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot4_next = vlTOPp->tb_top__DOT__old0__DOT__pot4_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot4_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot3_next = vlTOPp->tb_top__DOT__old0__DOT__pot3_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot3_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot2_next = vlTOPp->tb_top__DOT__old0__DOT__pot2_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot2_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot1_next = vlTOPp->tb_top__DOT__old0__DOT__pot1_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot1_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot0_next = vlTOPp->tb_top__DOT__old0__DOT__pot0_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot0_next 
                = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next = 0U;
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
            >> 1U))) {
        if ((0U == (0xfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)))) {
            if ((3U == (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                              >> 4U)))) {
                vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next = 0U;
            }
        }
    }
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg)))) {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next = 1U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_out_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serial_out_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__serial_out_next 
            = (1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_shift_reg) 
                      >> 1U) | (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_active_reg))));
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__serial_out_next 
                = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg)));
        }
    }
    if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__serial_out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg;
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next 
        = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg;
    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                == (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg)) 
               | (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))))) {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key = 1U;
    }
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
            >> 1U))) {
        vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 0U;
        if ((2U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
            if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
                vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 1U;
                if (vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 0U;
                    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 0U;
                }
            } else {
                vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 1U;
                if (vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                    vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 3U;
                }
            }
        } else if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
            if (vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 0U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__twotone_reset = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                  & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serial_out_reg))))) {
        vlTOPp->tb_top__DOT__old0__DOT__twotone_reset 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                     >> 3U));
    }
    vlTOPp->tb_top__DOT__old0__DOT__async_serial_reset = 0U;
    if (((((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
           >> 4U) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg)) 
         & (9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
        vlTOPp->tb_top__DOT__old0__DOT__async_serial_reset = 1U;
    }
    VL_EXTEND_WI(342,16, __Vtemp2, (IData)(vlTOPp->out_raw0));
    VL_SHIFTL_WWI(342,342,32, __Vtemp3, __Vtemp2, 3U);
    vlTOPp->dbg0[0U] = (__Vconst1[0U] & __Vtemp3[0U]);
    vlTOPp->dbg0[1U] = (__Vconst1[1U] & __Vtemp3[1U]);
    vlTOPp->dbg0[2U] = (__Vconst1[2U] & __Vtemp3[2U]);
    vlTOPp->dbg0[3U] = (__Vconst1[3U] & __Vtemp3[3U]);
    vlTOPp->dbg0[4U] = (__Vconst1[4U] & __Vtemp3[4U]);
    vlTOPp->dbg0[5U] = (__Vconst1[5U] & __Vtemp3[5U]);
    vlTOPp->dbg0[6U] = (__Vconst1[6U] & __Vtemp3[6U]);
    vlTOPp->dbg0[7U] = (__Vconst1[7U] & __Vtemp3[7U]);
    vlTOPp->dbg0[8U] = (__Vconst1[8U] & __Vtemp3[8U]);
    vlTOPp->dbg0[9U] = (__Vconst1[9U] & __Vtemp3[9U]);
    vlTOPp->dbg0[0xaU] = (__Vconst1[0xaU] & __Vtemp3[0xaU]);
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__l;
    vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf0_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__Vfuncout));
    vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__l;
    vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf2_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__Vfuncout));
    vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__l;
    vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf1_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__Vfuncout));
    vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__l;
    vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf3_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__Vfuncout));
    vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow_command));
    vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_next = 0U;
    vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_next 
        = ((((IData)(vlTOPp->tb_top__DOT__old0__DOT__twotone_reset) 
             | (IData)(vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_reg)) 
            << 1U) | (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg) 
                            >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__audf3_reload = 
        (1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old0__DOT__async_serial_reset)));
    vlTOPp->tb_top__DOT__old0__DOT__audf2_reload = 
        (1U & (((((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                      >> 3U)) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg)) 
                 | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                     >> 3U) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) 
                | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old0__DOT__async_serial_reset)));
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc3_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                     & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg) 
                        >> 2U)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__audclk) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc3_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc3_reg))
                          ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg) 
                             >> 2U) : ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg) 
                                       >> 2U))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc2_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg) 
                     & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg) 
                        >> 1U)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__audclk) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc2_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc2_reg))
                          ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg) 
                             >> 1U) : ((IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg) 
                                       >> 1U))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc1_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                     & (IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_5_reg)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__audclk) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc1_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc1_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_4_reg)
                          : (IData)(vlTOPp->tb_top__DOT__old0__DOT__noise_large_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audc0_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                     & (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__audclk) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc0_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__audc0_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg)
                          : (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_next = 0U;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg)
                      : (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)));
        vlTOPp->tb_top__DOT__old0__DOT__serin_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_reg)))));
    } else {
        vlTOPp->tb_top__DOT__old0__DOT__serout_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                          ? ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_reg))
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_reg)))));
        vlTOPp->tb_top__DOT__old0__DOT__serin_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old0__DOT__clock_reg)))));
    }
    vlTOPp->tb_top__DOT__old0__DOT__serin_next = vlTOPp->tb_top__DOT__old0__DOT__serin_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg))) {
                vlTOPp->tb_top__DOT__old0__DOT__serin_next 
                    = (0xffU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_shift_reg) 
                                >> 2U));
            }
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_ip_ready_interrupt = 0U;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg))) {
                vlTOPp->tb_top__DOT__old0__DOT__serial_ip_ready_interrupt = 1U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old0__DOT__audf0_reload) {
        vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old0__DOT__audf1_reload) {
        vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old0__DOT__audf3_reload) {
        vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old0__DOT__audf2_reload) {
        vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__irqst_next = (0xffU 
                                                  & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_reg) 
                                                     | (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg))));
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xfeU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xfdU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (2U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                            >> 1U)) << 1U)));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xfbU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (4U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                            >> 2U)) << 2U)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xbfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (0x40U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                               >> 6U)) << 6U)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0x7fU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (0x80U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                               >> 7U)) << 7U)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_ip_ready_interrupt) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xdfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (0x20U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                               >> 5U)) << 5U)));
    }
    vlTOPp->tb_top__DOT__old0__DOT__irqst_next = ((0xf7U 
                                                   & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
                                                  | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_active_reg) 
                                                     << 3U));
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_op_needed_interrupt) {
        vlTOPp->tb_top__DOT__old0__DOT__irqst_next 
            = ((0xefU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_next)) 
               | (0x10U & ((~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqen_reg) 
                               >> 4U)) << 4U)));
    }
}

VL_INLINE_OPT void Vtb_top::_sequent__TOP__4(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_sequent__TOP__4\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<11>/*351:0*/ __Vtemp5;
    VlWide<11>/*351:0*/ __Vtemp6;
    // Body
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__irq_n_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__irq_n_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__irq_n_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan1_output_del_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__chan1_output_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan1_output_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan0_output_del_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__chan0_output_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan0_output_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__highpass0_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__highpass0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__highpass0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__highpass1_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__highpass1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__highpass1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_holding_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_holding_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_holding_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg = 0U;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serin_shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serin_shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg = 0xaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg = 0xaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc2_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audc2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audc2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc3_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audc3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audc3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__irqen_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__irqen_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__irqen_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc0_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audc0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audc0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc1_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audc1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audc1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot0_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot1_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot2_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot3_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot4_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot4_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot4_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot5_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot5_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot5_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot6_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot6_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot6_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot7_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot7_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot7_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serin_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serin_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf3_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audf3_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audf3_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf0_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audf0_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audf0_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf1_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audf1_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audf1_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf2_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audf2_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audf2_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_active_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_active_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_active_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__allpot_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__allpot_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__allpot_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serial_out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serial_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serial_out_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__noise_large_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__noise_5_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__noise_4_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg = 0xaaaaU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__irqst_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__irqst_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_reg = 0xffU;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_next;
        }
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_reset_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg = 1U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_clock_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan3_output_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan3_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan2_output_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan2_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan1_output_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan1_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__chan0_output_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__chan0_output_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__clock_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__audctl_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__audctl_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__audctl_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg 
                = (1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_reg) 
                          & (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_reg)) 
                         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_reg)));
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__skctl_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__skctl_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__skctl_reg = 0U;
    }
    vlTOPp->irq_n = ((1U & (IData)(vlTOPp->irq_n)) 
                     | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irq_n_reg) 
                        << 1U));
    vlTOPp->out_raw1 = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_reg) 
                         << 0xcU) | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_reg) 
                                      << 8U) | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_reg) 
                                                 << 4U) 
                                                | (IData)(vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_reg))));
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg;
    vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_next = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__chan0_output_del_reg) 
                ^ (IData)(vlTOPp->tb_top__DOT__old1__DOT__highpass0_reg)) 
               | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc0_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_0_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc0_reg));
    }
    vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_next = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__chan1_output_del_reg) 
                ^ (IData)(vlTOPp->tb_top__DOT__old1__DOT__highpass1_reg)) 
               | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc1_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_1_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc1_reg));
    }
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
    vlTOPp->tb_top__DOT__old1__DOT__noise_large_next 
        = ((6U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg) 
                  << 1U)) | (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg));
    vlTOPp->tb_top__DOT__old1__DOT__noise_5_next = 
        ((6U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg) 
                << 1U)) | (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old1__DOT__noise_4_next = 
        ((6U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg) 
                << 1U)) | (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_next 
        = (1U & (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                 >> 9U));
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__feedback 
        = (1U & (~ ((vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                     >> 0xdU) ^ (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                 >> 8U))));
    vlTOPp->tb_top__DOT__old1__DOT__irq_n_next = 0U;
    if ((0xffU == ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_reg) 
                   | (8U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                                >> 3U)) << 3U))))) {
        vlTOPp->tb_top__DOT__old1__DOT__irq_n_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_op_needed_interrupt = 0U;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old1__DOT__serial_op_needed_interrupt = 1U;
            }
        }
    }
    vlTOPp->pot_count1 = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
    vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_next = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__chan3_output_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc3_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_3_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc3_reg));
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_next = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__chan2_output_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc2_reg) 
                  >> 4U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__volume_channel_2_next 
            = (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc2_reg));
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__chan1_output_del_next 
        = vlTOPp->tb_top__DOT__old1__DOT__chan1_output_reg;
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__chan0_output_del_next 
        = vlTOPp->tb_top__DOT__old1__DOT__chan0_output_reg;
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg = 0U;
    }
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__clock_reg = 1U;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__clock_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf1_reload = 
        (1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg)));
    if (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n) {
        if ((2U & (IData)(vlTOPp->ce))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg 
                = vlTOPp->tb_top__DOT__old1__DOT__serin_clock_next;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_next = 0U;
    if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next 
        = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                 >> 7U));
    vlTOPp->tb_top__DOT__old1__DOT__highpass0_next 
        = vlTOPp->tb_top__DOT__old1__DOT__highpass0_reg;
    if ((4U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__highpass0_next 
                = vlTOPp->tb_top__DOT__old1__DOT__chan0_output_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__highpass0_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__highpass1_next 
        = vlTOPp->tb_top__DOT__old1__DOT__highpass1_reg;
    if ((2U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__highpass1_next 
                = vlTOPp->tb_top__DOT__old1__DOT__chan1_output_reg;
        }
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__highpass1_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf0_reload = 
        (1U & (((((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                      >> 4U)) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg)) 
                 | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                     >> 4U) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg))) 
                | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg)));
    vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_next = 0U;
    if ((0x71U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf0_enable = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf0_enable 
            = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf0_enable = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf2_enable = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf2_enable 
            = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf2_enable = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf1_enable = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf1_enable 
            = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf1_enable 
            = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg));
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf3_enable = vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf3_enable 
            = vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg;
    }
    if ((8U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__audf3_enable 
            = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg));
    }
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
            >> 1U))) {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next 
            = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)));
    }
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
            >> 1U))) {
        if ((0U == (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)))) {
            if ((3U != (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                              >> 4U)))) {
                if ((1U == (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                                  >> 4U)))) {
                    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next = 0U;
                }
            }
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot7_next = vlTOPp->tb_top__DOT__old1__DOT__pot7_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot7_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot6_next = vlTOPp->tb_top__DOT__old1__DOT__pot6_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot6_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot5_next = vlTOPp->tb_top__DOT__old1__DOT__pot5_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot5_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot4_next = vlTOPp->tb_top__DOT__old1__DOT__pot4_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot4_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot3_next = vlTOPp->tb_top__DOT__old1__DOT__pot3_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot3_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot2_next = vlTOPp->tb_top__DOT__old1__DOT__pot2_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot2_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot1_next = vlTOPp->tb_top__DOT__old1__DOT__pot1_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot1_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot0_next = vlTOPp->tb_top__DOT__old1__DOT__pot0_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot0_next 
                = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next = 0U;
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
            >> 1U))) {
        if ((0U == (0xfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg)))) {
            if ((3U == (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                              >> 4U)))) {
                vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next = 0U;
            }
        }
    }
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg)))) {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next = 1U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_out_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serial_out_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__serial_out_next 
            = (1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_shift_reg) 
                      >> 1U) | (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_active_reg))));
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__serial_out_next 
                = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg)));
        }
    }
    if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__serial_out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg;
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next 
        = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg;
    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key = 0U;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg) 
                == (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg)) 
               | (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))))) {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key = 1U;
    }
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
         & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
            >> 1U))) {
        vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 0U;
        if ((2U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
            if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
                vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 1U;
                if (vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 0U;
                    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 0U;
                }
            } else {
                vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next = 1U;
                if (vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                    vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 3U;
                }
            }
        } else if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg))) {
            if (vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key) {
                vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next = 0U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__twotone_reset = 0U;
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
               | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                  & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serial_out_reg))))) {
        vlTOPp->tb_top__DOT__old1__DOT__twotone_reset 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                     >> 3U));
    }
    vlTOPp->tb_top__DOT__old1__DOT__async_serial_reset = 0U;
    if (((((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
           >> 4U) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg)) 
         & (9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
        vlTOPp->tb_top__DOT__old1__DOT__async_serial_reset = 1U;
    }
    VL_EXTEND_WI(342,16, __Vtemp5, (IData)(vlTOPp->out_raw1));
    VL_SHIFTL_WWI(342,342,32, __Vtemp6, __Vtemp5, 3U);
    vlTOPp->dbg1[0U] = (__Vconst1[0U] & __Vtemp6[0U]);
    vlTOPp->dbg1[1U] = (__Vconst1[1U] & __Vtemp6[1U]);
    vlTOPp->dbg1[2U] = (__Vconst1[2U] & __Vtemp6[2U]);
    vlTOPp->dbg1[3U] = (__Vconst1[3U] & __Vtemp6[3U]);
    vlTOPp->dbg1[4U] = (__Vconst1[4U] & __Vtemp6[4U]);
    vlTOPp->dbg1[5U] = (__Vconst1[5U] & __Vtemp6[5U]);
    vlTOPp->dbg1[6U] = (__Vconst1[6U] & __Vtemp6[6U]);
    vlTOPp->dbg1[7U] = (__Vconst1[7U] & __Vtemp6[7U]);
    vlTOPp->dbg1[8U] = (__Vconst1[8U] & __Vtemp6[8U]);
    vlTOPp->dbg1[9U] = (__Vconst1[9U] & __Vtemp6[9U]);
    vlTOPp->dbg1[0xaU] = (__Vconst1[0xaU] & __Vtemp6[0xaU]);
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__l;
    vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf0_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__Vfuncout));
    vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__l;
    vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf2_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__Vfuncout));
    vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__l;
    vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf1_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__Vfuncout));
    vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow_command));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__l 
        = (0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_reg));
    vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__Vfuncout 
        = vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__l;
    vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf3_enable) 
            << 1U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__Vfuncout));
    vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow 
        = (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow_command));
    vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_next = 0U;
    vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_next 
        = ((((IData)(vlTOPp->tb_top__DOT__old1__DOT__twotone_reset) 
             | (IData)(vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_reg)) 
            << 1U) | (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg) 
                            >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__audf3_reload = 
        (1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old1__DOT__async_serial_reset)));
    vlTOPp->tb_top__DOT__old1__DOT__audf2_reload = 
        (1U & (((((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                      >> 3U)) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg)) 
                 | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                     >> 3U) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) 
                | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg)) 
               | (IData)(vlTOPp->tb_top__DOT__old1__DOT__async_serial_reset)));
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc3_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                     & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg) 
                        >> 2U)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__audclk) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc3_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc3_reg))
                          ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg) 
                             >> 2U) : ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg) 
                                       >> 2U))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc2_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg) 
                     & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg) 
                        >> 1U)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__audclk) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc2_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc2_reg))
                          ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg) 
                             >> 1U) : ((IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg) 
                                       >> 1U))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc1_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                     & (IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_5_reg)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__audclk) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc1_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc1_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_4_reg)
                          : (IData)(vlTOPp->tb_top__DOT__old1__DOT__noise_large_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__audclk 
        = (1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg));
    vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg;
    if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audc0_reg) 
                  >> 7U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__audclk 
            = (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                     & (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__audclk) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_next 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc0_reg))
                      ? (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg))
                      : ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__audc0_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg)
                          : (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_next = 0U;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg)
                      : (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)));
        vlTOPp->tb_top__DOT__old1__DOT__serin_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_reg)))));
    } else {
        vlTOPp->tb_top__DOT__old1__DOT__serout_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                          ? ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_reg))
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_reg)))));
        vlTOPp->tb_top__DOT__old1__DOT__serin_enable 
            = (1U & ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                      ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                      : ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg))
                          ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg)
                          : ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_sync_reg)) 
                             & (IData)(vlTOPp->tb_top__DOT__old1__DOT__clock_reg)))));
    }
    vlTOPp->tb_top__DOT__old1__DOT__serin_next = vlTOPp->tb_top__DOT__old1__DOT__serin_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg))) {
                vlTOPp->tb_top__DOT__old1__DOT__serin_next 
                    = (0xffU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_shift_reg) 
                                >> 2U));
            }
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_ip_ready_interrupt = 0U;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg))) {
                vlTOPp->tb_top__DOT__old1__DOT__serial_ip_ready_interrupt = 1U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old1__DOT__audf0_reload) {
        vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old1__DOT__audf1_reload) {
        vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old1__DOT__audf3_reload) {
        vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg) 
                            >> 1U)));
    if (vlTOPp->tb_top__DOT__old1__DOT__audf2_reload) {
        vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__irqst_next = (0xffU 
                                                  & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_reg) 
                                                     | (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg))));
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xfeU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg))));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xfdU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (2U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                            >> 1U)) << 1U)));
    }
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xfbU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (4U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                            >> 2U)) << 2U)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xbfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (0x40U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                               >> 6U)) << 6U)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0x7fU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (0x80U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                               >> 7U)) << 7U)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_ip_ready_interrupt) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xdfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (0x20U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                               >> 5U)) << 5U)));
    }
    vlTOPp->tb_top__DOT__old1__DOT__irqst_next = ((0xf7U 
                                                   & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
                                                  | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_active_reg) 
                                                     << 3U));
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_op_needed_interrupt) {
        vlTOPp->tb_top__DOT__old1__DOT__irqst_next 
            = ((0xefU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_next)) 
               | (0x10U & ((~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqen_reg) 
                               >> 4U)) << 4U)));
    }
}

VL_INLINE_OPT void Vtb_top::_combo__TOP__5(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_combo__TOP__5\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[4U][0U] = 1U;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 3U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [4U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[3U][0U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 3U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [4U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[3U][1U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 2U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [3U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[2U][0U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 2U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [3U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[2U][1U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 2U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [3U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[2U][2U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 2U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [3U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[2U][3U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 1U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][0U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 1U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][1U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 1U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][2U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 1U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][3U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 1U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][2U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][4U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 1U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][2U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][5U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr0) >> 1U)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][3U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][6U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr0) >> 1U) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [2U][3U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[1U][7U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][0U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][1U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][2U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][1U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][3U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][2U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][4U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][2U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][5U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][3U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][6U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][3U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][7U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][4U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][8U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][4U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][9U] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][5U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xaU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][5U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xbU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][6U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xcU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][6U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xdU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr0)) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][7U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xeU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr0) & vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
           [1U][7U]);
    vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p[0U][0xfU] 
        = vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xfffcU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][1U] << 1U) | vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
            [0U][0U]));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xfff3U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][3U] << 3U) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                [0U][2U] << 2U)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xffcfU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][5U] << 5U) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                [0U][4U] << 4U)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xff3fU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][7U] << 7U) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                [0U][6U] << 6U)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xfcffU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][9U] << 9U) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                [0U][8U] << 8U)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xf3ffU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][0xbU] << 0xbU) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                    [0U][0xaU] << 0xaU)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0xcfffU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][0xdU] << 0xdU) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                    [0U][0xcU] << 0xcU)));
    vlTOPp->tb_top__DOT__old0__DOT__addr_decoded = 
        ((0x3fffU & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
             [0U][0xfU] << 0xfU) | (vlTOPp->tb_top__DOT__old0__DOT__decode_addr1__DOT__p
                                    [0U][0xeU] << 0xeU)));
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[4U][0U] = 1U;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 3U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [4U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[3U][0U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 3U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [4U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[3U][1U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 2U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [3U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[2U][0U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 2U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [3U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[2U][1U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 2U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [3U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[2U][2U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 2U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [3U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[2U][3U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 1U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][0U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 1U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][1U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 1U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][2U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 1U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][3U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 1U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][2U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][4U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 1U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][2U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][5U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ ((IData)(vlTOPp->addr1) >> 1U)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][3U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][6U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = (((IData)(vlTOPp->addr1) >> 1U) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [2U][3U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[1U][7U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][0U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][1U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][2U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][1U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][3U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][2U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][4U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][2U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][5U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][3U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][6U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][3U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][7U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][4U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][8U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][4U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][9U] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][5U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xaU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][5U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xbU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][6U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xcU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][6U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xdU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1 
        = ((~ (IData)(vlTOPp->addr1)) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][7U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xeU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2 
        = ((IData)(vlTOPp->addr1) & vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
           [1U][7U]);
    vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p[0U][0xfU] 
        = vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xfffcU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][1U] << 1U) | vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
            [0U][0U]));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xfff3U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][3U] << 3U) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                [0U][2U] << 2U)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xffcfU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][5U] << 5U) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                [0U][4U] << 4U)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xff3fU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][7U] << 7U) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                [0U][6U] << 6U)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xfcffU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][9U] << 9U) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                [0U][8U] << 8U)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xf3ffU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][0xbU] << 0xbU) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                    [0U][0xaU] << 0xaU)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0xcfffU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][0xdU] << 0xdU) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                    [0U][0xcU] << 0xcU)));
    vlTOPp->tb_top__DOT__old1__DOT__addr_decoded = 
        ((0x3fffU & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded)) 
         | ((vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
             [0U][0xfU] << 0xfU) | (vlTOPp->tb_top__DOT__old1__DOT__decode_addr1__DOT__p
                                    [0U][0xeU] << 0xeU)));
    vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n 
        = (1U & (IData)(vlTOPp->reset_n));
    vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n 
        = (1U & ((IData)(vlTOPp->reset_n) >> 1U));
    vlTOPp->tb_top__DOT__old0__DOT__serout_holding_load = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_holding_load = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__stimer_write = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x200U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__stimer_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__potgo_write = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x800U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__potgo_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__skrest_write = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x400U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__skrest_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_reset = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            if ((0U == (7U & ((IData)(vlTOPp->din0) 
                              >> 4U)))) {
                vlTOPp->tb_top__DOT__old0__DOT__serial_reset = 1U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audc1_next = vlTOPp->tb_top__DOT__old0__DOT__audc1_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((8U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc1_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_holding_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_holding_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_holding_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audc0_next = vlTOPp->tb_top__DOT__old0__DOT__audc0_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((2U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc0_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audc2_next = vlTOPp->tb_top__DOT__old0__DOT__audc2_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc2_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audc3_next = vlTOPp->tb_top__DOT__old0__DOT__audc3_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audc3_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audctl_next = vlTOPp->tb_top__DOT__old0__DOT__audctl_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x100U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audctl_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__irqen_next = vlTOPp->tb_top__DOT__old0__DOT__irqen_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x4000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__irqen_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->dout0 = 0xffU;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot0_reg;
    }
    if ((2U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot1_reg;
    }
    if ((4U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot2_reg;
    }
    if ((8U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot3_reg;
    }
    if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot4_reg;
    }
    if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot5_reg;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot6_reg;
    }
    if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__pot7_reg;
    }
    if ((0x100U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__allpot_reg;
    }
    if ((0x200U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
    }
    if ((0x400U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = (0xffU & (~ (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                     >> 8U)));
    }
    if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__serin_reg;
    }
    if ((0x4000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = vlTOPp->tb_top__DOT__old0__DOT__irqst_reg;
    }
    if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
        vlTOPp->dout0 = (1U | ((0x80U & ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_reg)) 
                                         << 7U)) | 
                               ((0x40U & ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_reg)) 
                                          << 6U)) | 
                                ((0x20U & ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_reg)) 
                                           << 5U)) 
                                 | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg) 
                                     << 4U) | ((8U 
                                                & ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg)) 
                                                   << 3U)) 
                                               | ((4U 
                                                   & ((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg)) 
                                                      << 2U)) 
                                                  | ((9U 
                                                      == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
                                                     << 1U))))))));
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf0_next = vlTOPp->tb_top__DOT__old0__DOT__audf0_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf0_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf1_next = vlTOPp->tb_top__DOT__old0__DOT__audf1_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((4U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf1_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf2_next = vlTOPp->tb_top__DOT__old0__DOT__audf2_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf2_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__audf3_next = vlTOPp->tb_top__DOT__old0__DOT__audf3_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__audf3_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__skctl_next = vlTOPp->tb_top__DOT__old0__DOT__skctl_reg;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old0__DOT__skctl_next 
                = vlTOPp->din0;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_holding_load = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_holding_load = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__stimer_write = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x200U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__stimer_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__potgo_write = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x800U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__potgo_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__skrest_write = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x400U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__skrest_write = 1U;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_reset = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            if ((0U == (7U & ((IData)(vlTOPp->din1) 
                              >> 4U)))) {
                vlTOPp->tb_top__DOT__old1__DOT__serial_reset = 1U;
            }
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audc1_next = vlTOPp->tb_top__DOT__old1__DOT__audc1_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((8U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc1_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_holding_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_holding_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_holding_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audc0_next = vlTOPp->tb_top__DOT__old1__DOT__audc0_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((2U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc0_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audc2_next = vlTOPp->tb_top__DOT__old1__DOT__audc2_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc2_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audc3_next = vlTOPp->tb_top__DOT__old1__DOT__audc3_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audc3_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audctl_next = vlTOPp->tb_top__DOT__old1__DOT__audctl_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x100U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audctl_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__irqen_next = vlTOPp->tb_top__DOT__old1__DOT__irqen_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x4000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__irqen_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->dout1 = 0xffU;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot0_reg;
    }
    if ((2U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot1_reg;
    }
    if ((4U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot2_reg;
    }
    if ((8U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot3_reg;
    }
    if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot4_reg;
    }
    if ((0x20U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot5_reg;
    }
    if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot6_reg;
    }
    if ((0x80U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__pot7_reg;
    }
    if ((0x100U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__allpot_reg;
    }
    if ((0x200U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
    }
    if ((0x400U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = (0xffU & (~ (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                     >> 8U)));
    }
    if ((0x2000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__serin_reg;
    }
    if ((0x4000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = vlTOPp->tb_top__DOT__old1__DOT__irqst_reg;
    }
    if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
        vlTOPp->dout1 = (1U | ((0x80U & ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_reg)) 
                                         << 7U)) | 
                               ((0x40U & ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_reg)) 
                                          << 6U)) | 
                                ((0x20U & ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_reg)) 
                                           << 5U)) 
                                 | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg) 
                                     << 4U) | ((8U 
                                                & ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg)) 
                                                   << 3U)) 
                                               | ((4U 
                                                   & ((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg)) 
                                                      << 2U)) 
                                                  | ((9U 
                                                      == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
                                                     << 1U))))))));
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf0_next = vlTOPp->tb_top__DOT__old1__DOT__audf0_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf0_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf1_next = vlTOPp->tb_top__DOT__old1__DOT__audf1_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((4U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf1_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf2_next = vlTOPp->tb_top__DOT__old1__DOT__audf2_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x10U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf2_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__audf3_next = vlTOPp->tb_top__DOT__old1__DOT__audf3_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x40U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__audf3_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old1__DOT__skctl_next = vlTOPp->tb_top__DOT__old1__DOT__skctl_reg;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((0x8000U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__addr_decoded))) {
            vlTOPp->tb_top__DOT__old1__DOT__skctl_next 
                = vlTOPp->din1;
        }
    }
    vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_next = 0U;
    vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_next 
        = ((((IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_write) 
             | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_reg)) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg) 
                            >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__pot_counter_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot_counter_next 
                = (0xffU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg)));
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old0__DOT__pot_counter_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__pot_reset_next 
        = vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__pot_reset_next = 1U;
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old0__DOT__pot_reset_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__allpot_next = vlTOPp->tb_top__DOT__old0__DOT__allpot_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__allpot_next = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__allpot_next 
                = vlTOPp->tb_top__DOT__old0__DOT__allpot_reg;
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old0__DOT__allpot_next = 0xffU;
    }
    vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_next 
        = vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg) 
         & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_reg) 
               >> 6U)))) {
        vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old0__DOT__keyboard_overrun_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg))) {
                if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg)))) {
                    vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_next = 1U;
                }
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old0__DOT__serial_ip_framing_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg))) {
                if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__irqst_reg) 
                              >> 5U)))) {
                    vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_next = 1U;
                }
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old0__DOT__serial_ip_overrun_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg;
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_clock_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_next 
            = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg)));
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_next = 9U;
            }
        } else {
            vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_next 
                = (0xfU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg) 
                           - (IData)(1U)));
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_active_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_active_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            vlTOPp->tb_top__DOT__old0__DOT__serout_active_next 
                = vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg;
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_active_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_next = 0U;
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serout_holding_load) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_shift_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serout_shift_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_shift_next 
            = (0x1ffU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_shift_reg) 
                         >> 1U));
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old0__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old0__DOT__serout_shift_next 
                    = (0x200U | ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_holding_reg) 
                                 << 1U));
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_next 
                = ((0U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg))
                    ? 9U : (0xfU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg) 
                                    - (IData)(1U))));
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_next = 9U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serin_shift_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serin_shift_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
            vlTOPp->tb_top__DOT__old0__DOT__serin_shift_next 
                = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg) 
                    << 9U) | (0x1ffU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_shift_reg) 
                                        >> 1U)));
        }
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serin_shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_enable) 
            << 1U) | (1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_reg) 
                            >> 1U)));
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__serial_reset) 
               | (IData)(vlTOPp->tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg)))) {
        vlTOPp->tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__serin_clock_next 
        = vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg;
    if (vlTOPp->tb_top__DOT__old0__DOT__serin_enable) {
        vlTOPp->tb_top__DOT__old0__DOT__serin_clock_next 
            = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_clock_reg)));
    }
    if (((((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_reg) 
           >> 4U) & (IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in_reg)) 
         & (9U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__serin_bitcount_reg)))) {
        vlTOPp->tb_top__DOT__old0__DOT__serin_clock_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old0__DOT__serin_clock_next = 0U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf0_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf0_reload));
    vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf0_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer0__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf1_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf1_reload));
    vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf1_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer1__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf2_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf2_reload));
    vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf2_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer2__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old0__DOT__audf3_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf3_reload));
    vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old0__DOT__audf3_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old0__DOT__timer3__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old0__DOT__initmode = (1U 
                                                & (~ 
                                                   (((IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_next) 
                                                     >> 1U) 
                                                    | (IData)(vlTOPp->tb_top__DOT__old0__DOT__skctl_next))));
    vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_next = 0U;
    vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_next 
        = ((((IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_write) 
             | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_reg)) 
            << 2U) | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg) 
                            >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__pot_counter_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot_counter_next 
                = (0xffU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg)));
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old1__DOT__pot_counter_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__pot_reset_next 
        = vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__pot_reset_next = 1U;
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old1__DOT__pot_reset_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__allpot_next = vlTOPp->tb_top__DOT__old1__DOT__allpot_reg;
    if ((1U & (((IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg) 
                & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                      >> 2U))) | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
                                  >> 2U)))) {
        if ((0xe4U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_counter_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__allpot_next = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__pot_reset_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__allpot_next 
                = vlTOPp->tb_top__DOT__old1__DOT__allpot_reg;
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__potgo_write) {
        vlTOPp->tb_top__DOT__old1__DOT__allpot_next = 0xffU;
    }
    vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_next 
        = vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg) 
         & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_reg) 
               >> 6U)))) {
        vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old1__DOT__keyboard_overrun_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg))) {
                if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg)))) {
                    vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_next = 1U;
                }
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old1__DOT__serial_ip_framing_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg))) {
                if ((1U & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__irqst_reg) 
                              >> 5U)))) {
                    vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_next = 1U;
                }
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__skrest_write) {
        vlTOPp->tb_top__DOT__old1__DOT__serial_ip_overrun_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg;
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_clock_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg;
    if ((1U & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_next 
            = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg)));
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_next = 9U;
            }
        } else {
            vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_next 
                = (0xfU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg) 
                           - (IData)(1U)));
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_active_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_active_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            vlTOPp->tb_top__DOT__old1__DOT__serout_active_next 
                = vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg;
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_active_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_next = 0U;
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serout_holding_load) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_shift_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serout_shift_reg;
    if (((~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_last_reg)) 
         & (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_shift_next 
            = (0x1ffU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_shift_reg) 
                         >> 1U));
        if ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_bitcount_reg))) {
            if (vlTOPp->tb_top__DOT__old1__DOT__serout_holding_full_reg) {
                vlTOPp->tb_top__DOT__old1__DOT__serout_shift_next 
                    = (0x200U | ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_holding_reg) 
                                 << 1U));
            }
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_next 
                = ((0U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg))
                    ? 9U : (0xfU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg) 
                                    - (IData)(1U))));
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_next = 9U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serin_shift_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serin_shift_reg;
    if (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_last_reg) 
         & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)))) {
        if ((((9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)) 
              & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg))) 
             | (9U != (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
            vlTOPp->tb_top__DOT__old1__DOT__serin_shift_next 
                = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg) 
                    << 9U) | (0x1ffU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_shift_reg) 
                                        >> 1U)));
        }
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serin_shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_next 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_enable) 
            << 1U) | (1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_reg) 
                            >> 1U)));
    if ((1U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__serial_reset) 
               | (IData)(vlTOPp->tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg)))) {
        vlTOPp->tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__serin_clock_next 
        = vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg;
    if (vlTOPp->tb_top__DOT__old1__DOT__serin_enable) {
        vlTOPp->tb_top__DOT__old1__DOT__serin_clock_next 
            = (1U & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_clock_reg)));
    }
    if (((((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_reg) 
           >> 4U) & (IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in_reg)) 
         & (9U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__serin_bitcount_reg)))) {
        vlTOPp->tb_top__DOT__old1__DOT__serin_clock_next = 1U;
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__serial_reset) {
        vlTOPp->tb_top__DOT__old1__DOT__serin_clock_next = 0U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf0_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf0_reload));
    vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf0_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer0__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf1_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf1_reload));
    vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf1_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer1__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf2_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf2_reload));
    vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf2_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer2__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_command 
        = (((IData)(vlTOPp->tb_top__DOT__old1__DOT__audf3_enable) 
            << 1U) | (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf3_reload));
    vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_next 
        = (0xffU & ((2U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_command))
                     ? ((IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_reg) 
                        - (IData)(1U)) : (((1U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_command)) 
                                           | (3U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_command)))
                                           ? (IData)(vlTOPp->tb_top__DOT__old1__DOT__audf3_next)
                                           : (IData)(vlTOPp->tb_top__DOT__old1__DOT__timer3__DOT__count_reg))));
    vlTOPp->tb_top__DOT__old1__DOT__initmode = (1U 
                                                & (~ 
                                                   (((IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_next) 
                                                     >> 1U) 
                                                    | (IData)(vlTOPp->tb_top__DOT__old1__DOT__skctl_next))));
    vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_next 
        = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg)));
    if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_next = 0U;
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__initmode) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_64_div__DOT__count_next = 6U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_next 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg)));
    if ((0x71U == (IData)(vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_next = 0U;
    }
    if (vlTOPp->tb_top__DOT__old0__DOT__initmode) {
        vlTOPp->tb_top__DOT__old0__DOT__enable_15_div__DOT__count_next = 0x21U;
    }
    vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_next 
        = ((0x10U & (((~ (((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg) 
                           >> 2U) ^ (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg))) 
                      & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__initmode))) 
                     << 4U)) | (0xfU & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg) 
                                        >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_next 
        = ((8U & (((~ (((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg) 
                        >> 1U) ^ (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg))) 
                   & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__initmode))) 
                  << 3U)) | (7U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg) 
                                   >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next 
        = vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg;
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next 
        = ((0x10000U & vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next) 
           | ((0xff00U & (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                          >> 1U)) | (((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__feedback) 
                                      << 7U) | (0x7fU 
                                                & (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                                   >> 1U)))));
    vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next 
        = ((0xffffU & vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next) 
           | (0x10000U & (((((IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__feedback) 
                             & (IData)(vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg)) 
                            | (vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg 
                               & (~ ((IData)(vlTOPp->tb_top__DOT__old0__DOT__audctl_reg) 
                                     >> 7U)))) & (~ (IData)(vlTOPp->tb_top__DOT__old0__DOT__initmode))) 
                          << 0x10U)));
    if (vlTOPp->tb_top__DOT__old0__DOT__initmode) {
        vlTOPp->tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next = 0xffU;
    }
    vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_next 
        = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg)));
    if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_next = 0U;
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__initmode) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_64_div__DOT__count_next = 6U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_next 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg)));
    if ((0x71U == (IData)(vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg))) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_next = 0U;
    }
    if (vlTOPp->tb_top__DOT__old1__DOT__initmode) {
        vlTOPp->tb_top__DOT__old1__DOT__enable_15_div__DOT__count_next = 0x21U;
    }
    vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_next 
        = ((0x10U & (((~ (((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg) 
                           >> 2U) ^ (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg))) 
                      & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__initmode))) 
                     << 4U)) | (0xfU & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg) 
                                        >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_next 
        = ((8U & (((~ (((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg) 
                        >> 1U) ^ (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg))) 
                   & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__initmode))) 
                  << 3U)) | (7U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg) 
                                   >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next 
        = vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg;
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next 
        = ((0x10000U & vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next) 
           | ((0xff00U & (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                          >> 1U)) | (((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__feedback) 
                                      << 7U) | (0x7fU 
                                                & (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                                                   >> 1U)))));
    vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next 
        = ((0xffffU & vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next) 
           | (0x10000U & (((((IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__feedback) 
                             & (IData)(vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg)) 
                            | (vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg 
                               & (~ ((IData)(vlTOPp->tb_top__DOT__old1__DOT__audctl_reg) 
                                     >> 7U)))) & (~ (IData)(vlTOPp->tb_top__DOT__old1__DOT__initmode))) 
                          << 0x10U)));
    if (vlTOPp->tb_top__DOT__old1__DOT__initmode) {
        vlTOPp->tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next = 0xffU;
    }
}

VL_INLINE_OPT void Vtb_top::_sequent__TOP__7(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_sequent__TOP__7\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_next;
    }
    if ((1U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_next;
    }
    if ((1U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_next;
    }
    if ((2U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_next;
    }
    if ((2U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_next;
    }
    if ((2U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_reg 
            = vlTOPp->tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_next;
    }
    vlTOPp->tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_reg) 
                       >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_reg) 
                       >> 1U)));
    vlTOPp->tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_reg) 
                       >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_reg) 
                       >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_reg) 
                       >> 1U)));
    vlTOPp->tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_next 
        = (4U | (3U & ((IData)(vlTOPp->tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_reg) 
                       >> 1U)));
}

void Vtb_top::_eval(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n 
        = vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n 
        = vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n;
    vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n 
        = vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n;
    vlTOPp->__VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n 
        = vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n;
}

VL_INLINE_OPT QData Vtb_top::_change_request(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_change_request\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtb_top::_change_request_1(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_change_request_1\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n ^ vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old0__reset_n)
         | (vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n ^ vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old1__reset_n));
    VL_DEBUG_IF( if(__req && ((vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n ^ vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old0__reset_n))) VL_DBG_MSGF("        CHANGE: /Work/Projects/Arcade-Centipede_MiSTer/rtl/sound/pokey/pokey.v:23: tb_top.__Vcellinp__old0__reset_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n ^ vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old1__reset_n))) VL_DBG_MSGF("        CHANGE: /Work/Projects/Arcade-Centipede_MiSTer/rtl/sound/pokey/pokey.v:23: tb_top.__Vcellinp__old1__reset_n\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old0__reset_n 
        = vlTOPp->tb_top__DOT____Vcellinp__old0__reset_n;
    vlTOPp->__Vchglast__TOP__tb_top__DOT____Vcellinp__old1__reset_n 
        = vlTOPp->tb_top__DOT____Vcellinp__old1__reset_n;
    return __req;
}

#ifdef VL_DEBUG
void Vtb_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfcU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((ce & 0xfcU))) {
        Verilated::overWidthError("ce");}
    if (VL_UNLIKELY((wr & 0xfcU))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY((rd & 0xfcU))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((addr0 & 0xf0U))) {
        Verilated::overWidthError("addr0");}
    if (VL_UNLIKELY((addr1 & 0xf0U))) {
        Verilated::overWidthError("addr1");}
}
#endif  // VL_DEBUG
