#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define NMAX 100000

struct abr {
	int val;
	struct abr* fg;
	struct abr* fd;
};
typedef struct abr* ABR;


int alea(int n){
  return (int)(1.0*n*rand()/RAND_MAX);
}

ABR initialisation()
{
	return NULL;
}

ABR ajoutElement(ABR a, int element)
{
	if (a == NULL)
	{
		ABR tmp = malloc(sizeof(ABR));
	
		tmp->val = element;
		tmp->fg = NULL;
		tmp->fd = NULL;
		
		return tmp;
	}
	else
	{
		if(element >= a->val)
			a->fd = ajoutElement(a->fd,element);
		else
			a->fg = ajoutElement(a->fg,element);
	}
	return a;
}

ABR remplirABR(ABR a);
{
	int i=0;
	int element;
	
	while (i<NMAX)
	{
		element = alea();
		a=ajoutElement(a,element);
		
		i++;
	}
	
	return a;
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



