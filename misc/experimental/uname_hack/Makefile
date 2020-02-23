PWD := $(shell pwd)
KERNEL_DIR := /lib/modules/$(shell uname -r)/build

obj-m += uname_hack.o

uname_hack_fake_machine := ppc
EXTRA_CFLAGS += -Duname_hack_fake_machine=\"$(uname_hack_fake_machine)\"

modules clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) $@

test:
	sudo /sbin/insmod uname_hack.ko
	uname -m
	sudo /sbin/rmmod uname_hack
