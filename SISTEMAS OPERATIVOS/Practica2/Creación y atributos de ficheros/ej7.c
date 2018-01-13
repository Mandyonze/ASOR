#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	mode_t prev = umask(027); // 027

	int cfopen = open("ej6.txt", O_CREAT | O_RDONLY, 0777);

	mode_t last = umask(prev);

	printf("Last: %i\n", last);

	return 0;
}
