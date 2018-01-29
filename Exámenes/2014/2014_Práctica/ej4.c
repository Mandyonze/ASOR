#include <stdio.h>
#include <errno.h>
#include <stdlib.h> //exit

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

void main(int argc, char**argv){
  if (argc < 2) {
    printf("Introduce los parámetros necesarios");
    exit(1);
  }

  struct addrinfo hints, *res;
  struct sockaddr_storage cli;
  char buf[81], host[NI_MAXHOST], serv[NI_MAXSERV], send[256];
  int bytes = 0;

  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_protocol = 0;
  getaddrinfo(argv[1],argv[2],&hints, &res);
  int sd = socket(res->ai_family, res->ai_socktype,0);
  bind(sd, (struct sockaddr *)res->ai_addr, res->ai_addrlen);
  freeaddrinfo(res);

  while(1){
    socklen_t clen = sizeof(cli);
    int c = recvfrom(sd, buf, 80, 0,(struct sockaddr *) &cli, &clen);
    getnameinfo((struct sockaddr *) &cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
    printf("Host:%s\tPuerto:%s\n",host,serv);
    if (buf[0] == 'a') {
      sendto(sd, host, strlen(host), 0, (struct sockaddr *) &cli, clen);
    } else if (buf[0] == 'p'){
      sendto(sd, serv, strlen(serv), 0, (struct sockaddr *) &cli, clen);
    } else if (buf[0] == 'q'){
      exit(0);
    } else {
      sendto(sd,"Comando Desconocido\n",strlen("Comando Desconocido\n"),0, (struct sockaddr *) &cli, clen);
    }
  }

}
