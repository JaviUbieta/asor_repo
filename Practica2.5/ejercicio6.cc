#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char**argv){

  struct addrinfo hints;
  struct addrinfo *result;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  
  if (getaddrinfo(argv[1], argv[2], &hints, &result) != 0) {
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

    while (1) {
      getnameinfo((struct sockaddr *)&cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
      printf("Conexión %s:%s\n", host, serv);

      c = recv(cli_sd, buf, 80, 0);
      buf[c] = '\0';

      if ((buf[0] == 'Q') && (c == 2)) {
        break;
      }
      send(cli_sd, buf, c, 0);
    }

  }

  close(cli_sd);



  return 0;
}
