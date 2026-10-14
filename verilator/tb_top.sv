// Lockstep rig top: two POKEY slots (multi-chip boards), per-slot MAME config
// parameters set at verilate time (-G).  Slot s is driven independently by tb_pokey.cpp.
// `GLUE: the slots are the old-port-list glue (rtl/pokey_glue.sv) instead of pokey_cx.
// `OLDRTL: the existing Mark Watson pokey behind an out_raw-only adapter (M12 control).
`default_nettype none
module tb_top #(
    parameter [7:0] S0_POT_CB = 8'h00, parameter [0:0] S0_ALLPOT_CB = 1'b0,
    parameter [7:0] S1_POT_CB = 8'h00, parameter [0:0] S1_ALLPOT_CB = 1'b0
)(
    input  wire         clk,
    input  wire [1:0]   reset_n, ce, wr, rd,
    input  wire [3:0]   addr0, addr1,
    input  wire [7:0]   din0, din1,
    input  wire [63:0]  pot_val0, pot_val1,
    input  wire [7:0]   allpot_ext0, allpot_ext1,
    output wire [7:0]   dout0, dout1,
    output wire [1:0]   irq_n,
    output wire [15:0]  out_raw0, out_raw1,
    output wire [7:0]   pot_count0, pot_count1,
    output wire [341:0] dbg0, dbg1,
    output wire [17:0]  cfg      // {S1_ALLPOT_CB, S1_POT_CB, S0_ALLPOT_CB, S0_POT_CB}
);
assign cfg = {S1_ALLPOT_CB, S1_POT_CB, S0_ALLPOT_CB, S0_POT_CB};
`ifdef GLUE
`include "tb_top_glue.svh"
`elsif OLDRTL
`include "tb_top_old.svh"
`else
/* verilator lint_off PINCONNECTEMPTY */
pokey_cx #(.POT_CB(S0_POT_CB), .ALLPOT_CB(S0_ALLPOT_CB)) u0 (
    .clk(clk), .reset_n(reset_n[0]), .ce(ce[0]), .addr(addr0), .din(din0), .wr(wr[0]), .rd(rd[0]),
    .dout(dout0), .pot_val(pot_val0), .allpot_ext(allpot_ext0), .irq_n(irq_n[0]), .out_raw(out_raw0),
    .channel_0_out(), .channel_1_out(), .channel_2_out(), .channel_3_out(), .pot_count(pot_count0),
    .pot_in(8'h00), .pot_count_step(), .dbg_state(dbg0));
pokey_cx #(.POT_CB(S1_POT_CB), .ALLPOT_CB(S1_ALLPOT_CB)) u1 (
    .clk(clk), .reset_n(reset_n[1]), .ce(ce[1]), .addr(addr1), .din(din1), .wr(wr[1]), .rd(rd[1]),
    .dout(dout1), .pot_val(pot_val1), .allpot_ext(allpot_ext1), .irq_n(irq_n[1]), .out_raw(out_raw1),
    .channel_0_out(), .channel_1_out(), .channel_2_out(), .channel_3_out(), .pot_count(pot_count1),
    .pot_in(8'h00), .pot_count_step(), .dbg_state(dbg1));
/* verilator lint_on PINCONNECTEMPTY */
`endif
endmodule
`default_nettype wire
