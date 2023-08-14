#include <string.h>

char *strncpy(char *dst, const char *src, size_t n) {
	for (size_t i = 0; i < n; i++) {
		dst[i] = src[i];
	}

	return dst;
}