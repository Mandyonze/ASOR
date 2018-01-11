
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
  char *s;
  if (setuid(0) == -1){
	   perror(s);
	}
  return 1;
}
