
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int int_count = 0;
volatile int tstp_count = 0;

void hler(int senial){
  if (senial == SIGINT) int_count++;
  if (senial == SIGTSTP) tstp_count++;
}

int main(){

  struct sigaction act;

  //Sigint
  sigaction(SIGINT, NULL, &act); //Get handler
  act.sa_handler = hler;
  sigaction(SIGINT, &act, NULL); //Set sa_handler
  //Sigtstp
  sigaction(SIGTSTP, NULL, &act); //Get handler
  act.sa_handler = hler;
  sigaction(SIGTSTP, &act, NULL); //Set sa_handler


  sigset_t set;
	sigemptyset(&set);

	while (int_count + tstp_count < 10)
		sigsuspend(&set);

	printf("SIGINT captured: %i\n", int_count);
	printf("SIGTSTP captured: %i\n", tstp_count);


  return 0;
}
