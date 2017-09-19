KERNEL_DIR	:= /lib/modules/$(shell uname -r)/build
#KERNEL_DIR	:= /usr/src/linux-2.6.29/linux-2.6.29.i686/
KERNEL_VERSION	:= $(shell uname -r)
PWD		:= $(shell pwd)
MODULE_NAME := int_timer
obj-m		:= $(MODULE_NAME).o

all: 
	@echo "Building Timer driver..."
	@(cd $(KERNEL_DIR) && make -C $(KERNEL_DIR) SUBDIRS=$(PWD) CROSS_COMPILE=$(CROSS_COMPILE) modules)
	@echo "Building app..."
	@gcc -o timer timer.c
clean:
	-rm -f *.o *.ko .*.cmd .*.flags .mii.mod.o.d *.mod.c Module.symvers Module.markers modules.order version.h
	-rm -rf .tmp_versions

