#ifndef __ASM_ARCH_MEMORY_H
#define __ASM_ARCH_MEMORY_H

#define TASK_SIZE (0x2000000UL)
#define TASK_SIZE_26 TASK_SIZE

#define PHYS_OFFSET (DRAM_BASE)
#define PAGE_OFFSET PHYS_OFFSET
#define END_MEM (DRAM_BASE+DRAM_SIZE)

#define __virt_to_phys(vpage) ((unsigned long)(vpage))
#define __phys_to_virt(ppage) ((void*)(ppage))
#define __virt_to_bus(vpage) ((unsigned long)(vpage))
#define __bus_to_virt(ppage) ((void*)(ppage))

#endif

