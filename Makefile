
.PHONY: all clean sim run

MODULE = $(firstword $(notdir $(VSRC:.v=)))
TARGET = V$(MODULE)
CSRC_DIR = csrc
VSRC_DIR = vsrc
CSRC  := $(wildcard $(CSRC_DIR)/*.cpp)
VSRC := $(wildcard $(VSRC_DIR)/*.v)
TRASH = obj_dir/ netlist/ icarus/

test:
	cat $(TARGET)
all:sim run
	
sim:$(VSRC) $(CSRC) 
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -j 8 -Wall --trace  $(VSRC) $(CSRC) 
run:
	obj_dir/$(TARGET)
	gtkwave wave.vcd

clean:
	rm -rf $(TRASH)
include ../Makefile
