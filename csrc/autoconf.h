#ifndef __AUTOCONF_H__
#define __AUTOCONF_H__
#define CONFIG_ISA64 false
#define CONFIG_MBASE 0x80000000
#define CONFIG_MSIZE 0x100000
#define CONFIG_TRACE 0
#ifdef CONFIG_TRACE
    #define CONFIG_ITRACE 0
    #define CONFIG_MTRACE 0
    #define CONFIG_IRINGBUF 0
#endif
//#define CONFIG_FTRACE 0
//#define CONFIG_TARGET_AM 0
//#define CONFIG_DEVICE 0
#define __GUEST_ISA__ riscv32
#endif