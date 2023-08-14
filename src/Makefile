%.o: %.c
	$(CC) $(LIBCCFLAGS) -c -o $@ $^ $(CFLAGS)

%.o: %.s
	$(AS) -o $@ $^ $(ASFLAGS)

OBJECTS := $(shell find . -type f -name '*.c')
OBJECTS_A := $(shell find . -type f -name "*-$(ARCH).s")
OBJECTS_O := $(shell \
	o="" ; \
	for item in ${OBJECTS}; do \
		o="$${item%.c}.o $${o}"; \
	done; \
	for item in ${OBJECTS_A}; do \
		o="$${item%.s}.o $${o}"; \
	done; \
	echo $$o \
)

libc.so: ${OBJECTS_O}
	${CC} $(LIBCCFLAGS) -shared -fPIC -o $@ $^ $(CFLAGS)

libc.a: ${OBJECTS_O}
	${AR} rcs libc.a ${OBJECTS_O}