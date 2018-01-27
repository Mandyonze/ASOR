#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char**argv){

  if (argc < 2) {
    printf("Introduce los parámetros.\n");
    return -1;
  }

  struct addrinfo hints;
  struct addrinfo *result;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; //Coger direcciones IPv4 y Ipv6
  hints.ai_socktype = SOCK_STREAM; //Tipo de socket TCP
  hints.ai_flags = AI_PASSIVE; // node == NULL

  //argv[1] node (Referencia al host) argv[2] server (Puerto)
  if (getaddrinfo(argv[1], argv[2], &hints, &result) != 0) {
      printf("ERROR: No se ha podido ejecutar el getaddrinfo.");
      exit(EXIT_FAILURE);
  }

  int socketTCP = socket(result->ai_family, result->ai_socktype, 0);
  connect(socketTCP,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);


  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];
  //struct sockaddr_storage cli;
  //socklen_t clen = sizeof(cli);

  //getnameinfo((struct sockaddr *)&cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);


  char buffin[256];
  char buffout[256];
  ssize_t c;


  while (1) {
    c = read(0,buffout, 255);
    buffout[c] = '\0';
    send(socketTCP,buffout, c, 0);


    if ((buffout[1] == 'q') && (c == 2)) {
      printf("Conexión terminada\n");
      break;
    }

    c = recv(socketTCP, buffin, 255, 0);
    buffin[c] = '\0';
    printf("[OUT]:%s\n", buffin);
  }

  close(socketTCP);



  return 0;
}
