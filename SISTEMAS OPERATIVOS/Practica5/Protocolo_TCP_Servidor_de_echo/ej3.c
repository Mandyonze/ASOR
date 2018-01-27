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
  bind(socketTCP, result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);

  listen(socketTCP, 5);

  struct sockaddr_storage cli;
  socklen_t clen = sizeof(cli);

  char buf[81];
  int cli_sd;
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];
  ssize_t c;


  while (1) {

    cli_sd = accept(socketTCP,(struct sockaddr *) &cli, &clen);

    pid_t pid;
    pid = fork();
    if (pid == 0) {
      while (1) {
        getnameinfo((struct sockaddr *)&cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
        printf("[PID: %i] Conexión desde %s:%s\n", getpid(), host, serv);

        c = recv(cli_sd, buf, 80, 0);
        buf[c] = '\0';

        if ((buf[0] == 'Q') && (c == 2)) {
          printf("Conexión terminada\n");
          break;
        }
        send(cli_sd, buf, c, 0);
      }
      close(cli_sd);
    } else {
      close(cli_sd);
    }
  }

  close(cli_sd);



  return 0;
}
