#ifndef __DISASM_H__
#define __DISASM_H__

#include <dlfcn.h>
#include <capstone/capstone.h>
#include "common.h"

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void init_disasm();
#endif