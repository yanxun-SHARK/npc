
.PHONY: all clean sim run

CSRC_DIR = csrc
VSRC_DIR = vsrc
CSRC  := $(wildcard $(CSRC_DIR)/*.cpp)
VSRC := $(wildcard $(VSRC_DIR)/*.v)

MODULE = $(firstword $(notdir $(VSRC:.v=)))
TARGET = V$(MODULE)
TRASH = obj_dir/ netlist/ icarus/

test:
	cat $(TARGET)

all: sim run
	
sim: $(VSRC) $(CSRC) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 8 -Wall -Wno-fatal $(VSRC) $(CSRC) 

run: sim
	obj_dir/$(TARGET) $(IMG)
	gtkwave wave.vcd

clean:
	rm -rf $(TRASH)
include ../Makefile
