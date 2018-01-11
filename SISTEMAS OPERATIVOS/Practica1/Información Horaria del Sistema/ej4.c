
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(){
  //Empieza el programa y calcula el tiempo
  struct timeval tv;
	int rc = gettimeofday(&tv, NULL);
  int start = tv.tv_usec;

  //Hace las iteraciones
  int i;
  for (i = 0; i < 10000; i++);

  //Vuvelve a calcular el tiempo
  int rc2 = gettimeofday(&tv, NULL);
  int end = tv.tv_usec;

  printf("Ha tardado (ms): %i\n", end - start);

  return 1;
}
