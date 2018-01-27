
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define PIPE_W 1
#define PIPE_R 0

int main(int argv, char** argc){

  if (argv < 2) {
    printf("Error: Introduce los comandos\n");
  }

  int fd[2];

  int pipe = pipe(fd);

  switch (fork()) {
    case -1:
      perror("ERROR al hacerl el fork");
      return 1;
      break;
    case 0:
    //Hijo
      dup(fd[PIPE_R],0); //Cambiamos el descriptor a la entrada.
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      execlp(argc[3],argc[3],argc[4]);
    break;
    default:
    //Padre
      dup(fd[PIPE_W],1); //Cambiamos el descriptor a la entrada.
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      execlp(argc[1],argc[1],argc[2]);
    break;
  }

}
