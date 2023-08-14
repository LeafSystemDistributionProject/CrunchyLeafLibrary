export LIBCCFLAGS = -nostdinc -isysroot $(shell pwd) -I $(shell pwd)/include -nostdlib
export CC ?= ${CROSS_COMPILE}cc
export AS ?= ${CROSS_COMPILE}as
export AR ?= ${CROSS_COMPILE}ar

all: shared static
shared: ../libc.so
static: ../libc.a

../libc.so:
	make -C src libc.so

../libc.a:
	make -C src libc.a

clean:
	rm -f $(shell find . -type f -name '*.o') $(shell find . -type f -name '*.so') $(shell find . -type f -name '*.a')