# The module to be built
# obj-m = loadable module
obj-m+=hello.o

all:
	# -C = switch to following directory (kernel build dir)
	# M = shows where actual project files are
	# modules = default target for external kernel modules
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


