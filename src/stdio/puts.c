#include <string.h>
#include <unistd.h>

int puts(const char *str) {
	int ret1 = write(STDOUT_FILENO, str, strlen(str));
	if (ret1 == -1)
		return -1;

	if (write(STDOUT_FILENO, (char*) "\n", 1) == -1) {
		return -1;
	}

	return ret1;
}