#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int num_int = 0;
int num_count = 0;

void handler(int senial){
  if (senial == SIGINT) num_int++;
  if (senial == SIGTSTP) num_count++;
}

int main(){

  struct sigaction act;

  sigaction(SIGINT, NULL, &act);
  act.sa_handler = handler;
  sigaction(SIGINT, &act, NULL);
  sigaction(SIGTSTP, NULL, &act);
  act.sa_handler = handler;
  sigaction(SIGTSTP, &act, NULL);


  sigset_t set;
	sigemptyset(&set);

	while (num_int + num_count < 10)
		sigsuspend(&set);

	printf("Señales SIGINT: %i\n", num_int);
	printf("Señales SIGTSTP: %i\n", num_count);


  return 0;
}
