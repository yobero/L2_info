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

ABR remplirABR(ABR a)
{
	int i=0;
	int element;
	
	while (i<10)
	{
		element = alea(100);
		//printf("%d ",element);
		a=ajoutElement(a,element);
		//printf("%d ",a->val);
		
		i++;
	}
	return a;
}

ABR suppresionABR(ABR a)
{
	if (a==NULL)
		return NULL;
	if (a->fg == NULL && a->fd == NULL)
	{
		free(a);
		return NULL;
	}
	else
	{
		a->fg=suppresionABR(a->fg);
		a->fd=suppresionABR(a->fd);
	}
	return NULL;
	
}

ABR afficheABR(ABR a)
{
	if (a==NULL)
		return a;
	afficheABR(a->fg);
	printf("%d ",a->val);
	afficheABR(a->fd);
	
	return a;
}

int main(void){
  struct timeval tv1,tv2;
  double duree;

  srand(time(NULL));
  ABR a = initialisation();



  /*déclenchement du chronomètre*/
  gettimeofday(&tv1, NULL);
  
  a = remplirABR(a);
  
  afficheABR(a);
  suppresionABR(a);
  afficheABR(a);
  printf("rien ");
  /*arrêt du chronomètre*/
  gettimeofday(&tv2, NULL);  

  /*affichage de la durée en microsecondes*/
  duree = (tv2.tv_sec-tv1.tv_sec) * 1000000 + (tv2.tv_usec-tv1.tv_usec);
  printf("%f\n", duree);


  
  return 0;
}



