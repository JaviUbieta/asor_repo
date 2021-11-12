#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
  struct stat buf;
  int statint = stat(argv[1], &buf);
  char* hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
  char* sym = malloc(sizeof(char)*(5 + strlen(argv[1])));
  strcpy(hard, argv[1]);
  strcpy(sym, argv[1]);
  hard = strcat(hard, ".hard");
  sym = strcat(sym, ".sym");
  mode_t mode = buffer.st_mode;
  if (S_ISREG(mode)) {
    printf("%s es un archivo ordinario.\n", argv[1]);
    link(argv[1],hard);
    symlink(argv[1],sym);
   }else {
    printf("No es regular");
   }
return 0;
}
