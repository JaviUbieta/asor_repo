#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
   int i = setuid(2);
   if(i == -1){
   	perror("Error:  setuid ha generado un error: ");
   	printf(strerror(errno));
   	printf("%i", errno);
   }
   return 1;
}
