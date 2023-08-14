%.o: %.c
	$(CC) $(LIBCCFLAGS) -c -o $@ $^ $(CFLAGS)


OBJECTS := $(shell find . -type f -name '*.c')
OBJECTS_O := $(shell o="" && for item in ${OBJECTS}; do o="$${item%.c}.o $${o}"; done && echo $$o)

libc.so: ${OBJECTS_O}
	${CC} $(LIBCCFLAGS) -shared -fPIC -o $@ $^ $(CFLAGS)

libc.a: ${OBJECTS_O}
	${AR} rcs libc.a ${OBJECTS_O}