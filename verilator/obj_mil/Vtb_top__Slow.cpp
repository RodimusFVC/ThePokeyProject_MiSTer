// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top.h"
#include "Vtb_top__Syms.h"

//==========

Vtb_top::Vtb_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtb_top__Syms* __restrict vlSymsp = __VlSymsp = new Vtb_top__Syms(_vcontextp__, this, name());
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vtb_top::__Vconfigure(Vtb_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtb_top::~Vtb_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtb_top::_initial__TOP__1(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_initial__TOP__1\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cfg = 0x20100U;
}

void Vtb_top::_settle__TOP__3(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_settle__TOP__3\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<4>/*127:0*/ __Vtemp75;
    VlWide<5>/*159:0*/ __Vtemp77;
    VlWide<10>/*319:0*/ __Vtemp80;
    VlWide<4>/*127:0*/ __Vtemp92;
    VlWide<5>/*159:0*/ __Vtemp94;
    VlWide<10>/*319:0*/ __Vtemp97;
    // Body
    vlTOPp->pot_count0 = vlTOPp->tb_top__DOT__u0__DOT__pot_cnt;
    vlTOPp->pot_count1 = vlTOPp->tb_top__DOT__u1__DOT__pot_cnt;
    vlTOPp->irq_n = ((2U & ((~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__irq_lvl)) 
                            << 1U)) | (1U & (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__irq_lvl))));
    vlTOPp->dout0 = (0xffU & ((8U & (IData)(vlTOPp->addr0))
                               ? ((4U & (IData)(vlTOPp->addr0))
                                   ? ((2U & (IData)(vlTOPp->addr0))
                                       ? ((1U & (IData)(vlTOPp->addr0))
                                           ? 0xffU : 
                                          (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__irqst)))
                                       : ((1U & (IData)(vlTOPp->addr0))
                                           ? 0U : 0xffU))
                                   : ((2U & (IData)(vlTOPp->addr0))
                                       ? ((1U & (IData)(vlTOPp->addr0))
                                           ? 0xffU : 
                                          ((0x80U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__audctl))
                                            ? (IData)(vlTOPp->tb_top__DOT__u0__DOT__p9)
                                            : (vlTOPp->tb_top__DOT__u0__DOT__p17 
                                               >> 8U)))
                                       : ((1U & (IData)(vlTOPp->addr0))
                                           ? 9U : (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl)))
                                                    ? (IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot)
                                                    : (IData)(vlTOPp->allpot_ext0)))))
                               : ((1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot) 
                                         >> (7U & (IData)(vlTOPp->addr0))))
                                   ? vlTOPp->tb_top__DOT__u0__DOT__potx
                                  [(7U & (IData)(vlTOPp->addr0))]
                                   : (IData)(vlTOPp->tb_top__DOT__u0__DOT__pot_cnt))));
    vlTOPp->dout1 = (0xffU & ((8U & (IData)(vlTOPp->addr1))
                               ? ((4U & (IData)(vlTOPp->addr1))
                                   ? ((2U & (IData)(vlTOPp->addr1))
                                       ? ((1U & (IData)(vlTOPp->addr1))
                                           ? 0xffU : 
                                          (~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__irqst)))
                                       : ((1U & (IData)(vlTOPp->addr1))
                                           ? 0U : 0xffU))
                                   : ((2U & (IData)(vlTOPp->addr1))
                                       ? ((1U & (IData)(vlTOPp->addr1))
                                           ? 0xffU : 
                                          ((0x80U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__audctl))
                                            ? (IData)(vlTOPp->tb_top__DOT__u1__DOT__p9)
                                            : (vlTOPp->tb_top__DOT__u1__DOT__p17 
                                               >> 8U)))
                                       : ((1U & (IData)(vlTOPp->addr1))
                                           ? 9U : (
                                                   (0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl)))
                                                    ? (IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot)
                                                    : (IData)(vlTOPp->allpot_ext1)))))
                               : ((1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot) 
                                         >> (7U & (IData)(vlTOPp->addr1))))
                                   ? vlTOPp->tb_top__DOT__u1__DOT__potx
                                  [(7U & (IData)(vlTOPp->addr1))]
                                   : (IData)(vlTOPp->tb_top__DOT__u1__DOT__pot_cnt))));
    vlTOPp->out_raw0 = vlTOPp->tb_top__DOT__u0__DOT__oraw;
    vlTOPp->out_raw1 = vlTOPp->tb_top__DOT__u1__DOT__oraw;
    vlTOPp->tb_top__DOT__u0__DOT__n_audf[0U] = vlTOPp->tb_top__DOT__u0__DOT__audf
        [0U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audc[0U] = vlTOPp->tb_top__DOT__u0__DOT__audc
        [0U];
    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] = vlTOPp->tb_top__DOT__u0__DOT__cnt
        [0U];
    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] = vlTOPp->tb_top__DOT__u0__DOT__bcnt
        [0U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audf[1U] = vlTOPp->tb_top__DOT__u0__DOT__audf
        [1U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audc[1U] = vlTOPp->tb_top__DOT__u0__DOT__audc
        [1U];
    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[1U] = vlTOPp->tb_top__DOT__u0__DOT__cnt
        [1U];
    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] = vlTOPp->tb_top__DOT__u0__DOT__bcnt
        [1U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audf[2U] = vlTOPp->tb_top__DOT__u0__DOT__audf
        [2U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audc[2U] = vlTOPp->tb_top__DOT__u0__DOT__audc
        [2U];
    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] = vlTOPp->tb_top__DOT__u0__DOT__cnt
        [2U];
    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] = vlTOPp->tb_top__DOT__u0__DOT__bcnt
        [2U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audf[3U] = vlTOPp->tb_top__DOT__u0__DOT__audf
        [3U];
    vlTOPp->tb_top__DOT__u0__DOT__n_audc[3U] = vlTOPp->tb_top__DOT__u0__DOT__audc
        [3U];
    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] = vlTOPp->tb_top__DOT__u0__DOT__cnt
        [3U];
    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] = vlTOPp->tb_top__DOT__u0__DOT__bcnt
        [3U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[0U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [0U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[1U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [1U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[2U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [2U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[3U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [3U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[4U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [4U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[5U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [5U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[6U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [6U];
    vlTOPp->tb_top__DOT__u0__DOT__n_potx[7U] = vlTOPp->tb_top__DOT__u0__DOT__potx
        [7U];
    vlTOPp->tb_top__DOT__u0__DOT__n_outp = vlTOPp->tb_top__DOT__u0__DOT__outp;
    vlTOPp->tb_top__DOT__u0__DOT__n_fsmp = vlTOPp->tb_top__DOT__u0__DOT__fsmp;
    vlTOPp->tb_top__DOT__u0__DOT__n_audctl = vlTOPp->tb_top__DOT__u0__DOT__audctl;
    vlTOPp->tb_top__DOT__u0__DOT__n_skctl = vlTOPp->tb_top__DOT__u0__DOT__skctl;
    vlTOPp->tb_top__DOT__u0__DOT__n_irqen = vlTOPp->tb_top__DOT__u0__DOT__irqen;
    vlTOPp->tb_top__DOT__u0__DOT__n_irqst = vlTOPp->tb_top__DOT__u0__DOT__irqst;
    vlTOPp->tb_top__DOT__u0__DOT__n_allpot = vlTOPp->tb_top__DOT__u0__DOT__allpot;
    vlTOPp->tb_top__DOT__u0__DOT__n_clk28 = vlTOPp->tb_top__DOT__u0__DOT__clk28;
    vlTOPp->tb_top__DOT__u0__DOT__n_clk114 = vlTOPp->tb_top__DOT__u0__DOT__clk114;
    vlTOPp->tb_top__DOT__u0__DOT__n_p4 = vlTOPp->tb_top__DOT__u0__DOT__p4;
    vlTOPp->tb_top__DOT__u0__DOT__n_p5 = vlTOPp->tb_top__DOT__u0__DOT__p5;
    vlTOPp->tb_top__DOT__u0__DOT__n_p9 = vlTOPp->tb_top__DOT__u0__DOT__p9;
    vlTOPp->tb_top__DOT__u0__DOT__n_p17 = vlTOPp->tb_top__DOT__u0__DOT__p17;
    vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt = vlTOPp->tb_top__DOT__u0__DOT__pot_cnt;
    vlTOPp->tb_top__DOT__u0__DOT__n_oraw = vlTOPp->tb_top__DOT__u0__DOT__oraw;
    vlTOPp->tb_top__DOT__u0__DOT__n_irq = vlTOPp->tb_top__DOT__u0__DOT__irq_lvl;
    vlTOPp->tb_top__DOT__u0__DOT__t = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__upd = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__arm = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__run = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__t28 = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__t114 = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__tb = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__async_rst = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__j12 = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__j34 = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__fire = 0U;
    vlTOPp->tb_top__DOT__u0__DOT__poly9 = 0U;
    if ((1U & (IData)(vlTOPp->wr))) {
        if ((8U & (IData)(vlTOPp->addr0))) {
            if ((4U & (IData)(vlTOPp->addr0))) {
                if ((2U & (IData)(vlTOPp->addr0))) {
                    if ((1U & (IData)(vlTOPp->addr0))) {
                        if (((IData)(vlTOPp->din0) 
                             != (IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl))) {
                            vlTOPp->tb_top__DOT__u0__DOT__n_skctl 
                                = vlTOPp->din0;
                            if ((0U == (3U & (IData)(vlTOPp->din0)))) {
                                vlTOPp->tb_top__DOT__u0__DOT__n_irqen = 0U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_irqst = 8U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_irq = 0U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_p4 = 1U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_p5 = 1U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_p9 = 0xffU;
                                vlTOPp->tb_top__DOT__u0__DOT__n_p17 = 0x1ff7fU;
                                vlTOPp->tb_top__DOT__u0__DOT__n_clk28 = 0U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_clk114 = 0U;
                            }
                            if ((0x10U & (IData)(vlTOPp->din0))) {
                                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                                [2U]));
                                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] = 0U;
                                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] 
                                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                                [3U]));
                                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] = 0U;
                            }
                        }
                    } else {
                        vlTOPp->tb_top__DOT__u0__DOT__n_irqst 
                            = ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqst) 
                               & (8U | (IData)(vlTOPp->din0)));
                        vlTOPp->tb_top__DOT__u0__DOT__n_irqen 
                            = vlTOPp->din0;
                        if ((0U != (8U & ((IData)(vlTOPp->din0) 
                                          & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqst))))) {
                            vlTOPp->tb_top__DOT__u0__DOT__n_irq = 1U;
                        } else if ((0U == ((IData)(vlTOPp->din0) 
                                           & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqst)))) {
                            vlTOPp->tb_top__DOT__u0__DOT__n_irq = 0U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->addr0))) {
                if ((1U & (IData)(vlTOPp->addr0))) {
                    if ((0U != (3U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl)))) {
                        vlTOPp->tb_top__DOT__u0__DOT__n_allpot = 0U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt = 0U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[0U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[1U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[2U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[3U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[4U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[5U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[6U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u0__DOT__n_potx[7U] = 0xe4U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->addr0))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__n_outp = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__n_fsmp = 3U;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[1U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [1U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [3U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] = 0U;
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_audctl 
                    = vlTOPp->din0;
            }
        } else if ((4U & (IData)(vlTOPp->addr0))) {
            if ((2U & (IData)(vlTOPp->addr0))) {
                if ((1U & (IData)(vlTOPp->addr0))) {
                    vlTOPp->tb_top__DOT__u0__DOT__n_audc[3U] 
                        = vlTOPp->din0;
                } else {
                    vlTOPp->tb_top__DOT__u0__DOT__n_audf[3U] 
                        = vlTOPp->din0;
                }
            } else if ((1U & (IData)(vlTOPp->addr0))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_audc[2U] 
                    = vlTOPp->din0;
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_audf[2U] 
                    = vlTOPp->din0;
            }
        } else if ((2U & (IData)(vlTOPp->addr0))) {
            if ((1U & (IData)(vlTOPp->addr0))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_audc[1U] 
                    = vlTOPp->din0;
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_audf[1U] 
                    = vlTOPp->din0;
            }
        } else if ((1U & (IData)(vlTOPp->addr0))) {
            vlTOPp->tb_top__DOT__u0__DOT__n_audc[0U] 
                = vlTOPp->din0;
        } else {
            vlTOPp->tb_top__DOT__u0__DOT__n_audf[0U] 
                = vlTOPp->din0;
        }
    }
    if ((((IData)(vlTOPp->rd) & (8U == (IData)(vlTOPp->addr0))) 
         & (0U != (3U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_skctl))))) {
        vlTOPp->tb_top__DOT__u0__DOT__n_allpot = vlTOPp->allpot_ext0;
    }
    if ((1U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__u0__DOT__run = (0U != 
                                             (3U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_skctl)));
        vlTOPp->tb_top__DOT__u0__DOT__j12 = (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl) 
                                                   >> 4U));
        vlTOPp->tb_top__DOT__u0__DOT__j34 = (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl) 
                                                   >> 3U));
        vlTOPp->tb_top__DOT__u0__DOT__poly9 = (1U & 
                                               ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl) 
                                                >> 7U));
        vlTOPp->tb_top__DOT__u0__DOT__async_rst = (1U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_skctl) 
                                                      >> 4U));
        if (vlTOPp->tb_top__DOT__u0__DOT__run) {
            vlTOPp->tb_top__DOT__u0__DOT__n_p4 = ((0xeU 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (~ 
                                                        (((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4) 
                                                          >> 2U) 
                                                         ^ 
                                                         ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4) 
                                                          >> 3U)))));
            vlTOPp->tb_top__DOT__u0__DOT__n_p5 = ((0x1eU 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (~ 
                                                        (((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5) 
                                                          >> 2U) 
                                                         ^ 
                                                         ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5) 
                                                          >> 4U)))));
            vlTOPp->tb_top__DOT__u0__DOT__n_p9 = ((0x100U 
                                                   & (((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9) 
                                                       << 8U) 
                                                      ^ 
                                                      (0xffffff00U 
                                                       & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9) 
                                                          << 3U)))) 
                                                  | (0xffU 
                                                     & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9) 
                                                        >> 1U)));
            vlTOPp->tb_top__DOT__u0__DOT__n_p17 = (
                                                   (0x10000U 
                                                    & (vlTOPp->tb_top__DOT__u0__DOT__n_p17 
                                                       << 0x10U)) 
                                                   | ((0xff00U 
                                                       & (vlTOPp->tb_top__DOT__u0__DOT__n_p17 
                                                          >> 1U)) 
                                                      | ((0x80U 
                                                          & (VL_REDXOR_32(
                                                                          (0x2100U 
                                                                           & vlTOPp->tb_top__DOT__u0__DOT__n_p17)) 
                                                             << 7U)) 
                                                         | (0x7fU 
                                                            & (vlTOPp->tb_top__DOT__u0__DOT__n_p17 
                                                               >> 1U)))));
            if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_clk28))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_clk28 = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__t28 = 1U;
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_clk28 
                    = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_clk28)));
            }
            if ((0x71U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_clk114))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_clk114 = 0U;
                vlTOPp->tb_top__DOT__u0__DOT__t114 = 1U;
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_clk114 
                    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_clk114)));
            }
            vlTOPp->tb_top__DOT__u0__DOT__tb = ((1U 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl))
                                                 ? (IData)(vlTOPp->tb_top__DOT__u0__DOT__t114)
                                                 : (IData)(vlTOPp->tb_top__DOT__u0__DOT__t28));
            if ((0x40U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl))) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cyc 
                    = ((IData)(vlTOPp->tb_top__DOT__u0__DOT__j12)
                        ? 7U : 4U);
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__b)))
                        ? (0x800U | (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cyc) 
                                      << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cn)))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((6U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                              >> 0xbU)));
            } else if (vlTOPp->tb_top__DOT__u0__DOT__tb) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((6U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                              >> 0xbU)));
            }
            if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__async_rst)))) {
                if ((0x20U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl))) {
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cyc 
                        = ((IData)(vlTOPp->tb_top__DOT__u0__DOT__j34)
                            ? 7U : 4U);
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__b 
                        = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__c 
                        = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cn 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__c)));
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__Vfuncout 
                        = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cn)) 
                            & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__b)))
                            ? (0x800U | (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cyc) 
                                          << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cn)))
                            : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__b) 
                                << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cn)));
                    vlTOPp->tb_top__DOT__u0__DOT__t 
                        = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__Vfuncout;
                    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                        = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] 
                        = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                                 >> 8U));
                } else if (vlTOPp->tb_top__DOT__u0__DOT__tb) {
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__b 
                        = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__c 
                        = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__cn 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__c)));
                    vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__Vfuncout 
                        = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__cn)) 
                            & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__b)))
                            ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__cn))
                            : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__b) 
                                << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__cn)));
                    vlTOPp->tb_top__DOT__u0__DOT__t 
                        = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__Vfuncout;
                    vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                        = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                    vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] 
                        = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                                 >> 8U));
                }
            }
            if (((IData)(vlTOPp->tb_top__DOT__u0__DOT__tb) 
                 & (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__j12)))) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[1U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((5U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (2U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                              >> 0xaU)));
            }
            if ((((IData)(vlTOPp->tb_top__DOT__u0__DOT__tb) 
                  & (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__j34))) 
                 & (~ (IData)(vlTOPp->tb_top__DOT__u0__DOT__async_rst)))) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((3U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (4U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                              >> 9U)));
            }
            if ((((IData)(vlTOPp->tb_top__DOT__u0__DOT__t114) 
                  | ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_skctl) 
                     >> 2U)) & (0xe4U > (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)))) {
                vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xfeU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | ((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                         [0U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                        | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xfdU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [1U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 1U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xfbU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [2U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 2U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xf7U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [3U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 3U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xefU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [4U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 4U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xdfU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [5U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 5U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0xbfU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [6U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 6U));
                vlTOPp->tb_top__DOT__u0__DOT__upd = 
                    ((0x7fU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u0__DOT__n_potx
                          [7U] < (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_pot_cnt))) 
                        << 7U));
            }
        }
        vlTOPp->tb_top__DOT__u0__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                                              [2U]);
        if ((0U != vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
             [2U])) {
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                         [2U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u0__DOT__fire) {
            if (vlTOPp->tb_top__DOT__u0__DOT__j34) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((3U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (4U & ((0xfffffffcU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                              | (0x7ffffcU & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                                              >> 9U)))));
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__poly9 
                = vlTOPp->tb_top__DOT__u0__DOT__poly9;
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p17b 
                = (1U & vlTOPp->tb_top__DOT__u0__DOT__n_p17);
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__c 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                         [2U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                         >> 2U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__o)));
            vlTOPp->tb_top__DOT__u0__DOT__n_outp = 
                ((0xbU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__Vfuncout) 
                    << 2U));
            vlTOPp->tb_top__DOT__u0__DOT__n_fsmp = 
                ((0xeU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                 | (1U & ((~ ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl) 
                              >> 2U)) | (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp))));
        }
        vlTOPp->tb_top__DOT__u0__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                                              [3U]);
        if ((0U != vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
             [3U])) {
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                         [3U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u0__DOT__fire) {
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__poly9 
                = vlTOPp->tb_top__DOT__u0__DOT__poly9;
            if (vlTOPp->tb_top__DOT__u0__DOT__j34) {
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[2U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p17b 
                = (1U & vlTOPp->tb_top__DOT__u0__DOT__n_p17);
            vlTOPp->tb_top__DOT__u0__DOT__n_cnt[3U] 
                = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                            [3U]));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9));
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[3U] = 0U;
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__c 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                         [3U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                         >> 3U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__o)));
            vlTOPp->tb_top__DOT__u0__DOT__n_outp = 
                ((7U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__Vfuncout) 
                    << 3U));
            vlTOPp->tb_top__DOT__u0__DOT__n_fsmp = 
                ((0xdU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                 | (2U & (((~ ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_audctl) 
                               >> 1U)) << 1U) | (0xfffffffeU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp)))));
        }
        vlTOPp->tb_top__DOT__u0__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                                              [0U]);
        if ((0U != vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
             [0U])) {
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                         [0U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u0__DOT__fire) {
            if (vlTOPp->tb_top__DOT__u0__DOT__j12) {
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__b 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__c 
                    = vlTOPp->tb_top__DOT__u0__DOT__n_cnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__cn)));
                vlTOPp->tb_top__DOT__u0__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__Vfuncout;
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[1U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__t));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u0__DOT__arm = 
                    ((5U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                     | (2U & ((0xfffffffeU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__arm)) 
                              | (0x3ffffeU & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__t) 
                                              >> 0xaU)))));
            } else {
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__poly9 
                = vlTOPp->tb_top__DOT__u0__DOT__poly9;
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p17b 
                = (1U & vlTOPp->tb_top__DOT__u0__DOT__n_p17);
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__c 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                         [0U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__o 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__o)));
            vlTOPp->tb_top__DOT__u0__DOT__n_outp = 
                ((0xeU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp)) 
                 | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__Vfuncout));
        }
        vlTOPp->tb_top__DOT__u0__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                                              [1U]);
        if ((0U != vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
             [1U])) {
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_bcnt
                         [1U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u0__DOT__fire) {
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__poly9 
                = vlTOPp->tb_top__DOT__u0__DOT__poly9;
            if (vlTOPp->tb_top__DOT__u0__DOT__j12) {
                vlTOPp->tb_top__DOT__u0__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[0U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p17b 
                = (1U & vlTOPp->tb_top__DOT__u0__DOT__n_p17);
            vlTOPp->tb_top__DOT__u0__DOT__n_cnt[1U] 
                = (0xffU & (~ vlTOPp->tb_top__DOT__u0__DOT__n_audf
                            [1U]));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p9));
            vlTOPp->tb_top__DOT__u0__DOT__n_bcnt[1U] = 0U;
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__c 
                = (7U & (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                         [1U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                         >> 1U));
            vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__o)));
            vlTOPp->tb_top__DOT__u0__DOT__n_outp = 
                ((0xdU & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__Vfuncout) 
                    << 1U));
        }
        vlTOPp->tb_top__DOT__u0__DOT__n_oraw = ((0xfff0U 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_oraw)) 
                                                | ((1U 
                                                    & (((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                                                        ^ (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                                                       | (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                          [0U] 
                                                          >> 4U)))
                                                    ? 
                                                   (0xfU 
                                                    & vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                    [0U])
                                                    : 0U));
        vlTOPp->tb_top__DOT__u0__DOT__n_oraw = ((0xff0fU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                                                         >> 1U) 
                                                        | (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                           [1U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                     [1U])
                                                     : 0U) 
                                                   << 4U));
        vlTOPp->tb_top__DOT__u0__DOT__n_oraw = ((0xf0ffU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                                                         >> 2U) 
                                                        | (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                           [2U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                     [2U])
                                                     : 0U) 
                                                   << 8U));
        vlTOPp->tb_top__DOT__u0__DOT__n_oraw = ((0xfffU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_fsmp)) 
                                                         >> 3U) 
                                                        | (vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                           [3U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u0__DOT__n_audc
                                                     [3U])
                                                     : 0U) 
                                                   << 0xcU));
        vlTOPp->tb_top__DOT__u0__DOT__n_allpot = ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_allpot) 
                                                  | (IData)(vlTOPp->tb_top__DOT__u0__DOT__upd));
        if ((0U != ((IData)(vlTOPp->tb_top__DOT__u0__DOT__arm) 
                    & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqen)))) {
            vlTOPp->tb_top__DOT__u0__DOT__n_irqst = 
                ((0xf8U & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqst)) 
                 | (7U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqst) 
                          | ((IData)(vlTOPp->tb_top__DOT__u0__DOT__arm) 
                             & (IData)(vlTOPp->tb_top__DOT__u0__DOT__n_irqen)))));
            vlTOPp->tb_top__DOT__u0__DOT__n_irq = 1U;
        }
    }
    vlTOPp->tb_top__DOT__u1__DOT__n_audf[0U] = vlTOPp->tb_top__DOT__u1__DOT__audf
        [0U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audc[0U] = vlTOPp->tb_top__DOT__u1__DOT__audc
        [0U];
    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] = vlTOPp->tb_top__DOT__u1__DOT__cnt
        [0U];
    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] = vlTOPp->tb_top__DOT__u1__DOT__bcnt
        [0U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audf[1U] = vlTOPp->tb_top__DOT__u1__DOT__audf
        [1U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audc[1U] = vlTOPp->tb_top__DOT__u1__DOT__audc
        [1U];
    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[1U] = vlTOPp->tb_top__DOT__u1__DOT__cnt
        [1U];
    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] = vlTOPp->tb_top__DOT__u1__DOT__bcnt
        [1U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audf[2U] = vlTOPp->tb_top__DOT__u1__DOT__audf
        [2U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audc[2U] = vlTOPp->tb_top__DOT__u1__DOT__audc
        [2U];
    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] = vlTOPp->tb_top__DOT__u1__DOT__cnt
        [2U];
    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] = vlTOPp->tb_top__DOT__u1__DOT__bcnt
        [2U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audf[3U] = vlTOPp->tb_top__DOT__u1__DOT__audf
        [3U];
    vlTOPp->tb_top__DOT__u1__DOT__n_audc[3U] = vlTOPp->tb_top__DOT__u1__DOT__audc
        [3U];
    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] = vlTOPp->tb_top__DOT__u1__DOT__cnt
        [3U];
    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] = vlTOPp->tb_top__DOT__u1__DOT__bcnt
        [3U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[0U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [0U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[1U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [1U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[2U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [2U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[3U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [3U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[4U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [4U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[5U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [5U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[6U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [6U];
    vlTOPp->tb_top__DOT__u1__DOT__n_potx[7U] = vlTOPp->tb_top__DOT__u1__DOT__potx
        [7U];
    vlTOPp->tb_top__DOT__u1__DOT__n_outp = vlTOPp->tb_top__DOT__u1__DOT__outp;
    vlTOPp->tb_top__DOT__u1__DOT__n_fsmp = vlTOPp->tb_top__DOT__u1__DOT__fsmp;
    vlTOPp->tb_top__DOT__u1__DOT__n_audctl = vlTOPp->tb_top__DOT__u1__DOT__audctl;
    vlTOPp->tb_top__DOT__u1__DOT__n_skctl = vlTOPp->tb_top__DOT__u1__DOT__skctl;
    vlTOPp->tb_top__DOT__u1__DOT__n_irqen = vlTOPp->tb_top__DOT__u1__DOT__irqen;
    vlTOPp->tb_top__DOT__u1__DOT__n_irqst = vlTOPp->tb_top__DOT__u1__DOT__irqst;
    vlTOPp->tb_top__DOT__u1__DOT__n_allpot = vlTOPp->tb_top__DOT__u1__DOT__allpot;
    vlTOPp->tb_top__DOT__u1__DOT__n_clk28 = vlTOPp->tb_top__DOT__u1__DOT__clk28;
    vlTOPp->tb_top__DOT__u1__DOT__n_clk114 = vlTOPp->tb_top__DOT__u1__DOT__clk114;
    vlTOPp->tb_top__DOT__u1__DOT__n_p4 = vlTOPp->tb_top__DOT__u1__DOT__p4;
    vlTOPp->tb_top__DOT__u1__DOT__n_p5 = vlTOPp->tb_top__DOT__u1__DOT__p5;
    vlTOPp->tb_top__DOT__u1__DOT__n_p9 = vlTOPp->tb_top__DOT__u1__DOT__p9;
    vlTOPp->tb_top__DOT__u1__DOT__n_p17 = vlTOPp->tb_top__DOT__u1__DOT__p17;
    vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt = vlTOPp->tb_top__DOT__u1__DOT__pot_cnt;
    vlTOPp->tb_top__DOT__u1__DOT__n_oraw = vlTOPp->tb_top__DOT__u1__DOT__oraw;
    vlTOPp->tb_top__DOT__u1__DOT__n_irq = vlTOPp->tb_top__DOT__u1__DOT__irq_lvl;
    vlTOPp->tb_top__DOT__u1__DOT__t = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__upd = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__arm = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__run = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__t28 = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__t114 = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__tb = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__async_rst = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__j12 = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__j34 = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__fire = 0U;
    vlTOPp->tb_top__DOT__u1__DOT__poly9 = 0U;
    if ((2U & (IData)(vlTOPp->wr))) {
        if ((8U & (IData)(vlTOPp->addr1))) {
            if ((4U & (IData)(vlTOPp->addr1))) {
                if ((2U & (IData)(vlTOPp->addr1))) {
                    if ((1U & (IData)(vlTOPp->addr1))) {
                        if (((IData)(vlTOPp->din1) 
                             != (IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl))) {
                            vlTOPp->tb_top__DOT__u1__DOT__n_skctl 
                                = vlTOPp->din1;
                            if ((0U == (3U & (IData)(vlTOPp->din1)))) {
                                vlTOPp->tb_top__DOT__u1__DOT__n_irqen = 0U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_irqst = 8U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_irq = 0U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_p4 = 1U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_p5 = 1U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_p9 = 0xffU;
                                vlTOPp->tb_top__DOT__u1__DOT__n_p17 = 0x1ff7fU;
                                vlTOPp->tb_top__DOT__u1__DOT__n_clk28 = 0U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_clk114 = 0U;
                            }
                            if ((0x10U & (IData)(vlTOPp->din1))) {
                                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                                [2U]));
                                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] = 0U;
                                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] 
                                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                                [3U]));
                                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] = 0U;
                            }
                        }
                    } else {
                        vlTOPp->tb_top__DOT__u1__DOT__n_irqst 
                            = ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqst) 
                               & (8U | (IData)(vlTOPp->din1)));
                        vlTOPp->tb_top__DOT__u1__DOT__n_irqen 
                            = vlTOPp->din1;
                        if ((0U != (8U & ((IData)(vlTOPp->din1) 
                                          & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqst))))) {
                            vlTOPp->tb_top__DOT__u1__DOT__n_irq = 1U;
                        } else if ((0U == ((IData)(vlTOPp->din1) 
                                           & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqst)))) {
                            vlTOPp->tb_top__DOT__u1__DOT__n_irq = 0U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->addr1))) {
                if ((1U & (IData)(vlTOPp->addr1))) {
                    if ((0U != (3U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl)))) {
                        vlTOPp->tb_top__DOT__u1__DOT__n_allpot = 0U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt = 0U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[0U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[1U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[2U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[3U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[4U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[5U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[6U] = 0xe4U;
                        vlTOPp->tb_top__DOT__u1__DOT__n_potx[7U] = 0xe4U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->addr1))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__n_outp = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__n_fsmp = 3U;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[1U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [1U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [3U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] = 0U;
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_audctl 
                    = vlTOPp->din1;
            }
        } else if ((4U & (IData)(vlTOPp->addr1))) {
            if ((2U & (IData)(vlTOPp->addr1))) {
                if ((1U & (IData)(vlTOPp->addr1))) {
                    vlTOPp->tb_top__DOT__u1__DOT__n_audc[3U] 
                        = vlTOPp->din1;
                } else {
                    vlTOPp->tb_top__DOT__u1__DOT__n_audf[3U] 
                        = vlTOPp->din1;
                }
            } else if ((1U & (IData)(vlTOPp->addr1))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_audc[2U] 
                    = vlTOPp->din1;
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_audf[2U] 
                    = vlTOPp->din1;
            }
        } else if ((2U & (IData)(vlTOPp->addr1))) {
            if ((1U & (IData)(vlTOPp->addr1))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_audc[1U] 
                    = vlTOPp->din1;
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_audf[1U] 
                    = vlTOPp->din1;
            }
        } else if ((1U & (IData)(vlTOPp->addr1))) {
            vlTOPp->tb_top__DOT__u1__DOT__n_audc[0U] 
                = vlTOPp->din1;
        } else {
            vlTOPp->tb_top__DOT__u1__DOT__n_audf[0U] 
                = vlTOPp->din1;
        }
    }
    if (((((IData)(vlTOPp->rd) >> 1U) & (8U == (IData)(vlTOPp->addr1))) 
         & (0U != (3U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_skctl))))) {
        vlTOPp->tb_top__DOT__u1__DOT__n_allpot = vlTOPp->allpot_ext1;
    }
    if ((2U & (IData)(vlTOPp->ce))) {
        vlTOPp->tb_top__DOT__u1__DOT__run = (0U != 
                                             (3U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_skctl)));
        vlTOPp->tb_top__DOT__u1__DOT__j12 = (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl) 
                                                   >> 4U));
        vlTOPp->tb_top__DOT__u1__DOT__j34 = (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl) 
                                                   >> 3U));
        vlTOPp->tb_top__DOT__u1__DOT__poly9 = (1U & 
                                               ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl) 
                                                >> 7U));
        vlTOPp->tb_top__DOT__u1__DOT__async_rst = (1U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_skctl) 
                                                      >> 4U));
        if (vlTOPp->tb_top__DOT__u1__DOT__run) {
            vlTOPp->tb_top__DOT__u1__DOT__n_p4 = ((0xeU 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (~ 
                                                        (((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4) 
                                                          >> 2U) 
                                                         ^ 
                                                         ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4) 
                                                          >> 3U)))));
            vlTOPp->tb_top__DOT__u1__DOT__n_p5 = ((0x1eU 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (~ 
                                                        (((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5) 
                                                          >> 2U) 
                                                         ^ 
                                                         ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5) 
                                                          >> 4U)))));
            vlTOPp->tb_top__DOT__u1__DOT__n_p9 = ((0x100U 
                                                   & (((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9) 
                                                       << 8U) 
                                                      ^ 
                                                      (0xffffff00U 
                                                       & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9) 
                                                          << 3U)))) 
                                                  | (0xffU 
                                                     & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9) 
                                                        >> 1U)));
            vlTOPp->tb_top__DOT__u1__DOT__n_p17 = (
                                                   (0x10000U 
                                                    & (vlTOPp->tb_top__DOT__u1__DOT__n_p17 
                                                       << 0x10U)) 
                                                   | ((0xff00U 
                                                       & (vlTOPp->tb_top__DOT__u1__DOT__n_p17 
                                                          >> 1U)) 
                                                      | ((0x80U 
                                                          & (VL_REDXOR_32(
                                                                          (0x2100U 
                                                                           & vlTOPp->tb_top__DOT__u1__DOT__n_p17)) 
                                                             << 7U)) 
                                                         | (0x7fU 
                                                            & (vlTOPp->tb_top__DOT__u1__DOT__n_p17 
                                                               >> 1U)))));
            if ((0x1bU == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_clk28))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_clk28 = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__t28 = 1U;
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_clk28 
                    = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_clk28)));
            }
            if ((0x71U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_clk114))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_clk114 = 0U;
                vlTOPp->tb_top__DOT__u1__DOT__t114 = 1U;
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_clk114 
                    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_clk114)));
            }
            vlTOPp->tb_top__DOT__u1__DOT__tb = ((1U 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl))
                                                 ? (IData)(vlTOPp->tb_top__DOT__u1__DOT__t114)
                                                 : (IData)(vlTOPp->tb_top__DOT__u1__DOT__t28));
            if ((0x40U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl))) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cyc 
                    = ((IData)(vlTOPp->tb_top__DOT__u1__DOT__j12)
                        ? 7U : 4U);
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__b)))
                        ? (0x800U | (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cyc) 
                                      << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cn)))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((6U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                              >> 0xbU)));
            } else if (vlTOPp->tb_top__DOT__u1__DOT__tb) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [0U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((6U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                              >> 0xbU)));
            }
            if ((1U & (~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__async_rst)))) {
                if ((0x20U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl))) {
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cyc 
                        = ((IData)(vlTOPp->tb_top__DOT__u1__DOT__j34)
                            ? 7U : 4U);
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__b 
                        = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__c 
                        = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cn 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__c)));
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__Vfuncout 
                        = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cn)) 
                            & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__b)))
                            ? (0x800U | (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cyc) 
                                          << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cn)))
                            : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__b) 
                                << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cn)));
                    vlTOPp->tb_top__DOT__u1__DOT__t 
                        = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__Vfuncout;
                    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                        = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] 
                        = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                                 >> 8U));
                } else if (vlTOPp->tb_top__DOT__u1__DOT__tb) {
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__b 
                        = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__c 
                        = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                        [2U];
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__cn 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__c)));
                    vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__Vfuncout 
                        = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__cn)) 
                            & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__b)))
                            ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__cn))
                            : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__b) 
                                << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__cn)));
                    vlTOPp->tb_top__DOT__u1__DOT__t 
                        = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__Vfuncout;
                    vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                        = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                    vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] 
                        = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                                 >> 8U));
                }
            }
            if (((IData)(vlTOPp->tb_top__DOT__u1__DOT__tb) 
                 & (~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__j12)))) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[1U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((5U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (2U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                              >> 0xaU)));
            }
            if ((((IData)(vlTOPp->tb_top__DOT__u1__DOT__tb) 
                  & (~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__j34))) 
                 & (~ (IData)(vlTOPp->tb_top__DOT__u1__DOT__async_rst)))) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((3U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (4U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                              >> 9U)));
            }
            if ((((IData)(vlTOPp->tb_top__DOT__u1__DOT__t114) 
                  | ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_skctl) 
                     >> 2U)) & (0xe4U > (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)))) {
                vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xfeU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | ((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                         [0U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                        | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xfdU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [1U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 1U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xfbU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [2U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 2U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xf7U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [3U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 3U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xefU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [4U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 4U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xdfU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [5U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 5U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0xbfU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [6U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 6U));
                vlTOPp->tb_top__DOT__u1__DOT__upd = 
                    ((0x7fU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd)) 
                     | (((vlTOPp->tb_top__DOT__u1__DOT__n_potx
                          [7U] < (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt)) 
                         | (0xe4U == (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_pot_cnt))) 
                        << 7U));
            }
        }
        vlTOPp->tb_top__DOT__u1__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                                              [2U]);
        if ((0U != vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
             [2U])) {
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                         [2U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u1__DOT__fire) {
            if (vlTOPp->tb_top__DOT__u1__DOT__j34) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [3U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((3U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (4U & ((0xfffffffcU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                              | (0x7ffffcU & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                                              >> 9U)))));
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__poly9 
                = vlTOPp->tb_top__DOT__u1__DOT__poly9;
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p17b 
                = (1U & vlTOPp->tb_top__DOT__u1__DOT__n_p17);
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__c 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                         [2U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                         >> 2U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__o)));
            vlTOPp->tb_top__DOT__u1__DOT__n_outp = 
                ((0xbU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__Vfuncout) 
                    << 2U));
            vlTOPp->tb_top__DOT__u1__DOT__n_fsmp = 
                ((0xeU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                 | (1U & ((~ ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl) 
                              >> 2U)) | (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp))));
        }
        vlTOPp->tb_top__DOT__u1__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                                              [3U]);
        if ((0U != vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
             [3U])) {
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                         [3U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u1__DOT__fire) {
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__poly9 
                = vlTOPp->tb_top__DOT__u1__DOT__poly9;
            if (vlTOPp->tb_top__DOT__u1__DOT__j34) {
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[2U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [2U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[2U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p17b 
                = (1U & vlTOPp->tb_top__DOT__u1__DOT__n_p17);
            vlTOPp->tb_top__DOT__u1__DOT__n_cnt[3U] 
                = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                            [3U]));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9));
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[3U] = 0U;
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__c 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                         [3U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                         >> 3U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__o)));
            vlTOPp->tb_top__DOT__u1__DOT__n_outp = 
                ((7U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__Vfuncout) 
                    << 3U));
            vlTOPp->tb_top__DOT__u1__DOT__n_fsmp = 
                ((0xdU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                 | (2U & (((~ ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_audctl) 
                               >> 1U)) << 1U) | (0xfffffffeU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp)))));
        }
        vlTOPp->tb_top__DOT__u1__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                                              [0U]);
        if ((0U != vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
             [0U])) {
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                         [0U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u1__DOT__fire) {
            if (vlTOPp->tb_top__DOT__u1__DOT__j12) {
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__b 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__c 
                    = vlTOPp->tb_top__DOT__u1__DOT__n_cnt
                    [1U];
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__cn 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__c)));
                vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__Vfuncout 
                    = (((0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__cn)) 
                        & (0U == (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__b)))
                        ? (0x900U | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__cn))
                        : (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__b) 
                            << 8U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__cn)));
                vlTOPp->tb_top__DOT__u1__DOT__t = vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__Vfuncout;
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[1U] 
                    = (0xffU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__t));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] 
                    = (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                             >> 8U));
                vlTOPp->tb_top__DOT__u1__DOT__arm = 
                    ((5U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                     | (2U & ((0xfffffffeU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__arm)) 
                              | (0x3ffffeU & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__t) 
                                              >> 0xaU)))));
            } else {
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__poly9 
                = vlTOPp->tb_top__DOT__u1__DOT__poly9;
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p17b 
                = (1U & vlTOPp->tb_top__DOT__u1__DOT__n_p17);
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__c 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                         [0U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__o 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__o)));
            vlTOPp->tb_top__DOT__u1__DOT__n_outp = 
                ((0xeU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp)) 
                 | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__Vfuncout));
        }
        vlTOPp->tb_top__DOT__u1__DOT__fire = (1U == 
                                              vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                                              [1U]);
        if ((0U != vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
             [1U])) {
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_bcnt
                         [1U] - (IData)(1U)));
        }
        if (vlTOPp->tb_top__DOT__u1__DOT__fire) {
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__poly9 
                = vlTOPp->tb_top__DOT__u1__DOT__poly9;
            if (vlTOPp->tb_top__DOT__u1__DOT__j12) {
                vlTOPp->tb_top__DOT__u1__DOT__n_cnt[0U] 
                    = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                                [0U]));
                vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[0U] = 0U;
            }
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p17b 
                = (1U & vlTOPp->tb_top__DOT__u1__DOT__n_p17);
            vlTOPp->tb_top__DOT__u1__DOT__n_cnt[1U] 
                = (0xffU & (~ vlTOPp->tb_top__DOT__u1__DOT__n_audf
                            [1U]));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p9b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p9));
            vlTOPp->tb_top__DOT__u1__DOT__n_bcnt[1U] = 0U;
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p5b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p5));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p4b 
                = (1U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_p4));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__c 
                = (7U & (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                         [1U] >> 5U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__o 
                = (1U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                         >> 1U));
            vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__Vfuncout 
                = (1U & ((1U & (((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__c) 
                                 >> 2U) | (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p5b)))
                          ? ((1U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__c))
                              ? (~ (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__o))
                              : ((2U & (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__c))
                                  ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p4b)
                                  : ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__poly9)
                                      ? (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p9b)
                                      : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p17b))))
                          : (IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__o)));
            vlTOPp->tb_top__DOT__u1__DOT__n_outp = 
                ((0xdU & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp)) 
                 | ((IData)(vlTOPp->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__Vfuncout) 
                    << 1U));
        }
        vlTOPp->tb_top__DOT__u1__DOT__n_oraw = ((0xfff0U 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_oraw)) 
                                                | ((1U 
                                                    & (((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                                                        ^ (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                                                       | (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                          [0U] 
                                                          >> 4U)))
                                                    ? 
                                                   (0xfU 
                                                    & vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                    [0U])
                                                    : 0U));
        vlTOPp->tb_top__DOT__u1__DOT__n_oraw = ((0xff0fU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                                                         >> 1U) 
                                                        | (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                           [1U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                     [1U])
                                                     : 0U) 
                                                   << 4U));
        vlTOPp->tb_top__DOT__u1__DOT__n_oraw = ((0xf0ffU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                                                         >> 2U) 
                                                        | (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                           [2U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                     [2U])
                                                     : 0U) 
                                                   << 8U));
        vlTOPp->tb_top__DOT__u1__DOT__n_oraw = ((0xfffU 
                                                 & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_oraw)) 
                                                | (((1U 
                                                     & ((((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_outp) 
                                                          ^ (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_fsmp)) 
                                                         >> 3U) 
                                                        | (vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                           [3U] 
                                                           >> 4U)))
                                                     ? 
                                                    (0xfU 
                                                     & vlTOPp->tb_top__DOT__u1__DOT__n_audc
                                                     [3U])
                                                     : 0U) 
                                                   << 0xcU));
        vlTOPp->tb_top__DOT__u1__DOT__n_allpot = ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_allpot) 
                                                  | (IData)(vlTOPp->tb_top__DOT__u1__DOT__upd));
        if ((0U != ((IData)(vlTOPp->tb_top__DOT__u1__DOT__arm) 
                    & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqen)))) {
            vlTOPp->tb_top__DOT__u1__DOT__n_irqst = 
                ((0xf8U & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqst)) 
                 | (7U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqst) 
                          | ((IData)(vlTOPp->tb_top__DOT__u1__DOT__arm) 
                             & (IData)(vlTOPp->tb_top__DOT__u1__DOT__n_irqen)))));
            vlTOPp->tb_top__DOT__u1__DOT__n_irq = 1U;
        }
    }
    __Vtemp75[1U] = ((0xffffe000U & ((IData)((((QData)((IData)(
                                                               (((IData)(vlTOPp->tb_top__DOT__u0__DOT__pot_cnt) 
                                                                 << 0x18U) 
                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                    [0U] 
                                                                    << 0x10U) 
                                                                   | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                       [1U] 
                                                                       << 8U) 
                                                                      | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                      [2U]))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                  [3U] 
                                                                  << 0x18U) 
                                                                 | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                     [4U] 
                                                                     << 0x10U) 
                                                                    | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                        [5U] 
                                                                        << 8U) 
                                                                       | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                       [6U]))))))) 
                                     << 0xdU)) | (IData)(
                                                         ((0x802ULL 
                                                           | ((QData)((IData)(
                                                                              vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                              [7U])) 
                                                              << 0x25U)) 
                                                          >> 0x20U)));
    __Vtemp75[2U] = ((0x1fffU & ((IData)((((QData)((IData)(
                                                           (((IData)(vlTOPp->tb_top__DOT__u0__DOT__pot_cnt) 
                                                             << 0x18U) 
                                                            | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                [0U] 
                                                                << 0x10U) 
                                                               | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                   [1U] 
                                                                   << 8U) 
                                                                  | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                  [2U]))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                              [3U] 
                                                              << 0x18U) 
                                                             | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                 [4U] 
                                                                 << 0x10U) 
                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                    [5U] 
                                                                    << 8U) 
                                                                   | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                   [6U]))))))) 
                                 >> 0x13U)) | (0xffffe000U 
                                               & ((IData)(
                                                          ((((QData)((IData)(
                                                                             (((IData)(vlTOPp->tb_top__DOT__u0__DOT__pot_cnt) 
                                                                               << 0x18U) 
                                                                              | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [0U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [1U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [2U]))))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [3U] 
                                                                                << 0x18U) 
                                                                               | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [4U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [5U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [6U])))))) 
                                                           >> 0x20U)) 
                                                  << 0xdU)));
    __Vtemp77[3U] = ((0xc0000000U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__p9) 
                                     << 0x1eU)) | (
                                                   (0xffffe000U 
                                                    & (vlTOPp->tb_top__DOT__u0__DOT__p17 
                                                       << 0xdU)) 
                                                   | (0x1fffU 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u0__DOT__pot_cnt) 
                                                                                << 0x18U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [0U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [1U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [2U]))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [3U] 
                                                                                << 0x18U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [4U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [5U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                                [6U])))))) 
                                                                  >> 0x20U)) 
                                                         >> 0x13U))));
    __Vtemp80[4U] = ((0xffff0000U & ((IData)((((QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                                   >> 3U)))) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                                      >> 3U)))) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(
                                                                     (((IData)(vlTOPp->tb_top__DOT__u0__DOT__audctl) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__irqen) 
                                                                             << 8U) 
                                                                            | (IData)(vlTOPp->tb_top__DOT__u0__DOT__irqst)))))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__clk28) 
                                                                           << 7U) 
                                                                          | (IData)(vlTOPp->tb_top__DOT__u0__DOT__clk114))))))))) 
                                     << 0x10U)) | (
                                                   (0xfffff000U 
                                                    & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__p4) 
                                                       << 0xcU)) 
                                                   | ((0xffffff80U 
                                                       & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__p5) 
                                                          << 7U)) 
                                                      | (0x3fffffffU 
                                                         & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__p9) 
                                                            >> 2U)))));
    __Vtemp80[5U] = ((0xffffU & ((IData)((((QData)((IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                               >> 3U)))) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                                  >> 3U)))) 
                                              << 0x3cU) 
                                             | (((QData)((IData)(
                                                                 (((IData)(vlTOPp->tb_top__DOT__u0__DOT__audctl) 
                                                                   << 0x18U) 
                                                                  | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl) 
                                                                      << 0x10U) 
                                                                     | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__irqen) 
                                                                         << 8U) 
                                                                        | (IData)(vlTOPp->tb_top__DOT__u0__DOT__irqst)))))) 
                                                 << 0x1cU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot) 
                                                                    << 0xcU) 
                                                                   | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__clk28) 
                                                                       << 7U) 
                                                                      | (IData)(vlTOPp->tb_top__DOT__u0__DOT__clk114))))))))) 
                                 >> 0x10U)) | (0xffff0000U 
                                               & ((IData)(
                                                          ((((QData)((IData)(
                                                                             (1U 
                                                                              & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                                                >> 3U)))) 
                                                             << 0x3dU) 
                                                            | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                                                >> 3U)))) 
                                                                << 0x3cU) 
                                                               | (((QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u0__DOT__audctl) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__irqen) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->tb_top__DOT__u0__DOT__irqst)))))) 
                                                                   << 0x1cU) 
                                                                  | (QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__clk28) 
                                                                                << 7U) 
                                                                                | (IData)(vlTOPp->tb_top__DOT__u0__DOT__clk114)))))))) 
                                                           >> 0x20U)) 
                                                  << 0x10U)));
    __Vtemp80[6U] = ((0xffffU & ((0xc000U & (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                             [3U] << 0xeU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                                   >> 3U)))) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                                      >> 3U)))) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(
                                                                     (((IData)(vlTOPp->tb_top__DOT__u0__DOT__audctl) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__skctl) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__irqen) 
                                                                             << 8U) 
                                                                            | (IData)(vlTOPp->tb_top__DOT__u0__DOT__irqst)))))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlTOPp->tb_top__DOT__u0__DOT__allpot) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlTOPp->tb_top__DOT__u0__DOT__clk28) 
                                                                           << 7U) 
                                                                          | (IData)(vlTOPp->tb_top__DOT__u0__DOT__clk114)))))))) 
                                             >> 0x20U)) 
                                    >> 0x10U))) | (0xffff0000U 
                                                   & ((0xfe000000U 
                                                       & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                                          [3U] 
                                                          << 0x19U)) 
                                                      | ((0xfffe0000U 
                                                          & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                             [3U] 
                                                             << 0x11U)) 
                                                         | (0xffff0000U 
                                                            & (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                               [3U] 
                                                               << 0xeU))))));
    __Vtemp80[7U] = ((0xffffU & ((0xc000U & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                             [2U] << 0xeU)) 
                                 | (0x3fffU & ((0x3800U 
                                                & (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                   [2U] 
                                                   << 0xbU)) 
                                               | ((0x400U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                      << 8U)) 
                                                  | ((0x200U 
                                                      & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                         << 7U)) 
                                                     | ((0x3ffeU 
                                                         & (vlTOPp->tb_top__DOT__u0__DOT__audf
                                                            [3U] 
                                                            << 1U)) 
                                                        | ((0x3fffU 
                                                            & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                                               [3U] 
                                                               >> 7U)) 
                                                           | ((0x3fffU 
                                                               & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                                  [3U] 
                                                                  >> 0xfU)) 
                                                              | (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                                 [3U] 
                                                                 >> 0x12U)))))))))) 
                     | (0xffff0000U & ((0xc0000000U 
                                        & (vlTOPp->tb_top__DOT__u0__DOT__audf
                                           [2U] << 0x1eU)) 
                                       | ((0xffc00000U 
                                           & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                              [2U] 
                                              << 0x16U)) 
                                          | (0xffff0000U 
                                             & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                [2U] 
                                                << 0xeU))))));
    __Vtemp80[8U] = ((0xffffU & ((0xff00U & ((0xf800U 
                                              & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                 [1U] 
                                                 << 0xbU)) 
                                             | (0xff00U 
                                                & (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                   [1U] 
                                                   << 8U)))) 
                                 | ((0x80U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                              << 6U)) 
                                    | ((0x40U & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                 << 5U)) 
                                       | ((0xffffU 
                                           & (vlTOPp->tb_top__DOT__u0__DOT__audf
                                              [2U] 
                                              >> 2U)) 
                                          | ((0xffffU 
                                              & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                                 [2U] 
                                                 >> 0xaU)) 
                                             | (0x3fffU 
                                                & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                   [2U] 
                                                   >> 0x12U)))))))) 
                     | (0xffff0000U & ((0xf8000000U 
                                        & (vlTOPp->tb_top__DOT__u0__DOT__audf
                                           [1U] << 0x1bU)) 
                                       | ((0xfff80000U 
                                           & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                              [1U] 
                                              << 0x13U)) 
                                          | (0xffff0000U 
                                             & ((vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                 [1U] 
                                                 << 0xbU) 
                                                | (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                   [1U] 
                                                   << 8U)))))));
    __Vtemp80[9U] = (0xffffU & ((0xff00U & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                            [0U] << 8U)) 
                                | (0xffU & ((0xe0U 
                                             & (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                [0U] 
                                                << 5U)) 
                                            | ((0x10U 
                                                & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__outp) 
                                                   << 4U)) 
                                               | ((8U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u0__DOT__fsmp) 
                                                      << 3U)) 
                                                  | ((0xffU 
                                                      & (vlTOPp->tb_top__DOT__u0__DOT__audf
                                                         [1U] 
                                                         >> 5U)) 
                                                     | ((0xffU 
                                                         & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                                            [1U] 
                                                            >> 0xdU)) 
                                                        | ((0xffU 
                                                            & (vlTOPp->tb_top__DOT__u0__DOT__cnt
                                                               [1U] 
                                                               >> 0x15U)) 
                                                           | (vlTOPp->tb_top__DOT__u0__DOT__bcnt
                                                              [1U] 
                                                              >> 0x18U))))))))));
    vlTOPp->dbg0[0U] = (0x200002U | ((0xffc00000U & 
                                      ((IData)((0x802ULL 
                                                | ((QData)((IData)(
                                                                   vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                   [7U])) 
                                                   << 0x25U))) 
                                       << 0x16U)) | 
                                     (((IData)(vlTOPp->out_raw0) 
                                       << 3U) | ((IData)(vlTOPp->tb_top__DOT__u0__DOT__irq_lvl) 
                                                 << 2U))));
    vlTOPp->dbg0[1U] = ((0x3fffffU & ((IData)((0x802ULL 
                                               | ((QData)((IData)(
                                                                  vlTOPp->tb_top__DOT__u0__DOT__potx
                                                                  [7U])) 
                                                  << 0x25U))) 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp75[1U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[2U] = ((0x3fffffU & (__Vtemp75[1U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp75[2U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[3U] = ((0x3fffffU & (__Vtemp75[2U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp77[3U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[4U] = ((0x3fffffU & (__Vtemp77[3U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[4U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[5U] = ((0x3fffffU & (__Vtemp80[4U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[5U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[6U] = ((0x3fffffU & (__Vtemp80[5U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[6U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[7U] = ((0x3fffffU & (__Vtemp80[6U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[7U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[8U] = ((0x3fffffU & (__Vtemp80[7U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[8U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[9U] = ((0x3fffffU & (__Vtemp80[8U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp80[9U] 
                                                      << 0x16U)));
    vlTOPp->dbg0[0xaU] = (0x3fffffU & ((0x3fc000U & 
                                        (vlTOPp->tb_top__DOT__u0__DOT__audf
                                         [0U] << 0xeU)) 
                                       | ((0x3fffc0U 
                                           & (vlTOPp->tb_top__DOT__u0__DOT__audc
                                              [0U] 
                                              << 6U)) 
                                          | (__Vtemp80[9U] 
                                             >> 0xaU))));
    __Vtemp92[1U] = ((0xffffe000U & ((IData)((((QData)((IData)(
                                                               (((IData)(vlTOPp->tb_top__DOT__u1__DOT__pot_cnt) 
                                                                 << 0x18U) 
                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                    [0U] 
                                                                    << 0x10U) 
                                                                   | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                       [1U] 
                                                                       << 8U) 
                                                                      | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                      [2U]))))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                  [3U] 
                                                                  << 0x18U) 
                                                                 | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                     [4U] 
                                                                     << 0x10U) 
                                                                    | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                        [5U] 
                                                                        << 8U) 
                                                                       | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                       [6U]))))))) 
                                     << 0xdU)) | (IData)(
                                                         ((0x802ULL 
                                                           | ((QData)((IData)(
                                                                              vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                              [7U])) 
                                                              << 0x25U)) 
                                                          >> 0x20U)));
    __Vtemp92[2U] = ((0x1fffU & ((IData)((((QData)((IData)(
                                                           (((IData)(vlTOPp->tb_top__DOT__u1__DOT__pot_cnt) 
                                                             << 0x18U) 
                                                            | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                [0U] 
                                                                << 0x10U) 
                                                               | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                   [1U] 
                                                                   << 8U) 
                                                                  | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                  [2U]))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                              [3U] 
                                                              << 0x18U) 
                                                             | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                 [4U] 
                                                                 << 0x10U) 
                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                    [5U] 
                                                                    << 8U) 
                                                                   | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                   [6U]))))))) 
                                 >> 0x13U)) | (0xffffe000U 
                                               & ((IData)(
                                                          ((((QData)((IData)(
                                                                             (((IData)(vlTOPp->tb_top__DOT__u1__DOT__pot_cnt) 
                                                                               << 0x18U) 
                                                                              | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [0U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [1U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [2U]))))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [3U] 
                                                                                << 0x18U) 
                                                                               | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [4U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [5U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [6U])))))) 
                                                           >> 0x20U)) 
                                                  << 0xdU)));
    __Vtemp94[3U] = ((0xc0000000U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__p9) 
                                     << 0x1eU)) | (
                                                   (0xffffe000U 
                                                    & (vlTOPp->tb_top__DOT__u1__DOT__p17 
                                                       << 0xdU)) 
                                                   | (0x1fffU 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u1__DOT__pot_cnt) 
                                                                                << 0x18U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [0U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [1U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [2U]))))) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [3U] 
                                                                                << 0x18U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [4U] 
                                                                                << 0x10U) 
                                                                                | ((vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [5U] 
                                                                                << 8U) 
                                                                                | vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                                [6U])))))) 
                                                                  >> 0x20U)) 
                                                         >> 0x13U))));
    __Vtemp97[4U] = ((0xffff0000U & ((IData)((((QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                                   >> 3U)))) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                                      >> 3U)))) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(
                                                                     (((IData)(vlTOPp->tb_top__DOT__u1__DOT__audctl) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__irqen) 
                                                                             << 8U) 
                                                                            | (IData)(vlTOPp->tb_top__DOT__u1__DOT__irqst)))))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__clk28) 
                                                                           << 7U) 
                                                                          | (IData)(vlTOPp->tb_top__DOT__u1__DOT__clk114))))))))) 
                                     << 0x10U)) | (
                                                   (0xfffff000U 
                                                    & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__p4) 
                                                       << 0xcU)) 
                                                   | ((0xffffff80U 
                                                       & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__p5) 
                                                          << 7U)) 
                                                      | (0x3fffffffU 
                                                         & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__p9) 
                                                            >> 2U)))));
    __Vtemp97[5U] = ((0xffffU & ((IData)((((QData)((IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                               >> 3U)))) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                                  >> 3U)))) 
                                              << 0x3cU) 
                                             | (((QData)((IData)(
                                                                 (((IData)(vlTOPp->tb_top__DOT__u1__DOT__audctl) 
                                                                   << 0x18U) 
                                                                  | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl) 
                                                                      << 0x10U) 
                                                                     | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__irqen) 
                                                                         << 8U) 
                                                                        | (IData)(vlTOPp->tb_top__DOT__u1__DOT__irqst)))))) 
                                                 << 0x1cU) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot) 
                                                                    << 0xcU) 
                                                                   | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__clk28) 
                                                                       << 7U) 
                                                                      | (IData)(vlTOPp->tb_top__DOT__u1__DOT__clk114))))))))) 
                                 >> 0x10U)) | (0xffff0000U 
                                               & ((IData)(
                                                          ((((QData)((IData)(
                                                                             (1U 
                                                                              & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                                                >> 3U)))) 
                                                             << 0x3dU) 
                                                            | (((QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                                                >> 3U)))) 
                                                                << 0x3cU) 
                                                               | (((QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u1__DOT__audctl) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__irqen) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->tb_top__DOT__u1__DOT__irqst)))))) 
                                                                   << 0x1cU) 
                                                                  | (QData)((IData)(
                                                                                (((IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__clk28) 
                                                                                << 7U) 
                                                                                | (IData)(vlTOPp->tb_top__DOT__u1__DOT__clk114)))))))) 
                                                           >> 0x20U)) 
                                                  << 0x10U)));
    __Vtemp97[6U] = ((0xffffU & ((0xc000U & (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                             [3U] << 0xeU)) 
                                 | ((IData)(((((QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                                   >> 3U)))) 
                                               << 0x3dU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                                      >> 3U)))) 
                                                  << 0x3cU) 
                                                 | (((QData)((IData)(
                                                                     (((IData)(vlTOPp->tb_top__DOT__u1__DOT__audctl) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__skctl) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__irqen) 
                                                                             << 8U) 
                                                                            | (IData)(vlTOPp->tb_top__DOT__u1__DOT__irqst)))))) 
                                                     << 0x1cU) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlTOPp->tb_top__DOT__u1__DOT__allpot) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlTOPp->tb_top__DOT__u1__DOT__clk28) 
                                                                           << 7U) 
                                                                          | (IData)(vlTOPp->tb_top__DOT__u1__DOT__clk114)))))))) 
                                             >> 0x20U)) 
                                    >> 0x10U))) | (0xffff0000U 
                                                   & ((0xfe000000U 
                                                       & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                                          [3U] 
                                                          << 0x19U)) 
                                                      | ((0xfffe0000U 
                                                          & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                             [3U] 
                                                             << 0x11U)) 
                                                         | (0xffff0000U 
                                                            & (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                               [3U] 
                                                               << 0xeU))))));
    __Vtemp97[7U] = ((0xffffU & ((0xc000U & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                             [2U] << 0xeU)) 
                                 | (0x3fffU & ((0x3800U 
                                                & (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                   [2U] 
                                                   << 0xbU)) 
                                               | ((0x400U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                      << 8U)) 
                                                  | ((0x200U 
                                                      & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                         << 7U)) 
                                                     | ((0x3ffeU 
                                                         & (vlTOPp->tb_top__DOT__u1__DOT__audf
                                                            [3U] 
                                                            << 1U)) 
                                                        | ((0x3fffU 
                                                            & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                                               [3U] 
                                                               >> 7U)) 
                                                           | ((0x3fffU 
                                                               & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                                  [3U] 
                                                                  >> 0xfU)) 
                                                              | (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                                 [3U] 
                                                                 >> 0x12U)))))))))) 
                     | (0xffff0000U & ((0xc0000000U 
                                        & (vlTOPp->tb_top__DOT__u1__DOT__audf
                                           [2U] << 0x1eU)) 
                                       | ((0xffc00000U 
                                           & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                              [2U] 
                                              << 0x16U)) 
                                          | (0xffff0000U 
                                             & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                [2U] 
                                                << 0xeU))))));
    __Vtemp97[8U] = ((0xffffU & ((0xff00U & ((0xf800U 
                                              & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                 [1U] 
                                                 << 0xbU)) 
                                             | (0xff00U 
                                                & (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                   [1U] 
                                                   << 8U)))) 
                                 | ((0x80U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                              << 6U)) 
                                    | ((0x40U & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                 << 5U)) 
                                       | ((0xffffU 
                                           & (vlTOPp->tb_top__DOT__u1__DOT__audf
                                              [2U] 
                                              >> 2U)) 
                                          | ((0xffffU 
                                              & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                                 [2U] 
                                                 >> 0xaU)) 
                                             | (0x3fffU 
                                                & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                   [2U] 
                                                   >> 0x12U)))))))) 
                     | (0xffff0000U & ((0xf8000000U 
                                        & (vlTOPp->tb_top__DOT__u1__DOT__audf
                                           [1U] << 0x1bU)) 
                                       | ((0xfff80000U 
                                           & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                              [1U] 
                                              << 0x13U)) 
                                          | (0xffff0000U 
                                             & ((vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                 [1U] 
                                                 << 0xbU) 
                                                | (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                   [1U] 
                                                   << 8U)))))));
    __Vtemp97[9U] = (0xffffU & ((0xff00U & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                            [0U] << 8U)) 
                                | (0xffU & ((0xe0U 
                                             & (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                [0U] 
                                                << 5U)) 
                                            | ((0x10U 
                                                & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__outp) 
                                                   << 4U)) 
                                               | ((8U 
                                                   & ((IData)(vlTOPp->tb_top__DOT__u1__DOT__fsmp) 
                                                      << 3U)) 
                                                  | ((0xffU 
                                                      & (vlTOPp->tb_top__DOT__u1__DOT__audf
                                                         [1U] 
                                                         >> 5U)) 
                                                     | ((0xffU 
                                                         & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                                            [1U] 
                                                            >> 0xdU)) 
                                                        | ((0xffU 
                                                            & (vlTOPp->tb_top__DOT__u1__DOT__cnt
                                                               [1U] 
                                                               >> 0x15U)) 
                                                           | (vlTOPp->tb_top__DOT__u1__DOT__bcnt
                                                              [1U] 
                                                              >> 0x18U))))))))));
    vlTOPp->dbg1[0U] = (0x200002U | ((0xffc00000U & 
                                      ((IData)((0x802ULL 
                                                | ((QData)((IData)(
                                                                   vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                   [7U])) 
                                                   << 0x25U))) 
                                       << 0x16U)) | 
                                     (((IData)(vlTOPp->out_raw1) 
                                       << 3U) | ((IData)(vlTOPp->tb_top__DOT__u1__DOT__irq_lvl) 
                                                 << 2U))));
    vlTOPp->dbg1[1U] = ((0x3fffffU & ((IData)((0x802ULL 
                                               | ((QData)((IData)(
                                                                  vlTOPp->tb_top__DOT__u1__DOT__potx
                                                                  [7U])) 
                                                  << 0x25U))) 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp92[1U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[2U] = ((0x3fffffU & (__Vtemp92[1U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp92[2U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[3U] = ((0x3fffffU & (__Vtemp92[2U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp94[3U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[4U] = ((0x3fffffU & (__Vtemp94[3U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[4U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[5U] = ((0x3fffffU & (__Vtemp97[4U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[5U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[6U] = ((0x3fffffU & (__Vtemp97[5U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[6U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[7U] = ((0x3fffffU & (__Vtemp97[6U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[7U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[8U] = ((0x3fffffU & (__Vtemp97[7U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[8U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[9U] = ((0x3fffffU & (__Vtemp97[8U] 
                                      >> 0xaU)) | (0xffc00000U 
                                                   & (__Vtemp97[9U] 
                                                      << 0x16U)));
    vlTOPp->dbg1[0xaU] = (0x3fffffU & ((0x3fc000U & 
                                        (vlTOPp->tb_top__DOT__u1__DOT__audf
                                         [0U] << 0xeU)) 
                                       | ((0x3fffc0U 
                                           & (vlTOPp->tb_top__DOT__u1__DOT__audc
                                              [0U] 
                                              << 6U)) 
                                          | (__Vtemp97[9U] 
                                             >> 0xaU))));
}

void Vtb_top::_eval_initial(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval_initial\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtb_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::final\n"); );
    // Variables
    Vtb_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtb_top::_eval_settle(Vtb_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_eval_settle\n"); );
    Vtb_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vtb_top::_ctor_var_reset(Vtb_top* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clk = 0;
    self->reset_n = 0;
    self->ce = 0;
    self->wr = 0;
    self->rd = 0;
    self->addr0 = 0;
    self->addr1 = 0;
    self->din0 = 0;
    self->din1 = 0;
    self->pot_val0 = 0;
    self->pot_val1 = 0;
    self->allpot_ext0 = 0;
    self->allpot_ext1 = 0;
    self->dout0 = 0;
    self->dout1 = 0;
    self->irq_n = 0;
    self->out_raw0 = 0;
    self->out_raw1 = 0;
    self->pot_count0 = 0;
    self->pot_count1 = 0;
    VL_ZERO_RESET_W(342, self->dbg0);
    VL_ZERO_RESET_W(342, self->dbg1);
    self->cfg = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__audf[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__audc[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__cnt[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__bcnt[__Vi0] = 0;
    }
    self->tb_top__DOT__u0__DOT__outp = 0;
    self->tb_top__DOT__u0__DOT__fsmp = 0;
    self->tb_top__DOT__u0__DOT__audctl = 0;
    self->tb_top__DOT__u0__DOT__skctl = 0;
    self->tb_top__DOT__u0__DOT__irqen = 0;
    self->tb_top__DOT__u0__DOT__irqst = 0;
    self->tb_top__DOT__u0__DOT__allpot = 0;
    self->tb_top__DOT__u0__DOT__clk28 = 0;
    self->tb_top__DOT__u0__DOT__clk114 = 0;
    self->tb_top__DOT__u0__DOT__p4 = 0;
    self->tb_top__DOT__u0__DOT__p5 = 0;
    self->tb_top__DOT__u0__DOT__p9 = 0;
    self->tb_top__DOT__u0__DOT__p17 = 0;
    self->tb_top__DOT__u0__DOT__pot_cnt = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__potx[__Vi0] = 0;
    }
    self->tb_top__DOT__u0__DOT__oraw = 0;
    self->tb_top__DOT__u0__DOT__irq_lvl = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__n_audf[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__n_audc[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__n_cnt[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__n_bcnt[__Vi0] = 0;
    }
    self->tb_top__DOT__u0__DOT__n_outp = 0;
    self->tb_top__DOT__u0__DOT__n_fsmp = 0;
    self->tb_top__DOT__u0__DOT__n_audctl = 0;
    self->tb_top__DOT__u0__DOT__n_skctl = 0;
    self->tb_top__DOT__u0__DOT__n_irqen = 0;
    self->tb_top__DOT__u0__DOT__n_irqst = 0;
    self->tb_top__DOT__u0__DOT__n_allpot = 0;
    self->tb_top__DOT__u0__DOT__n_clk28 = 0;
    self->tb_top__DOT__u0__DOT__n_clk114 = 0;
    self->tb_top__DOT__u0__DOT__n_p4 = 0;
    self->tb_top__DOT__u0__DOT__n_p5 = 0;
    self->tb_top__DOT__u0__DOT__n_p9 = 0;
    self->tb_top__DOT__u0__DOT__n_p17 = 0;
    self->tb_top__DOT__u0__DOT__n_pot_cnt = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->tb_top__DOT__u0__DOT__n_potx[__Vi0] = 0;
    }
    self->tb_top__DOT__u0__DOT__n_oraw = 0;
    self->tb_top__DOT__u0__DOT__n_irq = 0;
    self->tb_top__DOT__u0__DOT__t = 0;
    self->tb_top__DOT__u0__DOT__upd = 0;
    self->tb_top__DOT__u0__DOT__arm = 0;
    self->tb_top__DOT__u0__DOT__run = 0;
    self->tb_top__DOT__u0__DOT__t28 = 0;
    self->tb_top__DOT__u0__DOT__t114 = 0;
    self->tb_top__DOT__u0__DOT__tb = 0;
    self->tb_top__DOT__u0__DOT__async_rst = 0;
    self->tb_top__DOT__u0__DOT__j12 = 0;
    self->tb_top__DOT__u0__DOT__j34 = 0;
    self->tb_top__DOT__u0__DOT__fire = 0;
    self->tb_top__DOT__u0__DOT__poly9 = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__audf[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__audc[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__cnt[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__bcnt[__Vi0] = 0;
    }
    self->tb_top__DOT__u1__DOT__outp = 0;
    self->tb_top__DOT__u1__DOT__fsmp = 0;
    self->tb_top__DOT__u1__DOT__audctl = 0;
    self->tb_top__DOT__u1__DOT__skctl = 0;
    self->tb_top__DOT__u1__DOT__irqen = 0;
    self->tb_top__DOT__u1__DOT__irqst = 0;
    self->tb_top__DOT__u1__DOT__allpot = 0;
    self->tb_top__DOT__u1__DOT__clk28 = 0;
    self->tb_top__DOT__u1__DOT__clk114 = 0;
    self->tb_top__DOT__u1__DOT__p4 = 0;
    self->tb_top__DOT__u1__DOT__p5 = 0;
    self->tb_top__DOT__u1__DOT__p9 = 0;
    self->tb_top__DOT__u1__DOT__p17 = 0;
    self->tb_top__DOT__u1__DOT__pot_cnt = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__potx[__Vi0] = 0;
    }
    self->tb_top__DOT__u1__DOT__oraw = 0;
    self->tb_top__DOT__u1__DOT__irq_lvl = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__n_audf[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__n_audc[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__n_cnt[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__n_bcnt[__Vi0] = 0;
    }
    self->tb_top__DOT__u1__DOT__n_outp = 0;
    self->tb_top__DOT__u1__DOT__n_fsmp = 0;
    self->tb_top__DOT__u1__DOT__n_audctl = 0;
    self->tb_top__DOT__u1__DOT__n_skctl = 0;
    self->tb_top__DOT__u1__DOT__n_irqen = 0;
    self->tb_top__DOT__u1__DOT__n_irqst = 0;
    self->tb_top__DOT__u1__DOT__n_allpot = 0;
    self->tb_top__DOT__u1__DOT__n_clk28 = 0;
    self->tb_top__DOT__u1__DOT__n_clk114 = 0;
    self->tb_top__DOT__u1__DOT__n_p4 = 0;
    self->tb_top__DOT__u1__DOT__n_p5 = 0;
    self->tb_top__DOT__u1__DOT__n_p9 = 0;
    self->tb_top__DOT__u1__DOT__n_p17 = 0;
    self->tb_top__DOT__u1__DOT__n_pot_cnt = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->tb_top__DOT__u1__DOT__n_potx[__Vi0] = 0;
    }
    self->tb_top__DOT__u1__DOT__n_oraw = 0;
    self->tb_top__DOT__u1__DOT__n_irq = 0;
    self->tb_top__DOT__u1__DOT__t = 0;
    self->tb_top__DOT__u1__DOT__upd = 0;
    self->tb_top__DOT__u1__DOT__arm = 0;
    self->tb_top__DOT__u1__DOT__run = 0;
    self->tb_top__DOT__u1__DOT__t28 = 0;
    self->tb_top__DOT__u1__DOT__t114 = 0;
    self->tb_top__DOT__u1__DOT__tb = 0;
    self->tb_top__DOT__u1__DOT__async_rst = 0;
    self->tb_top__DOT__u1__DOT__j12 = 0;
    self->tb_top__DOT__u1__DOT__j34 = 0;
    self->tb_top__DOT__u1__DOT__fire = 0;
    self->tb_top__DOT__u1__DOT__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cyc = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__1__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__2__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cyc = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__3__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__4__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__5__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__6__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__7__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__o = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p4b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p5b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p9b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__p17b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__8__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__o = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p4b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p5b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p9b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__p17b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__9__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_inc__10__cn = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__o = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p4b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p5b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p9b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__p17b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__11__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__o = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__c = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p4b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p5b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p9b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__p17b = 0;
    self->__Vfunc_tb_top__DOT__u0__DOT__f_proc__12__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cyc = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__14__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__15__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cyc = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__16__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__17__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__18__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__19__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__20__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__o = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p4b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p5b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p9b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__p17b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__21__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__o = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p4b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p5b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p9b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__p17b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__22__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_inc__23__cn = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__o = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p4b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p5b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p9b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__p17b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__24__poly9 = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__Vfuncout = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__o = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__c = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p4b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p5b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p9b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__p17b = 0;
    self->__Vfunc_tb_top__DOT__u1__DOT__f_proc__25__poly9 = 0;
}
