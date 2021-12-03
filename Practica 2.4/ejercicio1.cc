#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argv, char** argc){

  int fd[2];

  int pipe = pipe(fd);

  switch (fork()) {
    case -1:
      perror("ERROR con el fork");
      return 1;
      break;
    case 0:
    //Hijo
      dup(fd[0],0);
      close(fd[1]);
      close(fd[0]);
      execlp(argc[3],argc[3],argc[4]);
    break;
    default:
    //Padre
      dup(fd[1],1);
      close(fd[1]);
      close(fd[0]);
      execlp(argc[1],argc[1],argc[2]);
    break;
  }
  
  return 1;
}
