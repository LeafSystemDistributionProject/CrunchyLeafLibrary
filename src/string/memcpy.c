#include <string.h>

void *memcpy(void *dst, const void *src, size_t n) {
	return (void *) strncpy((char *) dst, (char *) src, n);
}