#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){


  int cmdLen = 1;
  for (int i = 1; i < argc; i++)
    cmdLen += strlen(argv[i]) + 1;
  char *cmd = malloc(sizeof(char)*cmdLen);
  strcpy(cmd, "");

  for (int i = 1; i < argc; i++) {
    strcat(cmd, argv[i]);
    strcat(cmd, " ");
  }
  int x = system(cmd);
  if (x == -1) {
    printf("ERROR: No se ha ejecutado correctamente.\n");
  }

  printf("El comando terminó de ejecutarse.\n");


  return 0;
}
