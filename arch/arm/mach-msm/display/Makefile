obj-$(CONFIG_MACH_PRIMOU) += primou-panel.o
obj-$(CONFIG_MACH_SAGA) += saga-panel.o
obj-$(CONFIG_MACH_SPADE) += spade-panel.o
obj-$(CONFIG_MACH_VIVO) += vivow-panel.o
obj-$(CONFIG_MACH_VIVOW) += vivow-panel.o
ifndef CONFIG_MACH_VISION
obj-$(CONFIG_ARCH_MSM7X30) += panel-samsungwvga-tl2796a.o panel-samsungwvga-s6e63m0.o
ifeq ($(CONFIG_MICROP_COMMON),y)
	obj-$(CONFIG_ARCH_MSM7X30) += panel-sonywvga-s6d16a0x21-7x30.o
endif
endif
obj-$(CONFIG_MACH_VISION) += vision-panel.o
