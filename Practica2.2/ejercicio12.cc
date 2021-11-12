#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  int f1 = open(argv[1], O_CREAT | O_RDWR, 00777);
  int f2 = dup2(fd_1, 1);
  dup2(f2, f1);
return 1;
}
