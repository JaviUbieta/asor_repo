#include <stdio.h>
#include <time.h>
 
int main ()
{
    time_t segs;
     
    segs = time(NULL);
    printf("Segundos desde el 1 de enero de 1970 = %ld\n", segs);
     
    return 1;
}
