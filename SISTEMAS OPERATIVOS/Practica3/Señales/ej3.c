
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//export SLEEP_SECS="120"

int main(int argc, char **argv) {
	if (argc != 2) {
    printf("ERROR: Introduce los segundos!\n");
    return -1;
  }

  sigset_t set;

  //Inicializamos un conjunto de señales y añadimos las señales de int y tstp
  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTSTP);

  //Protegemos la región de código contra la recepción de las señales
  sigprocmask(SIG_BLOCK, &set, NULL);

  //Obtenemos la variable de entorno
  char *sleep_secs = getenv("SLEEP_SECS");
  int secs = atoi(sleep_secs);
  printf("Se va a dormir el proceso durante %d segundo(s)\n", secs);
  //Dormimos el proceso
  sleep(secs);

  //Comprobamos las señales pendientes
  sigset_t pending;
  sigpending(&pending);

  if (sigismember(&pending, SIGINT) == 1) {
    printf("Se ha recibido la señal SIGINT\n");

    //Eliminamos la señal del conjunto anterior
    sigdelset(&set, SIGINT);

  } else {
      printf("No se ha recibido la señal SIGINT\n");
  }
  if (sigismember(&pending, SIGTSTP) == 1) {
    printf("Se ha recibido la señal SIGTSTP\n");

    //Eliminamos la señal del conjunto anterior
    sigdelset(&set, SIGTSTP);
  } else {
    printf("No se ha recibido la señal SIGTSTP\n");
  }

  sigprocmask(SIG_UNBLOCK, &set, NULL);

  return 0;
}
