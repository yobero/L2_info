#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define NMAX 100000
	
struct timeval {
	
};

struct abr {
	int val;
	struct abr* fg;
	struct abr* fd;
};
typedef struct abr ABR;


int alea(int n){
  return (int)(1.0*n*rand()/RAND_MAX);
}


int main(void){
  struct timeval tv1,tv2;
  double duree;

  srand(time(NULL));



  /*déclenchement du chronomètre*/
  gettimeofday(&tv1, NULL);
  
  /*arrêt du chronomètre*/
  gettimeofday(&tv2, NULL);  

  /*affichage de la durée en microsecondes*/
  duree = (tv2.tv_sec-tv1.tv_sec) * 1000000 + (tv2.tv_usec-tv1.tv_usec);
  printf("%f\n", duree);


  
  return 0;
}



