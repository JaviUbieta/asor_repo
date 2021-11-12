#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  int f1 = open(argv[1], O_CREAT | O_RDWR, 00777);
  int f3 = dup2(fd_1, 2);
  int f2 = dup2(fd_1, 1);
char *i;
if (setuid(0) == -1){
  perror(i);
}
  dup2(fd_2, fd_1);
  dup2(fd_3, fd_1);
  return 1;
}
