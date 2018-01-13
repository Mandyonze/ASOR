#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	time_t t = time(NULL);

	printf("Seconds since 1/1/1970 00:00:00 UTC: %li\n", t);

	return 0;
}
