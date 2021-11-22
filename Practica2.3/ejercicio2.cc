#include <sched.h>
#include <stdio.h>
#include <string.h>

int main(){
    
    int min, max, pol, prio;
    struct sched_param param;

    pol = sched_getscheduler(0);
    char pr[20];
    if(pol == SCHED_OTHER){
        strcpy(pr, "SCHED_OTHER");
        printf("La prioridad es %s\n", pr);
    }
    else if(pol == SCHED_FIFO){
        strcpy(pr, "SCHED_FIFO");
        printf("La prioridad es %s\n", pr);
    }
    else if (pol == SCHED_RR){
        strcpy(pr, "SCHED_RR");
        printf("La prioridad es %s\n", pr);
    }
    else if (pol == SCHED_IDLE){
        strcpy(pr, "SCHED_IDLE");
        printf("La prioridad es %s\n", pr);
    }
    else if (pol == SCHED_BATCH){
        strcpy(pr, "SCHED_BATCH");
        printf("La prioridad es %s\n", pr);
    }
    else {
        strcpy(pr, "desconocida");
        printf("La prioridad es %s\n", pr);
    }

    min = sched_get_priority_min(pol);
    max = sched_get_priority_max(pol);

    printf("La prioridad minima es %d\n", min);
    printf("La prioridad maxima es %d\n", max);

    sched_getparam(0, &param);
    printf("La prioridad actual es %d\n", param.sched_priority);


    return 0;

}
