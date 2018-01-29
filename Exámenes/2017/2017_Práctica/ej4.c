#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

  char *tuberia1 = "tuberia1";
  char *tuberia2 = "tuberia2";
  char buffer[256];
  fd_set set;
  int pipeselect, pipeactual, numpipeactual, bytes;
  //Creamos las dos tuberias
  mkfifo(tuberia1, 0644);
  mkfifo(tuberia2, 0644);

  //Abrimos las tuberías
  int fd1 = open(tuberia1, O_RDONLY | O_NONBLOCK);
  int fd2 = open(tuberia2, O_RDONLY | O_NONBLOCK);

  while(1){
        FD_ZERO(&set);
        FD_SET(fd1,&set);
        FD_SET(fd2,&set);

        pipeselect = select((fd2>fd1) ? fd2+1 : fd1+1, &set, NULL,NULL,NULL);

        if (FD_ISSET(fd1,&set)){
          pipeactual = fd1;
          numpipeactual = 1;
        }else if (FD_ISSET(fd2,&set)){
          pipeactual = fd2;
          numpipeactual = 2;
        }

        ssize_t readsize = 256;

        while(readsize == 256){
          readsize = read(pipeactual, buffer, 256);
          buffer[readsize] = '\0';
          printf("Tuberia[%i]:%s\n",numpipeactual,buffer);
        }

        if (numpipeactual == 1){
          close(fd1);
          fd1 = open(tuberia1, O_RDONLY | O_NONBLOCK);
        } else if (numpipeactual == 2){
          close(fd2);
          fd2 = open(tuberia2, O_RDONLY | O_NONBLOCK);
        }
  }


  return 0;
}
