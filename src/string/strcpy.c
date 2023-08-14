#include <string.h>

char *strcpy(char *dst, const char *src) {
	return strncpy(dst, src, strlen(src) + 1);
}