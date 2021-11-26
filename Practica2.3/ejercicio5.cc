#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>

int main() {

  printf("PID: %i\n", getpid());
  printf("PPID: %i\n", getppid());
  printf("SID: %i\n", getsid(getpid()));
  printf("PgID: %i\n", getpgid());
  
  struct rlimit limit;
  printf("Maximo de ficheros: %li\n", limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("CWD: %s\n", path);
  free (path);

  return 0;
}
