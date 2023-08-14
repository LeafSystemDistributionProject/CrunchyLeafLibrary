#ifndef _STRING_H

#include <_defs.h>

size_t strlen(const char *str);

char *strcat(char *dst, const char *src);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
void *memcpy(void *dst, const void *src, size_t n);

#define _STRING_H
#endif