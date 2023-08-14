#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

void exit(int code) {
	syscall(SYS_exit, code);
}