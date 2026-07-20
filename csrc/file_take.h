#ifndef __file_take_h__
#define __file_take_h__

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
extern FILE *pf;

#define file_open(filename, mode) \
do { \
    pf = fopen((filename), (mode)); \
    if (pf != NULL) { \
        printf("文件打开成功，文件名：%s\n", (filename)); \
    } else { \
        printf("文件打开失败，文件名：%s\n", (filename)); \
        assert(0);\
    } \
} while(0)

#define file_close() \
do { \
    if (pf != NULL) { \
        fclose(pf); \
        pf = NULL; \
        printf("文件关闭成功\n"); \
    } \
} while(0)

#define file_read(seek, read_rd) \
do { \
    if (pf != NULL && (read_rd) != NULL) { \
        fseek(pf, (seek), SEEK_SET); \
        fread((read_rd), sizeof(uint32_t), 1, pf); \
    } \
} while(0)

#define file_write(seek, write_rd) \
do { \
    if (pf != NULL) { \
        fseek(pf, (seek), SEEK_SET); \
        fwrite(&(write_rd), sizeof(uint32_t), 1, pf); \
        fflush(pf); \
    } \
} while(0)

#endif
