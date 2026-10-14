// GLUE build of tb_top: slots are pokey_glue (old Mark Watson port list), driven with the
// old protocol (tb_pokey --glue: write = wr_en with ce on the same edge).  Pots: the board
// comparator of centiped_board.sv (pot_cmp = pot_count > paddle) with paddle = pot_val byte.
// Sx_POT_CB -> POT_CMP; Sx_ALLPOT_CB must be 0 (board muxes the DIP switches).
/* verilator lint_off PINCONNECTEMPTY */
wire [7:0] g_pc0, g_pc1;
wire [7:0] g_cmp0, g_cmp1;
genvar gi;
generate for (gi = 0; gi < 8; gi = gi + 1) begin : g_cmp
    assign g_cmp0[gi] = g_pc0 > pot_val0[8*gi +: 8];
    assign g_cmp1[gi] = g_pc1 > pot_val1[8*gi +: 8];
end endgenerate
wire [3:0] g0c0, g0c1, g0c2, g0c3, g1c0, g1c1, g1c2, g1c3;
pokey_glue #(.POT_CMP(S0_POT_CB)) u0 (
    .clk(clk), .ce(ce[0]), .enable_179(1'b1), .addr(addr0), .data_in(din0), .wr_en(wr[0]), .reset_n(reset_n[0]),
    .keyboard_scan_enable(1'b0), .keyboard_scan(), .keyboard_response(2'b11),
    .pot_in(g_cmp0 & S0_POT_CB), .sio_in1(1'b1), .sio_in2(1'b1), .sio_in3(1'b1),
    .data_out(dout0), .channel_0_out(g0c0), .channel_1_out(g0c1), .channel_2_out(g0c2), .channel_3_out(g0c3),
    .irq_n_out(irq_n[0]), .sio_out1(), .sio_out2(), .sio_out3(),
    .sio_clockin_in(1'b1), .sio_clockin_out(), .sio_clockin_oe(), .sio_clockout(), .pot_reset(), .pot_count(g_pc0),
    .dbg_state(dbg0));
pokey_glue #(.POT_CMP(S1_POT_CB)) u1 (
    .clk(clk), .ce(ce[1]), .enable_179(1'b1), .addr(addr1), .data_in(din1), .wr_en(wr[1]), .reset_n(reset_n[1]),
    .keyboard_scan_enable(1'b0), .keyboard_scan(), .keyboard_response(2'b11),
    .pot_in(g_cmp1 & S1_POT_CB), .sio_in1(1'b1), .sio_in2(1'b1), .sio_in3(1'b1),
    .data_out(dout1), .channel_0_out(g1c0), .channel_1_out(g1c1), .channel_2_out(g1c2), .channel_3_out(g1c3),
    .irq_n_out(irq_n[1]), .sio_out1(), .sio_out2(), .sio_out3(),
    .sio_clockin_in(1'b1), .sio_clockin_out(), .sio_clockin_oe(), .sio_clockout(), .pot_reset(), .pot_count(g_pc1),
    .dbg_state(dbg1));
assign out_raw0 = {g0c3, g0c2, g0c1, g0c0};
assign out_raw1 = {g1c3, g1c2, g1c1, g1c0};
assign pot_count0 = g_pc0;
assign pot_count1 = g_pc1;
wire unused_glue = &{1'b0, rd, allpot_ext0, allpot_ext1};
/* verilator lint_on PINCONNECTEMPTY */
