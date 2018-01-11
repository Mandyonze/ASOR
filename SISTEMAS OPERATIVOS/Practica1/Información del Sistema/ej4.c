
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

const int MAX_ERR=255;

int main(){
  char *s;
  for (int i = 0; i < MAX_ERR; i++){
	   //perror(s);
     printf("ERROR(%d): %s\n", i, strerror(i));
	}
  return 1;
}
