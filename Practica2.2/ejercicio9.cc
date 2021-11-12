#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat buf;
  int stati = stat(argv[1], &buf);
  printf("MAJOR: %li\n", (long) major(buf.st_dev));
  printf("MINOR: %li\n", (long) minor(buf.st_dev));
  printf("Inodo: %li\n", (long)buf.st_ino);
  printf("Tipo de archivo: %i\n", buf.st_mode);
  time_t acc = buf.st_time;
  struct tm *tiempoacc = localtime(&acc);
  printf("Ultimo acceso: %d:%d:%d\n", tiempoacc->tm_hour, tiempoacc->tm_min, tiempoacc->tm_sec);
  return 0;
}
