
.PHONY: all clean sim run

CSRC_DIR = csrc
VSRC_DIR = vsrc
CSRC := $(wildcard $(CSRC_DIR)/*.cpp) $(wildcard $(CSRC_DIR)/trace/*.cpp)  $(wildcard $(CSRC_DIR)/difftest/*.cpp)
VSRC := $(VSRC_DIR)/top.v $(filter-out $(VSRC_DIR)/top.v,$(wildcard $(VSRC_DIR)/*.v))


MODULE = $(firstword $(notdir $(VSRC:.v=)))
TARGET = V$(MODULE)
TRASH = obj_dir/ netlist/ icarus/

CAPSTONE_DIR = ../nemu/tools/capstone
CFLAGS += -I$(CAPSTONE_DIR)/repo/include
LDFLAGS += -L$(CAPSTONE_DIR)/repo -lcapstone -Wl,-rpath,$(CAPSTONE_DIR)/repo


test:
	cat $(TARGET)

all: sim run
	
sim: $(VSRC) $(CSRC) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 8 -Wall -Wno-fatal \
	-LDFLAGS "-lreadline -ldl" \
	-CFLAGS "-I../../nemu/tools/capstone/repo/include" \
	-CFLAGS "-I../csrc" \
	-CFLAGS "-I../obj_dir" \
	-CFLAGS "-O3" \
	-MAKEFLAGS "OPT_FAST=-O3" \
	-MAKEFLAGS "OPT_GLOBAL=-O3" \
	$(VSRC) $(CSRC)

run: sim
	obj_dir/$(TARGET) $(IMG)
	
wave:$(VSRC) $(CSRC) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 8 -Wall --trace-vcd -Wno-fatal \
	-LDFLAGS "-lreadline -ldl" \
	-CFLAGS "-I../../nemu/tools/capstone/repo/include" \
	-CFLAGS "-I../csrc" \
	-CFLAGS "-I../obj_dir" \
	$(VSRC) $(CSRC)

	gtkwave wave.vcd

clean:
	rm -rf $(TRASH)
	rm -rf *.vcd
	rm -rf *.view
include ../Makefile
