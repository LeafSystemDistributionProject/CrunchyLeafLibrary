#ifndef _SYS_SYSCALL_H

#if __x86_64__
#include <sys/_syscall64.h>
#else
#include <sys/_syscall32.h>
#endif

#define _SYS_SYSCALL_H
#endif