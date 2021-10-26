#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(){
	char outstr[200];
	struct timeval tv;
    	struct tm *hoy;
    	
    	gettimeofday(&tv, NULL);
    	
    	hoy = localtime(&tv.tv_sec);
    	
    	if(strftime(outstr, sizeof(outstr),"%c", hoy) != 0){
    		printf("Fecha: \"%s\"\n", outstr);
    	}
    	
	return 1;
}
