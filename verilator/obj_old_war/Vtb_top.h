// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTB_TOP_H_
#define VERILATED_VTB_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtb_top__Syms;

//----------

VL_MODULE(Vtb_top) {
  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,1,0);
    VL_IN8(ce,1,0);
    VL_IN8(wr,1,0);
    VL_IN8(rd,1,0);
    VL_IN8(addr0,3,0);
    VL_IN8(addr1,3,0);
    VL_IN8(din0,7,0);
    VL_IN8(din1,7,0);
    VL_IN8(allpot_ext0,7,0);
    VL_IN8(allpot_ext1,7,0);
    VL_OUT8(dout0,7,0);
    VL_OUT8(dout1,7,0);
    VL_OUT8(irq_n,1,0);
    VL_OUT8(pot_count0,7,0);
    VL_OUT8(pot_count1,7,0);
    VL_OUT16(out_raw0,15,0);
    VL_OUT16(out_raw1,15,0);
    VL_OUTW(dbg0,341,0,11);
    VL_OUTW(dbg1,341,0,11);
    VL_OUT(cfg,17,0);
    VL_IN64(pot_val0,63,0);
    VL_IN64(pot_val1,63,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf0_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc0_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf1_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc1_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf2_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc2_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf3_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc3_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audctl_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf0_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc0_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf1_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc1_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf2_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc2_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audf3_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audc3_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__audctl_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf0_reload;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf1_reload;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf2_reload;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf3_reload;
        CData/*0:0*/ tb_top__DOT__old0__DOT__stimer_write;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf0_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf1_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf2_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__audf3_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan0_output_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan1_output_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan2_output_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan3_output_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan0_output_del_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan1_output_del_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan0_output_del_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__chan1_output_del_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__highpass0_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__highpass1_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__highpass0_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__highpass1_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_0_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_1_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_2_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_3_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_0_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_1_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_2_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__volume_channel_3_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_4_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_4_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_5_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_5_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_large_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__noise_large_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__initmode;
        CData/*7:0*/ tb_top__DOT__old0__DOT__irqen_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__irqen_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__irqst_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__irqst_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__irq_n_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__irq_n_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_ip_ready_interrupt;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_ip_framing_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_ip_framing_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_ip_overrun_next;
    };
    struct {
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_ip_overrun_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_op_needed_interrupt;
        CData/*7:0*/ tb_top__DOT__old0__DOT__skctl_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__skctl_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__serin_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__serin_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__serin_bitcount_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__serin_bitcount_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__sio_in_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_out_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_holding_full_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_holding_full_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__serout_holding_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__serout_holding_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_holding_load;
        CData/*3:0*/ tb_top__DOT__old0__DOT__serout_bitcount_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__serout_bitcount_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_active_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_active_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serial_reset;
        CData/*0:0*/ tb_top__DOT__old0__DOT__skrest_write;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serin_enable;
        CData/*0:0*/ tb_top__DOT__old0__DOT__async_serial_reset;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serin_clock_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serin_clock_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serin_clock_last_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_clock_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_clock_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_clock_last_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__serout_clock_last_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__twotone_reset;
        CData/*0:0*/ tb_top__DOT__old0__DOT__clock_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__clock_sync_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__keyboard_overrun_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__keyboard_overrun_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot0_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot0_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot1_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot1_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot2_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot2_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot3_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot3_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot4_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot4_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot5_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot5_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot6_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot6_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot7_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot7_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__allpot_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__allpot_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot_counter_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__pot_counter_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__potgo_write;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pot_reset_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pot_reset_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer0__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer0__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__timer0__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer0__DOT__count_command;
    };
    struct {
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer0__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer0__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer1__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer1__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__timer1__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer1__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer1__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer1__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer2__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer2__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__timer2__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer2__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer2__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer2__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer3__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__timer3__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__timer3__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer3__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old0__DOT__timer3__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__timer3__DOT__underflow0_delay__DOT__shift_next;
        CData/*1:0*/ tb_top__DOT__old0__DOT__twotone_del__DOT__shift_reg;
        CData/*1:0*/ tb_top__DOT__old0__DOT__twotone_del__DOT__shift_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__twotone_del__DOT__data_in_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__stimer_delay__DOT__shift_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__stimer_delay__DOT__data_in_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter0__DOT__out_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter1__DOT__out_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter2__DOT__out_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__pokey_noise_filter3__DOT__out_reg;
        CData/*4:0*/ tb_top__DOT__old0__DOT__enable_64_div__DOT__count_reg;
        CData/*4:0*/ tb_top__DOT__old0__DOT__enable_64_div__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__enable_64_div__DOT__enabled_out_reg;
        CData/*6:0*/ tb_top__DOT__old0__DOT__enable_15_div__DOT__count_reg;
        CData/*6:0*/ tb_top__DOT__old0__DOT__enable_15_div__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__enable_15_div__DOT__enabled_out_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__cycle_delay_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__feedback;
        CData/*4:0*/ tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_reg;
        CData/*4:0*/ tb_top__DOT__old0__DOT__poly_5_lfsr__DOT__shift_next;
        CData/*3:0*/ tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_reg;
        CData/*3:0*/ tb_top__DOT__old0__DOT__poly_4_lfsr__DOT__shift_next;
        CData/*1:0*/ tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_reg;
        CData/*1:0*/ tb_top__DOT__old0__DOT__serout_clock_delay__DOT__shift_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_next;
    };
    struct {
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in1_synchronizer__DOT__ff_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in2_synchronizer__DOT__ff_reg;
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_next;
        CData/*2:0*/ tb_top__DOT__old0__DOT__sio_in3_synchronizer__DOT__ff_reg;
        CData/*5:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next;
        CData/*5:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg;
        CData/*5:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next;
        CData/*5:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg;
        CData/*7:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next;
        CData/*7:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg;
        CData/*0:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key;
        CData/*1:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
        CData/*1:0*/ tb_top__DOT__old0__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf0_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc0_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf1_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc1_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf2_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc2_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf3_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc3_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audctl_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf0_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc0_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf1_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc1_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf2_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc2_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audf3_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audc3_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__audctl_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf0_reload;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf1_reload;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf2_reload;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf3_reload;
        CData/*0:0*/ tb_top__DOT__old1__DOT__stimer_write;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf0_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf1_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf2_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__audf3_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan0_output_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan1_output_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan2_output_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan3_output_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan0_output_del_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan1_output_del_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan0_output_del_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__chan1_output_del_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__highpass0_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__highpass1_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__highpass0_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__highpass1_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_0_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_1_next;
    };
    struct {
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_2_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_3_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_0_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_1_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_2_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__volume_channel_3_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_4_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_4_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_5_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_5_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_large_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__noise_large_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__initmode;
        CData/*7:0*/ tb_top__DOT__old1__DOT__irqen_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__irqen_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__irqst_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__irqst_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__irq_n_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__irq_n_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_ip_ready_interrupt;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_ip_framing_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_ip_framing_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_ip_overrun_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_ip_overrun_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_op_needed_interrupt;
        CData/*7:0*/ tb_top__DOT__old1__DOT__skctl_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__skctl_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__serin_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__serin_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__serin_bitcount_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__serin_bitcount_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__sio_in_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_out_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_holding_full_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_holding_full_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__serout_holding_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__serout_holding_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_holding_load;
        CData/*3:0*/ tb_top__DOT__old1__DOT__serout_bitcount_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__serout_bitcount_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_active_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_active_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serial_reset;
        CData/*0:0*/ tb_top__DOT__old1__DOT__skrest_write;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serin_enable;
        CData/*0:0*/ tb_top__DOT__old1__DOT__async_serial_reset;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serin_clock_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serin_clock_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serin_clock_last_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_clock_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_clock_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_clock_last_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__serout_clock_last_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__twotone_reset;
        CData/*0:0*/ tb_top__DOT__old1__DOT__clock_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__clock_sync_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__keyboard_overrun_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__keyboard_overrun_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot0_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot0_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot1_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot1_reg;
    };
    struct {
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot2_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot2_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot3_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot3_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot4_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot4_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot5_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot5_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot6_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot6_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot7_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot7_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__allpot_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__allpot_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot_counter_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__pot_counter_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__potgo_write;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pot_reset_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pot_reset_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer0__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer0__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__timer0__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer0__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer0__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer0__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer1__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer1__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__timer1__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer1__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer1__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer1__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer2__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer2__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__timer2__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer2__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer2__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer2__DOT__underflow0_delay__DOT__shift_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer3__DOT__count_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__timer3__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__timer3__DOT__underflow;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer3__DOT__count_command;
        CData/*1:0*/ tb_top__DOT__old1__DOT__timer3__DOT__underflow_command;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__timer3__DOT__underflow0_delay__DOT__shift_next;
        CData/*1:0*/ tb_top__DOT__old1__DOT__twotone_del__DOT__shift_reg;
        CData/*1:0*/ tb_top__DOT__old1__DOT__twotone_del__DOT__shift_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__twotone_del__DOT__data_in_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__stimer_delay__DOT__shift_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__stimer_delay__DOT__data_in_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter0__DOT__out_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter1__DOT__out_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter2__DOT__out_reg;
    };
    struct {
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__audclk;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__pokey_noise_filter3__DOT__out_reg;
        CData/*4:0*/ tb_top__DOT__old1__DOT__enable_64_div__DOT__count_reg;
        CData/*4:0*/ tb_top__DOT__old1__DOT__enable_64_div__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__enable_64_div__DOT__enabled_out_reg;
        CData/*6:0*/ tb_top__DOT__old1__DOT__enable_15_div__DOT__count_reg;
        CData/*6:0*/ tb_top__DOT__old1__DOT__enable_15_div__DOT__count_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__enable_15_div__DOT__enabled_out_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__cycle_delay_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__select_9_17_del_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__feedback;
        CData/*4:0*/ tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_reg;
        CData/*4:0*/ tb_top__DOT__old1__DOT__poly_5_lfsr__DOT__shift_next;
        CData/*3:0*/ tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_reg;
        CData/*3:0*/ tb_top__DOT__old1__DOT__poly_4_lfsr__DOT__shift_next;
        CData/*1:0*/ tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_reg;
        CData/*1:0*/ tb_top__DOT__old1__DOT__serout_clock_delay__DOT__shift_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in1_synchronizer__DOT__ff_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in2_synchronizer__DOT__ff_reg;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_next;
        CData/*2:0*/ tb_top__DOT__old1__DOT__sio_in3_synchronizer__DOT__ff_reg;
        CData/*5:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_next;
        CData/*5:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__bincnt_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_pressed_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__shift_pressed_reg;
        CData/*5:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_next;
        CData/*5:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__compare_latch_reg;
        CData/*7:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_next;
        CData/*7:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__keycode_latch_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__irq_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__break_irq_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_next;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__key_held_reg;
        CData/*0:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__my_key;
        CData/*1:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_next;
        CData/*1:0*/ tb_top__DOT__old1__DOT__gen_normal_scan__DOT__pokey_keyboard_scanner1__DOT__state_reg;
        SData/*15:0*/ tb_top__DOT__old0__DOT__addr_decoded;
        SData/*9:0*/ tb_top__DOT__old0__DOT__serin_shift_next;
        SData/*9:0*/ tb_top__DOT__old0__DOT__serin_shift_reg;
        SData/*9:0*/ tb_top__DOT__old0__DOT__serout_shift_next;
        SData/*9:0*/ tb_top__DOT__old0__DOT__serout_shift_reg;
        SData/*15:0*/ tb_top__DOT__old1__DOT__addr_decoded;
        SData/*9:0*/ tb_top__DOT__old1__DOT__serin_shift_next;
        SData/*9:0*/ tb_top__DOT__old1__DOT__serin_shift_reg;
        SData/*9:0*/ tb_top__DOT__old1__DOT__serout_shift_next;
        SData/*9:0*/ tb_top__DOT__old1__DOT__serout_shift_reg;
        IData/*16:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_reg;
        IData/*16:0*/ tb_top__DOT__old0__DOT__poly_17_19_lfsr__DOT__shift_next;
        IData/*16:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_reg;
        IData/*16:0*/ tb_top__DOT__old1__DOT__poly_17_19_lfsr__DOT__shift_next;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 16>, 5> tb_top__DOT__old0__DOT__decode_addr1__DOT__p;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 16>, 5> tb_top__DOT__old1__DOT__decode_addr1__DOT__p;
    };

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ tb_top__DOT____Vcellinp__old0__reset_n;
    CData/*0:0*/ tb_top__DOT____Vcellinp__old1__reset_n;
    CData/*0:0*/ tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound1;
    CData/*0:0*/ tb_top__DOT__old0__DOT__decode_addr1__DOT____Vlvbound2;
    CData/*0:0*/ tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound1;
    CData/*0:0*/ tb_top__DOT__old1__DOT__decode_addr1__DOT____Vlvbound2;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer0__DOT__to_std_logic__0__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer1__DOT__to_std_logic__1__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer2__DOT__to_std_logic__2__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old0__DOT__timer3__DOT__to_std_logic__3__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer0__DOT__to_std_logic__4__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer1__DOT__to_std_logic__5__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer2__DOT__to_std_logic__6__l;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__Vfuncout;
    CData/*0:0*/ __Vfunc_tb_top__DOT__old1__DOT__timer3__DOT__to_std_logic__7__l;
    CData/*0:0*/ __VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n;
    CData/*0:0*/ __VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old0__reset_n;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__tb_top__DOT____Vcellinp__old1__reset_n;
    CData/*0:0*/ __Vchglast__TOP__tb_top__DOT____Vcellinp__old0__reset_n;
    CData/*0:0*/ __Vchglast__TOP__tb_top__DOT____Vcellinp__old1__reset_n;
    static VlWide<11>/*351:0*/ __Vconst1;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtb_top__Syms* __VlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtb_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtb_top(VerilatedContext* contextp, const char* name = "TOP");
    Vtb_top(const char* name = "TOP")
      : Vtb_top(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vtb_top();

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    static void _eval_initial_loop(Vtb_top__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtb_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtb_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtb_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__5(Vtb_top__Syms* __restrict vlSymsp);
  private:
    static void _ctor_var_reset(Vtb_top* self) VL_ATTR_COLD;
  public:
    static void _eval(Vtb_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vtb_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtb_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtb_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__6(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
