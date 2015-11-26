#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(){
  int i;
  struct timeval tv1,tv2;
  double duree;
  char buf[4096];

  gettimeofday(&tv1, NULL);

  //setvbuf(stdout, buf, _IONBF, 0);//pas de buffer
  //setvbuf(stdout, buf, _IOFBF, 4096);//buffer plein
  //setvbuf(stdout, buf, _IOLBF, 4096);//ligne par ligne

  for(i=0; i<200000; i++){
    printf("%d ", i);
    if(i%10 == 0) printf("\n");
  }

  gettimeofday(&tv2, NULL);  
  duree = (tv2.tv_sec-tv1.tv_sec) * 1000000 + (tv2.tv_usec-tv1.tv_usec);

  fprintf(stderr, "%f\n", duree);
  return 0;
}


