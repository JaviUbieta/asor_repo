#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char **argv){

    char *HOME = getenv("HOME");
		char *tuberia = strcat(HOME, "/tuberia");


   
  	mkfifo(tuberia, 0777);

		int fd = open(tuberia, O_WRONLY);
    printf("Opened %s\n", tuberia);
		write(fd, argv[1], strlen(argv[1]));

		close(fd);


  return 0;
}
