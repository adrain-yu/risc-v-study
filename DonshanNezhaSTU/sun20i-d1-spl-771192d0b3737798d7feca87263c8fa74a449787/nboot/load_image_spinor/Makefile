#
# (C) Copyright 2013-2016
# SPDX-License-Identifier: GPL-2.0+
#  Allwinner Technology Co., Ltd. <www.allwinnertech.com>
#
#



include $(TOPDIR)/mk/config.mk

LIB	:= $(obj)libloadspinor.o


COBJS-$(CFG_SUNXI_SPINOR) += load_image_spinor.o

SRCS	:= $(COBJS-y:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS-y))

all:	$(obj).depend $(LIB)

$(LIB):	$(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(TOPDIR)/mk/rules.mk

sinclude $(obj).depend

#########################################################################
