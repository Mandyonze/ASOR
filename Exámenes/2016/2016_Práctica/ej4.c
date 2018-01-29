#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void hler (int signal) {printf("Efectuando tarea programada\n");}

int main(int argc, char **argv){

  if (argc < 4) printf("ERRO: Introduzca los argumentos necesarios\n");

  int segundos = atoi(argv[1]);
  pid_t pid = fork();

  if (pid == 0) {
    struct sigaction act;
    act.sa_handler = hler;
    act.sa_flags=0;
    sigaction(SIGALRM, &act, NULL);

    alarm(segundos);

    sigset_t set;
  	sigemptyset(&set);
    sigsuspend(&set);

    int fd = open("/tmp/examen.out", O_RDWR | O_CREAT, 0777);
    dup2(fd, 1);
    execvp(argv[2], argv+2);

  } else if (pid == -1){
    printf("ERROR: No se ha podido ejecutar el FORK\n");
  } else {
    printf("Ejecución programada en %i segundos por el proceso %i\n",segundos, pid);
  }


  return 0;
}
