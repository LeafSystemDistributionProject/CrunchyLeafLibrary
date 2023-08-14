export LIBCCFLAGS = -nolibc -isysroot $(shell pwd) -I $(shell pwd)/include
export CC ?= ${CROSS_COMPILE}cc
export AS ?= ${CROSS_COMPILE}as
export AR ?= ${CROSS_COMPILE}ar
export ARCH ?= $(shell uname -m)

all: syscall_headers shared static
shared: ../libc.so
static: ../libc.a
syscall_headers: ./include/sys/_syscall64.h ./include/sys/_syscall32.h
remove_syscall_headers:
	rm -f ./include/sys/_syscall64.h ./include/sys/_syscall32.h

./include/sys/_syscall64.h:
	[ ! -f ./unistd_64.h ] && install -m644 /usr/include/asm/unistd_64.h . || exit 0
	sed 's/__NR/SYS/g' unistd_64.h > $@
	sed -i 's/ASM_UNISTD/SYS_SYSCALL/g' $@

./include/sys/_syscall32.h:
	[ ! -f ./unistd_32.h ] && install -m644 /usr/include/asm/unistd_32.h . || exit 0
	sed 's/__NR/SYS/g' unistd_32.h > $@
	sed -i 's/ASM_UNISTD/SYS_SYSCALL/g' $@

../libc.so:
	make -C src libc.so

../libc.a:
	make -C src libc.a

clean:
	rm -f $(shell find . -type f -name '*.o') $(shell find . -type f -name '*.so') $(shell find . -type f -name '*.a') 