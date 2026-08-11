#include <stdio.h>
#include "common.h"
#include <assert.h>
#include <dlfcn.h>
#include "autoconf.h"
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
extern "C" int read_reg(int idx);
extern "C" int read_pc();
extern int NPC_state;
extern uint8_t pmem[];
enum {DIFFTEST_TO_DUT,DIFFTEST_TO_REF};

void init_difftest(long img_size, int port) {

  void *handle;
  handle = dlopen("../nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (decltype(ref_difftest_memcpy))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (decltype(ref_difftest_regcpy))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (decltype(ref_difftest_exec))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (decltype(ref_difftest_raise_intr))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) =(void(*)(int)) dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", "../nemu/build/riscv32-nemu-interpreter-so");

  ref_difftest_init(port);
  ref_difftest_memcpy(CONFIG_MBASE, pmem, img_size, DIFFTEST_TO_REF);
  uint32_t reg_buf[33];
  for (int i = 0; i < 32; i++) reg_buf[i] = (uint32_t)read_reg(i);
  reg_buf[32] = (uint32_t)read_pc();
  ref_difftest_regcpy(reg_buf, DIFFTEST_TO_REF);
}

void difftest_step() {
  uint32_t ref_r[33];
  ref_difftest_exec(1);
  ref_difftest_regcpy(ref_r, DIFFTEST_TO_DUT);
  uint32_t val_reg[33];
  uint32_t val_pc;
  val_pc = read_pc();
  for (int i = 0 ; i < 32 ; i++) {
    val_reg[i] = read_reg(i);
    if (val_reg[i] != ref_r[i]) {
      panic("can not catch up with 0x%08x : REF = 0x%08x 0x%08x : DUT = 0x%08x ,",ref_r[32], ref_r[i],val_pc, val_reg[i]);
    }
  }
  
  if (val_pc !=ref_r[32]) {
    panic("can not catch up with ref.pc = 0x%08x at pc = 0x%08x", ref_r[32], val_pc);
  }
  ref_difftest_memcpy(CONFIG_MBASE, pmem, 0x100000, DIFFTEST_TO_REF);
}
