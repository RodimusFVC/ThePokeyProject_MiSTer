# POKEY cycle-exact rig.  All paths relative to this Makefile.
P      := $(abspath ..)
CXX    := g++
CXXSTD := -std=c++17
REFINC := -I$(P)/ref/shim -I$(P)/ref/mame_0289 -I$(P)/ref -I$(P)/verilator
REFCXX := $(CXXSTD) -O2 -Wall -Werror $(REFINC)
OBJ    := obj
PRISTINE_MD5 := cb6b2b3aa94d55c9632efc0ba3a115da

REF_SRCS := $(P)/ref/mame_0289/pokey.cpp $(P)/ref/pokey_ref.cpp
REF_HDRS := $(P)/ref/mame_0289/pokey.h $(P)/ref/pokey_ref.h $(wildcard $(P)/ref/shim/*.h) pokey_state.h

.PHONY: all md5 lfsr clean
all: lfsr_test mame2ptr

pokey_state.h $(P)/rtl/pokey_cx_dbg.svh: $(P)/tools/gen_state.py
	python3 $(P)/tools/gen_state.py

md5:
	@echo "$(PRISTINE_MD5)  $(P)/ref/mame_0289/pokey.cpp" | md5sum -c -

lfsr_test: lfsr_test.cpp $(REF_SRCS) $(REF_HDRS) | md5
	$(CXX) $(REFCXX) -o $@ lfsr_test.cpp $(REF_SRCS)

lfsr: lfsr_test
	./lfsr_test

mame2ptr: mame2ptr.cpp $(REF_SRCS) $(REF_HDRS) | md5
	$(CXX) $(REFCXX) -o $@ mame2ptr.cpp $(REF_SRCS)

# ---------------------------------------------------------------- Verilator lockstep rig
# slot configs (MAME machine configs): std = centiped/ccastles/directed, war = warlords pots, mil = milliped family
CFG_std := -GS0_POT_CB=0 -GS0_ALLPOT_CB=0 -GS1_POT_CB=0 -GS1_ALLPOT_CB=1
CFG_war := -GS0_POT_CB=15 -GS0_ALLPOT_CB=0 -GS1_POT_CB=0 -GS1_ALLPOT_CB=0
CFG_mil := -GS0_POT_CB=0 -GS0_ALLPOT_CB=1 -GS1_POT_CB=0 -GS1_ALLPOT_CB=1
RTL     := $(P)/rtl/pokey_cx.sv
VFLAGS  := -cc -O3 --x-assign fast --x-initial fast -Wall -Wno-fatal -DPOKEY_DBG -I$(P)/rtl -I$(P)/verilator \
           --top-module tb_top -CFLAGS "$(CXXSTD) -O2 $(REFINC)"
TB_SRCS := $(abspath tb_pokey.cpp) $(abspath $(P)/ref/mame_0289/pokey.cpp) $(abspath $(P)/ref/pokey_ref.cpp)

# explicit targets only: a pattern rule tb_% would also match tb_top.sv
TB_CFGS := std war mil
$(addprefix tb_,$(TB_CFGS)): tb_%: tb_pokey.cpp tb_top.sv $(RTL) $(P)/rtl/pokey_cx_dbg.svh $(REF_SRCS) $(REF_HDRS) | md5
	rm -rf obj_$*
	verilator $(VFLAGS) $(CFG_$*) $(EXTRA_VFLAGS) --Mdir obj_$* --exe tb_top.sv $(RTL) $(TB_SRCS) -o ../tb_$* > obj_$*.log 2>&1 || (cat obj_$*.log; false)
	$(MAKE) -s -C obj_$* -f Vtb_top.mk -j8 > /dev/null

rig: tb_std tb_war tb_mil

# glue builds (old port list, rtl/pokey_glue.sv): std = 2 plain chips, war = comparator pots on slot 0
CFG_glue_std := -GS0_POT_CB=0 -GS0_ALLPOT_CB=0 -GS1_POT_CB=0 -GS1_ALLPOT_CB=0
CFG_glue_war := -GS0_POT_CB=15 -GS0_ALLPOT_CB=0 -GS1_POT_CB=0 -GS1_ALLPOT_CB=0
GLUE_CFGS := glue_std glue_war
$(addprefix tb_,$(GLUE_CFGS)): tb_%: tb_pokey.cpp tb_top.sv tb_top_glue.svh $(RTL) $(P)/rtl/pokey_glue.sv $(P)/rtl/pokey_cx_dbg.svh $(REF_SRCS) $(REF_HDRS) | md5
	rm -rf obj_$*
	verilator $(VFLAGS) -DGLUE $(CFG_$*) --Mdir obj_$* --exe tb_top.sv $(RTL) $(P)/rtl/pokey_glue.sv $(TB_SRCS) -o ../tb_$* > obj_$*.log 2>&1 || (cat obj_$*.log; false)
	$(MAKE) -s -C obj_$* -f Vtb_top.mk -j8 > /dev/null

glue: tb_glue_std tb_glue_war

# M12 control: old Mark Watson RTL (read-only, from the Centipede core) through an out_raw-only adapter
OLD_DIR := /Work/Projects/Arcade-Centipede_MiSTer/rtl/sound/pokey
OLD_SRC := $(wildcard $(OLD_DIR)/*.v)
OLD_CFGS := old_std old_war
CFG_old_std := $(CFG_glue_std)
CFG_old_war := $(CFG_glue_war)
$(addprefix tb_,$(OLD_CFGS)): tb_%: tb_pokey.cpp tb_top.sv tb_top_old.svh pokey_dbg_pos.svh $(OLD_SRC) $(REF_SRCS) $(REF_HDRS) | md5
	rm -rf obj_$*
	verilator $(VFLAGS) -Wno-lint -Wno-style -Wno-COMBDLY -DOLDRTL $(CFG_$*) --Mdir obj_$* --exe tb_top.sv $(OLD_SRC) $(TB_SRCS) -o ../tb_$* > obj_$*.log 2>&1 || (cat obj_$*.log; false)
	$(MAKE) -s -C obj_$* -f Vtb_top.mk -j8 > /dev/null

old: tb_old_std tb_old_war

clean:
	rm -rf obj_* lfsr_test mame2ptr tb_std tb_war tb_mil tb_glue_* tb_old_* *.log
