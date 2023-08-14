#include <stdlib.h>
#include <stdio.h>

// (not finished)
void __stack_chk_fail() {
	puts("Stack overflow!");
	exit(255);
}

void __stack_chk_fail_local() {
	__stack_chk_fail();
}