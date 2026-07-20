#include <cstdint>
#include <cstdio>
#include <cstring>

#define PMEM_SIZE 0x100000

static uint8_t pmem[PMEM_SIZE];

extern "C" void pmem_load(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f) {
        memset(pmem, 0, sizeof(pmem));
        size_t n = fread(pmem, 1, sizeof(pmem), f);
        printf("[pmem] Loaded %zu bytes from %s\n", n, filename);
        fclose(f);
    } else {
        printf("[pmem] ERROR: Cannot open %s\n", filename);
    }
}

extern "C" int pmem_read(int raddr) {
    uint32_t a = (uint32_t)(raddr & ~0x3u) & (PMEM_SIZE - 1);
    return (int)(pmem[a] | (pmem[a+1] << 8) | (pmem[a+2] << 16) | (pmem[a+3] << 24));
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    uint32_t a = (uint32_t)(waddr & ~0x3u) & (PMEM_SIZE - 1);
    if (wmask & 0x1) pmem[a]   = (uint8_t)(wdata);
    if (wmask & 0x2) pmem[a+1] = (uint8_t)(wdata >> 8);
    if (wmask & 0x4) pmem[a+2] = (uint8_t)(wdata >> 16);
    if (wmask & 0x8) pmem[a+3] = (uint8_t)(wdata >> 24);
}