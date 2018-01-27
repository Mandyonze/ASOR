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


  freeaddrinfo(result);

  char buf[2];
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];

  struct sockaddr_storage client_addr;
  socklen_t client_addrlen = sizeof(client_addr);


  sendto(socketUDP, argv[3], 2, 0, result->ai_addr, result->ai_addrlen);

  printf("%s\n", argv[3]);


  if (*argv[3] == 'd' || *argv[3] == 't'){
    char s[50];
    ssize_t bytes = recvfrom(socketUDP, s, 50, 0, (struct sockaddr *) &client_addr, &client_addrlen);
    s[bytes] = '\0';

    printf("%s\n", s);
  }


  return 0;
}
