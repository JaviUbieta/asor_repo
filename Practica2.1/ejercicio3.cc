#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
	for(int i = 0; i < 255; i++){
	 	printf("Error: %s\n", strerror(i));
	}
	return 1;
}
