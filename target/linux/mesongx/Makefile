#
# Copyright (C) 2017-2018 Stijn Tintel <stijn@linux-ipv6.be>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

ARCH:=aarch64
BOARD:=mesongx
BOARDNAME:=Amlogic S9 family
CPU_TYPE:=cortex-a53
DEVICE_TYPE:=other
FEATURES:=audio boot-part ext4 fpu squashfs usbgadget
MAINTAINER:=Stijn Tintel <stijn@linux-ipv6.be>

KERNEL_PATCHVER:=5.4

define Target/Description
	Build firmware image for Amlogic S9 SoC devices.
endef

include $(INCLUDE_DIR)/target.mk

DEFAULT_PACKAGES += \
	e2fsprogs \
	kmod-sound-core \
	kmod-usb-hid \
	mkf2fs \
	partx-utils \
	v4l-utils

KERNELNAME:=Image dtbs

$(eval $(call BuildTarget))