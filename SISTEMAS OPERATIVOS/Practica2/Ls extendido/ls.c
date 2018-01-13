#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

  DIR *directorio = opendir(argv[1]);

  if (directorio == NULL ) {
    printf("ERROR: No existe el directorio.\n");
    return -1;
  }

  struct dirent *current;
  struct stat info;
  size_t sizePath = strlen(argv[1]);
  current = readdir(directorio);
  unsigned long int totalsize = 0;

  while (current != NULL) {
    char *path = malloc(sizeof(char)*(sizePath + strlen(current->d_name) + 3));
    strcpy(path, argv[1]);
    strcat(path, "/");
    strcat(path, current->d_name);


    if (stat(path, &info) == -1) {
      printf("ERROR : No se puede analizar el archivo\n");
      free(path);
      closedir(directorio);
      return -1;
    } else {
      if (S_ISREG(info.st_mode)) {
        printf("[*] %s \n", current->d_name);
        totalsize = totalsize + ((info.st_blksize/8)*info.st_blocks);

      } else if (S_ISDIR(info.st_mode)) {
        printf("[/] %s \n", current->d_name);

      } else if (S_ISLNK(info.st_mode)) {
        char *linkname = malloc(info.st_size + 1);
        int rc2 = readlink(path, linkname, info.st_size + 1);
        printf("[S]: %s->%s \n", current->d_name, linkname);
        free(linkname);
	     }
    }

    free(path);
    current = readdir(directorio);
  }

  closedir(directorio);
  return 0;
}
