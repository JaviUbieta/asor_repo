#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(){
    	struct timeval start;
    	struct timeval end;
    	
    	gettimeofday(&start, NULL);
    	
    	for(int i =0; i < 1000000; i++){}
    	
    	gettimeofday(&end,NULL);
    	
    	unsigned long  tstart = start.tv_sec *1000000 + start.tv_usec;
    	unsigned long  tend = end.tv_sec *1000000 + end.tv_usec;
    	printf("Tiempo transcurrido: %ld microsec \n", tend-tstart);
    	
	return 1;
}
