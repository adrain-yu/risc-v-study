# SPDX-License-Identifier: GPL-2.0+
#
#

include $(TOPDIR)/mk/config.mk

LIB	:= libarch.o
CPU	?= riscv64

START-$(CFG_SUNXI_FES) = fes1_entry.o

START-$(CFG_SUNXI_SBOOT) = sboot_entry.o

ifeq ($(CFG_SUNXI_FES)$(CFG_SUNXI_SBOOT),)
START-y = boot0_entry.o
endif

COBJS-y	+= arch_timer.o
COBJS-y   += mmu.o
#SOBJS-y	+= cache-v7.o
COBJS-y   += jmp.o

ifndef CFG_SUNXI_MEMOP
SOBJS-y   += memset.o
SOBJS-y   += memcpy.o
endif

LIBS := $(addprefix $(TOPDIR)/,$(sort $(LIBS-y)))


SRCS	:= $(COBJS:.o=.c) $(SOBJS:.o=.S) $(START-y:.o=.S)
START	:= $(addprefix $(obj),$(START-y))
OBJS	:= $(addprefix $(obj),$(COBJS-y) $(SOBJS-y))
OBJS	+= $(LIBS)
all:	$(obj).depend $(START) $(LIB)


$(LIB):	$(OBJS)
	$(call cmd_link_o_target, $(OBJS))


$(LIBS): depend
	$(MAKE) -C $(dir $(subst $(OBJTREE),,$@))
#########################################################################
depend:	$(obj).depend
.PHONY: depend

# defines $(obj).depend target
include $(TOPDIR)/mk/rules.mk

sinclude $(obj).depend

#########################################################################
