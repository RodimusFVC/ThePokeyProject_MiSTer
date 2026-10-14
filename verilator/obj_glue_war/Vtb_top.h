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
        CData/*7:0*/ tb_top__DOT__g_pc0;
        CData/*7:0*/ tb_top__DOT__g_pc1;
        CData/*7:0*/ tb_top__DOT__g_cmp0;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__outp;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__fsmp;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__audctl;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__skctl;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__irqen;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__irqst;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__allpot;
        CData/*4:0*/ tb_top__DOT__u0__DOT__core__DOT__clk28;
        CData/*6:0*/ tb_top__DOT__u0__DOT__core__DOT__clk114;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__p4;
        CData/*4:0*/ tb_top__DOT__u0__DOT__core__DOT__p5;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__pot_cnt;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__irq_lvl;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__n_outp;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__n_fsmp;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_audctl;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_skctl;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_irqen;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_irqst;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_allpot;
        CData/*4:0*/ tb_top__DOT__u0__DOT__core__DOT__n_clk28;
        CData/*6:0*/ tb_top__DOT__u0__DOT__core__DOT__n_clk114;
        CData/*3:0*/ tb_top__DOT__u0__DOT__core__DOT__n_p4;
        CData/*4:0*/ tb_top__DOT__u0__DOT__core__DOT__n_p5;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__n_pot_cnt;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__n_irq;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__upd;
        CData/*2:0*/ tb_top__DOT__u0__DOT__core__DOT__arm;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__run;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__t28;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__t114;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__tb;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__async_rst;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__j12;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__j34;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__fire;
        CData/*0:0*/ tb_top__DOT__u0__DOT__core__DOT__poly9;
        CData/*7:0*/ tb_top__DOT__u0__DOT__core__DOT__ps_cnt;
        CData/*2:0*/ tb_top__DOT__u0__DOT__core__DOT__ps_sk;
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__outp;
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__fsmp;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__audctl;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__skctl;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__irqen;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__irqst;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__allpot;
        CData/*4:0*/ tb_top__DOT__u1__DOT__core__DOT__clk28;
        CData/*6:0*/ tb_top__DOT__u1__DOT__core__DOT__clk114;
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__p4;
        CData/*4:0*/ tb_top__DOT__u1__DOT__core__DOT__p5;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__pot_cnt;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__irq_lvl;
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__n_outp;
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__n_fsmp;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_audctl;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_skctl;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_irqen;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_irqst;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_allpot;
        CData/*4:0*/ tb_top__DOT__u1__DOT__core__DOT__n_clk28;
        CData/*6:0*/ tb_top__DOT__u1__DOT__core__DOT__n_clk114;
    };
    struct {
        CData/*3:0*/ tb_top__DOT__u1__DOT__core__DOT__n_p4;
        CData/*4:0*/ tb_top__DOT__u1__DOT__core__DOT__n_p5;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__n_pot_cnt;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__n_irq;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__upd;
        CData/*2:0*/ tb_top__DOT__u1__DOT__core__DOT__arm;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__run;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__t28;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__t114;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__tb;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__async_rst;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__j12;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__j34;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__fire;
        CData/*0:0*/ tb_top__DOT__u1__DOT__core__DOT__poly9;
        CData/*7:0*/ tb_top__DOT__u1__DOT__core__DOT__ps_cnt;
        CData/*2:0*/ tb_top__DOT__u1__DOT__core__DOT__ps_sk;
        SData/*8:0*/ tb_top__DOT__u0__DOT__core__DOT__p9;
        SData/*15:0*/ tb_top__DOT__u0__DOT__core__DOT__oraw;
        SData/*8:0*/ tb_top__DOT__u0__DOT__core__DOT__n_p9;
        SData/*15:0*/ tb_top__DOT__u0__DOT__core__DOT__n_oraw;
        SData/*11:0*/ tb_top__DOT__u0__DOT__core__DOT__t;
        SData/*8:0*/ tb_top__DOT__u1__DOT__core__DOT__p9;
        SData/*15:0*/ tb_top__DOT__u1__DOT__core__DOT__oraw;
        SData/*8:0*/ tb_top__DOT__u1__DOT__core__DOT__n_p9;
        SData/*15:0*/ tb_top__DOT__u1__DOT__core__DOT__n_oraw;
        SData/*11:0*/ tb_top__DOT__u1__DOT__core__DOT__t;
        IData/*16:0*/ tb_top__DOT__u0__DOT__core__DOT__p17;
        IData/*16:0*/ tb_top__DOT__u0__DOT__core__DOT__n_p17;
        IData/*16:0*/ tb_top__DOT__u1__DOT__core__DOT__p17;
        IData/*16:0*/ tb_top__DOT__u1__DOT__core__DOT__n_p17;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__audf;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__audc;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__cnt;
        VlUnpacked<CData/*2:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__bcnt;
        VlUnpacked<CData/*7:0*/, 8> tb_top__DOT__u0__DOT__core__DOT__potx;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__n_audf;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__n_audc;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__n_cnt;
        VlUnpacked<CData/*2:0*/, 4> tb_top__DOT__u0__DOT__core__DOT__n_bcnt;
        VlUnpacked<CData/*7:0*/, 8> tb_top__DOT__u0__DOT__core__DOT__n_potx;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__audf;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__audc;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__cnt;
        VlUnpacked<CData/*2:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__bcnt;
        VlUnpacked<CData/*7:0*/, 8> tb_top__DOT__u1__DOT__core__DOT__potx;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__n_audf;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__n_audc;
        VlUnpacked<CData/*7:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__n_cnt;
        VlUnpacked<CData/*2:0*/, 4> tb_top__DOT__u1__DOT__core__DOT__n_bcnt;
        VlUnpacked<CData/*7:0*/, 8> tb_top__DOT__u1__DOT__core__DOT__n_potx;
    };

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_top__DOT__u0__DOT____Vcellinp__core__wr;
        CData/*0:0*/ tb_top__DOT__u1__DOT____Vcellinp__core__wr;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__1__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__1__b;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__1__cyc;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__1__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__2__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__2__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__2__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__3__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__3__b;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__3__cyc;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__3__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__4__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__4__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__4__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__5__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__5__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__5__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__6__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__6__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__6__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__7__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__7__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__7__cn;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__8__poly9;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__9__poly9;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__10__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__10__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__10__cn;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__11__poly9;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_proc__12__poly9;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__14__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__14__b;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__14__cyc;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__14__cn;
    };
    struct {
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__15__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__15__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__15__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__16__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__16__b;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__16__cyc;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__16__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__17__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__17__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__17__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__18__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__18__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__18__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__19__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__19__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__19__cn;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__20__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__20__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__20__cn;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__21__poly9;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__22__poly9;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__23__c;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__23__b;
        CData/*7:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__23__cn;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__24__poly9;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__Vfuncout;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__o;
        CData/*2:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__c;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__p4b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__p5b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__p9b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__p17b;
        CData/*0:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_proc__25__poly9;
        CData/*0:0*/ __Vclklast__TOP__clk;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__1__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__2__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__3__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__4__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__5__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__6__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__7__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u0__DOT__core__DOT__f_inc__10__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__14__Vfuncout;
    };
    struct {
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__15__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__16__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__17__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__18__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__19__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__20__Vfuncout;
        SData/*11:0*/ __Vfunc_tb_top__DOT__u1__DOT__core__DOT__f_inc__23__Vfuncout;
    };

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
    static void _combo__TOP__2(Vtb_top__Syms* __restrict vlSymsp);
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
    static void _sequent__TOP__4(Vtb_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtb_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
