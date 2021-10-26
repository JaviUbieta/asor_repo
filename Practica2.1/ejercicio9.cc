#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	printf("identificador de usuario real del proceso actual.: %d\n", getuid());
	printf("identificador de usuario efectivo del proceso actual.: %d\n", geteuid());
return 1;
}
