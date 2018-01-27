#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Memset,

#include <sys/types.h> //getaddrinfo, socket, bind
#include <sys/socket.h> //getaddrinfo, socket, bind


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h> //getaddrinfo,

#include <time.h>

#include <sys/select.h>


#include <unistd.h>


int main (int argc, char**argv) {


  if (argc < 2) {
    printf("Introduce la dirección.\n");
    return -1;
  }

  struct addrinfo hints;
  struct addrinfo *result, *iterator;

  //Rellenamos el hints para hacer los criterios de búsqueda.
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  //getaddrinfo
  if (getaddrinfo(argv[1], argv[2], &hints, &result) != 0) {
      printf("ERROR: No se ha podido ejecutar el getaddrinfo.");
      exit(EXIT_FAILURE);
  }

  //socket
  int socketUDP = socket(result->ai_family, result->ai_socktype, result->ai_protocol);


  //bind
  if (bind(socketUDP, result->ai_addr, result->ai_addrlen) != 0) {
    printf("ERROR: No se ha podido ejecutar el bind.");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);

  char buf[2];
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];

  struct sockaddr_storage client_addr;
  socklen_t client_addrlen = sizeof(client_addr);

  fd_set dflectura; //Creamos un descriptor de lectura
  int df = -1;

  while(1){

    while(df == -1) {
      FD_ZERO(&dflectura); //Vaciamos el puntero (No nos interesa ningún descriptor de fichero).
      FD_SET(socketUDP, &dflectura); //Metemos el descriptor del socket
      FD_SET(0, &dflectura); //Metemos el descriptor de la entrada estándar
      df = select(socketUDP+1, &dflectura, NULL, NULL, NULL);
    }


    time_t tiempo = time(NULL);
    struct tm *tm = localtime(&tiempo);
    size_t max;
    char s[50];

    if (FD_ISSET(socketUDP,&dflectura)){
      ssize_t bytes = recvfrom(socketUDP, buf, 2, 0, (struct sockaddr *) &client_addr, &client_addrlen);

      getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
      printf("[RED] %i byte(s) de %s:%s\n", bytes, host, serv);
      buf[1] = '\0';

      if (buf[0] == 't'){
        size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
        s[bytesT] = '\0';

        sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);

      }else if (buf[0] =='d'){
        size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
        s[bytesT] = '\0';

        sendto(socketUDP, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
      }else if (buf[0] =='q'){
        printf("Saliendo...\n");
        exit(0);
      }else{
        printf("Comando no soportado: %d...\n", buf[0]);
      }

    } else {
      read(0, buf, 2);
      printf("[Consola] %i byte(s)\n",2);
      buf[1] = '\0';

      if (buf[0] == 't'){
        size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
        s[bytesT] = '\0';

        printf("%s\n", s);

      }else if (buf[0] =='d'){
        size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
        s[bytesT] = '\0';

        printf("%s\n", s);
      }else if (buf[0] =='q'){
        printf("Saliendo...\n");
        exit(0);
      }else{
        printf("Comando no soportado: %d...\n", buf[0]);
      }
    }


  }

  return 0;
}
