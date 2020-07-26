/*
 * arch.c - architecture definition for iPod
 *
 * Copyright (c) 2003, Bernard Leach (leachbj@bouncycastle.org)
 */

#include <linux/config.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/init.h>

#include <asm/hardware.h>
#include <asm/irq.h>
#include <asm/setup.h>
#include <asm/mach-types.h>

#include <asm/arch/irq.h>
#include <asm/mach/arch.h>

static short calc_checksum2 (char* dest, int size) {
  short csum = 0;
  while (size-- > 0) {
    char b = *dest++;
    csum = ((csum << 1) & 0xffff) + ((csum<0)? 1 : 0) + b;
  }
  return csum;
}

static char* getArgs (char* baseAddr) {
  // fetch the args
  if (strncmp (baseAddr, "Args", 4) == 0) {
    int strlen = *(short*)(baseAddr+6);
    if (*(short*)(baseAddr+4) == calc_checksum2 (baseAddr+6, strlen+2)) {
      return baseAddr + 8;
    }
  }
  return 0;
}

static char cmdlineBuffer[256] = "";

static void __init
ipod_fixup(struct machine_desc *desc, struct param_struct *params,
	char **cmdline, struct meminfo *mi)
{	
  char *args = getArgs (0x80);
  if (args) {
    if (*cmdline && **cmdline) {
      // there is a default cmdline - copy it first, then append the args
      strncat (cmdlineBuffer, *cmdline, sizeof(cmdlineBuffer)-1);
      strncat (cmdlineBuffer, " ", sizeof(cmdlineBuffer)-1);
    }
    strncat (cmdlineBuffer, args, sizeof(cmdlineBuffer)-1);
    *cmdline = cmdlineBuffer;
  }
}

MACHINE_START(IPOD, "iPod")
	MAINTAINER("Bernard Leach")
	BOOT_MEM(0x00000000, 0xc0000000, 0x00000000)
	INITIRQ(ipod_init_irq)
	FIXUP(ipod_fixup)
MACHINE_END

