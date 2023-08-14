#ifndef _UNISTD_H

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#include <_defs.h>
long syscall(long number, ...);

ssize_t write(int fd, const void *data, size_t n);

#define _UNISTD_H
#endif