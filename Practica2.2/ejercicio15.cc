#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char ** argv) {
  int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
  struct flock cerrojo;
  cerrojo.l_type = F_UNLCK;
  cerrojo.l_whence = SEEK_SET;
  cerrojo.l_start = 0;
  cerrojo.l_len = 0;
  cerrojo.l_pid = getpid();
  int estado = fcntl(fd, F_GETLK, &lock);
  
  if (cerrojo.l_type == F_UNLCK) {
    cerrojo.l_type = F_WRLCK;
    cerrojo.l_whence = SEEK_SET;
    cerrojo.l_start = 0;
    cerrojo.l_len = 0;
    cerrojo.l_pid = getpid();
    fcntl(fd, F_GETLK, &lock);
    printf("Cerrojo bloqueado\n");
    time_t tim = time(NULL);
    struct tm *tm = localtime(&tim);
    char buf[1024];
    sprintf (buf, "Hora actual: %d:%d\n", tm->tm_hour, tm->tm_min);
    write(fd, &buf, strlen(buffer));
    sleep(30);
    cerrojo.l_type = F_WRLCK;
    cerrojo.l_whence = SEEK_SET;
    cerrojo.l_start = 0;
    cerrojo.l_len = 0;
    cerrojo.l_pid = getpid();
    fcntl(fd, F_GETLK, &lock);
    close(fd);
  }else {
  close(fd);
  return 1;
  }
}
