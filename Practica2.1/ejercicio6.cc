#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){
	printf("maximum length of the arguments: %ld\n", sysconf(_SC_ARG_MAX));
	printf("maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
	printf("maximum number of files that a process can have open: %ld\n", sysconf(_SC_OPEN_MAX));

return 1;
}
