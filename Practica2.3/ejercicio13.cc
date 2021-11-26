#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int stop = 0;

void handler(int senial){
  if (senial == SIGUSR1) stop = 1;
}

int main(int argc, char **argv) {

  sigset_t mask;
  sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
  sigprocmask(SIG_UNBLOCK, &mask, NULL);

  struct sigaction act;
  sigaction(SIGUSR1, NULL, &act);
  act.sa_handler = handler;
  sigaction(SIGUSR1, &act, NULL);

  int s = atoi(argv[1]);

  int i = 0;
	while (i < s && stop == 0) {
    i++;
    sleep(1);
  }

  if (stop == 0) {
    unlink(argv[0]);
  }

  return 0;
}
