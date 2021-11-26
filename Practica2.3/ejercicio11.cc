#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {

  sigset_t set;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTSTP);
  
  sigprocmask(SIG_BLOCK, &set, NULL);

  char *sleep_secs = getenv("SLEEP_SECS");
  int secs = atoi(sleep_secs);
  sleep(secs);

  sigset_t pending;
  sigpending(&pending);

  if (sigismember(&pending, SIGINT) == 1) {
    printf("señal SIGINT recibida\n");
    sigdelset(&set, SIGINT);

  } else {
      printf("señal SIGINT no recibida\n");
  }
  if (sigismember(&pending, SIGTSTP) == 1) {
    printf("señal SIGTSTP recibida\n");
    sigdelset(&set, SIGTSTP);
  } else {
    printf("señal SIGTSTP no recibida\n");
  }

  sigprocmask(SIG_UNBLOCK, &set, NULL);

  return 0;
}
