#
# Makefile for the linux kernel.
#
# Reuse any files we can from the H8/300H
#

#VPATH := $(VPATH):$(BOARD)

# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
.S.o:
	$(CC) -D__ASSEMBLY__ $(AFLAGS) -I. -c $< -o $*.o

all: platform.o $(BOARD)/crt0_$(MODEL).o
O_TARGET := platform.o
obj-y := entry.o ints_h8300h.o ptrace_h8300h.o

$(BOARD)/crt0_$(MODEL).o: $(BOARD)/crt0_$(MODEL).S

include $(TOPDIR)/Rules.make
