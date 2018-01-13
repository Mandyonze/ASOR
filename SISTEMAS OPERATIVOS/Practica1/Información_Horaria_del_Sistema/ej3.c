#include <time.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

	time_t t = time(NULL);

	char *date= ctime(&t);

	printf("CTIME: %s\n", date);

	return 0;
}
