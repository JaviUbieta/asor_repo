#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(){
	struct timeval tv;
    	struct tm *hoy;
    	
    	gettimeofday(&tv, NULL);
    	
    	hoy = localtime(&tv.tv_sec);
    	

    	printf("Año actual: %d \n", hoy->tm_year + 1900);
    	
	return 1;
}
