// OLDRTL build of tb_top (M12 control): the existing Mark Watson `pokey` (read-only, compiled
// from /Work/Projects/Arcade-Centipede_MiSTer/rtl/sound/pokey/) behind an out_raw-only adapter.
// Driven like the glue (old protocol); compare with --groups out.  Expected to diverge.
/* verilator lint_off PINCONNECTEMPTY */
`include "pokey_dbg_pos.svh"
wire [3:0] o0c0, o0c1, o0c2, o0c3, o1c0, o1c1, o1c2, o1c3;
pokey old0 (
    .clk(clk), .ce(ce[0]), .enable_179(1'b1), .addr(addr0), .data_in(din0), .wr_en(wr[0]), .reset_n(reset_n[0]),
    .keyboard_scan_enable(1'b0), .keyboard_scan(), .keyboard_response(2'b11),
    .pot_in(8'h00), .sio_in1(1'b1), .sio_in2(1'b1), .sio_in3(1'b1),
    .data_out(dout0), .channel_0_out(o0c0), .channel_1_out(o0c1), .channel_2_out(o0c2), .channel_3_out(o0c3),
    .irq_n_out(irq_n[0]), .sio_out1(), .sio_out2(), .sio_out3(),
    .sio_clockin_in(1'b1), .sio_clockin_out(), .sio_clockin_oe(), .sio_clockout(), .pot_reset(), .pot_count(pot_count0));
pokey old1 (
    .clk(clk), .ce(ce[1]), .enable_179(1'b1), .addr(addr1), .data_in(din1), .wr_en(wr[1]), .reset_n(reset_n[1]),
    .keyboard_scan_enable(1'b0), .keyboard_scan(), .keyboard_response(2'b11),
    .pot_in(8'h00), .sio_in1(1'b1), .sio_in2(1'b1), .sio_in3(1'b1),
    .data_out(dout1), .channel_0_out(o1c0), .channel_1_out(o1c1), .channel_2_out(o1c2), .channel_3_out(o1c3),
    .irq_n_out(irq_n[1]), .sio_out1(), .sio_out2(), .sio_out3(),
    .sio_clockin_in(1'b1), .sio_clockin_out(), .sio_clockin_oe(), .sio_clockout(), .pot_reset(), .pot_count(pot_count1));
assign out_raw0 = {o0c3, o0c2, o0c1, o0c0};
assign out_raw1 = {o1c3, o1c2, o1c1, o1c0};
assign dbg0 = {326'd0, out_raw0} << DBG_LSB_out_raw;
assign dbg1 = {326'd0, out_raw1} << DBG_LSB_out_raw;
wire unused_old = &{1'b0, rd, allpot_ext0, allpot_ext1, pot_val0, pot_val1};
/* verilator lint_on PINCONNECTEMPTY */
