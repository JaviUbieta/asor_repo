#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

  
  int x = execvp(argv[1], argv + 1);
  if ( x == -1) {
    printf("ERROR: No se ha ejecutado correctamente.\n");
  }

  printf("El comando terminó de ejecutarse.\n");


  return 0;
}
