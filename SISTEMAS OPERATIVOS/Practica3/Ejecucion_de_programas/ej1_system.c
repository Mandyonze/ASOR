#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

  if (argc < 2) {
    printf("ERROR: Introduce el comando.\n");
    return -1;
  }

  //Concatenamos todo lo que nos pase por pantalla:
  //Calculamos el tamaño del sting para reservar espacio en memoria:
  int cmdLen = 1;
  int i;
  for (i = 1; i < argc; i++)
    cmdLen += strlen(argv[i]) + 1;
  char *cmd = malloc(sizeof(char)*cmdLen);
  strcpy(cmd, "");

  //Concatenamos todos los argumentos
  for (i = 1; i < argc; i++) {
    strcat(cmd, argv[i]);
    strcat(cmd, " ");
  }

  //Ejecutamos el comando correspondiente a la entrada por argumentos
  if (system(cmd) == -1) {
    printf("ERROR: No se ha ejecutado correctamente.\n");
  }

  printf("El comando terminó de ejecutarse.\n");


  return 0;
}
