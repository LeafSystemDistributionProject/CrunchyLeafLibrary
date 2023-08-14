#include <stdarg.h>
#include <unistd.h>

long _syscall(long n, long a1, long a2, long a3, long a4, long a5, long a6);

long syscall(long number, ...) {
	va_list ap;

	va_start(ap, number);
	long a1 = va_arg(ap, long);
	long a2 = va_arg(ap, long);
	long a3 = va_arg(ap, long);
	long a4 = va_arg(ap, long);
	long a5 = va_arg(ap, long);
	long a6 = va_arg(ap, long);
	
	long ret = _syscall(number, a1, a2, a3, a4, a5, a6);

	va_end(ap);

	return ret;
}