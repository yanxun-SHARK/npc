#include <cstdint>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "autoconf.h"
#include "common.h"

#define PMEM_SIZE 0x100000
void log_mtrace(paddr_t addr, int len, word_t data);
uint8_t pmem[PMEM_SIZE];

extern "C" size_t pmem_load(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f) {
        memset(pmem, 0, sizeof(pmem));
        size_t n = fread(pmem, 1, sizeof(pmem), f);
        printf("[pmem] Loaded %zu bytes from %s\n", n, filename);
        fclose(f);
        return n;
    } else {
        printf("[pmem] ERROR: Cannot open %s\n", filename);
        return 0;
    }
    
}

extern "C" int pmem_read(int raddr) {
    
    if (raddr == 0x10000004) {
        time_t timep;
        time(&timep);
        return timep;
    }else {
        uint32_t a = (uint32_t)(raddr & ~0x3u) & (PMEM_SIZE - 1);
        return (int)(pmem[a] | (pmem[a+1] << 8) | (pmem[a+2] << 16) | (pmem[a+3] << 24));
    }
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    if (waddr == 0x10000000) { 
        putchar(wdata & 0xFF);
        return;
    }
    IFDEF(CONFIG_MTRACE,log_mtrace(waddr, 4, wdata));
    uint32_t a = (uint32_t)(waddr & ~0x3u) & (PMEM_SIZE - 1);
    if (wmask & 0x1) pmem[a]   = (uint8_t)(wdata);
    if (wmask & 0x2) pmem[a+1] = (uint8_t)(wdata >> 8);
    if (wmask & 0x4) pmem[a+2] = (uint8_t)(wdata >> 16);
    if (wmask & 0x8) pmem[a+3] = (uint8_t)(wdata >> 24);
}
