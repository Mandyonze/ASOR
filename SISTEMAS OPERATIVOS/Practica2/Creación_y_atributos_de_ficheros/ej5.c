
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

  const char PATH[]="/home/mandy/ASOR/PR1/GE/ej5.txt";

  int df = open(PATH, O_CREAT, 0645);

  printf("Descriptor = %i\n", df);


  return 1;
}
