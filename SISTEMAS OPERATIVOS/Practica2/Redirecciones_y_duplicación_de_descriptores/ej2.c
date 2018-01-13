
#include <stdio.h>


//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//dup
#include <unistd.h>


int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}


  int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
  if (fd == -1) {
    printf("ERROR: No se ha podido abrir/crear el fichero.\n");
    return -1;
  }

	int fd3 = dup2(fd,2);
  int fd2 = dup2(fd, 1);



  printf("Esto se ha reedirigido a %s\n", argv[1]);

	char *s;
	if (setuid(0) == -1){
		 perror(s);
	}

  dup2(fd2, fd);
	dup2(fd3,fd);

  return 1;
}
