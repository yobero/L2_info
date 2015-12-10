#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define NMAX 100000
#define M 10

struct abr {
	int val;
	struct abr* fg;
	struct abr* fd;
};
typedef struct abr* ABR;

struct atr {
	int g;
	int d;
	struct atr* fg;
	struct atr* fm;
	struct atr* fd;
};
typedef struct atr* ATR;


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
		a=suppresionABR(a);
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

//POUR ATR

ATR initialisationATR()
{
	return NULL;
}

ATR ajoutElementATR(ATR b, int elt)
{
	if (b == NULL)
	{
		ATR tmp = malloc(sizeof(ATR));
		
		tmp->g = elt;
		tmp->d = -1;
		tmp->fg = NULL;
		tmp->fm = NULL;
		tmp->fd = NULL;
		return tmp;
	}
	else
	{
		if(elt < b->g)
		{
			if (b->d = -1)
				if(elt < b->d)
				{
					int temp=b->g;
					b->g = elt;
					b->d = temp;
				}
				else
					b->d = elt;
			else
				b->fg = ajoutElementATR(b->fg,elt);
		}
		else
			if(elt>=b->g && elt <= b->d)
			{
				if (b->d = -1)
					if(elt < b->d)
					{
						int temp=b->g;
						b->g = elt;
						b->d = temp;
					}
					else
						b->d = elt;
				else
					b->fm = ajoutElementATR(b->fm,elt);
			}
			else
				if (elt > b->d)
				{
					if (b->d = -1)
						if(elt < b->d)
						{
							int temp=b->g;
							b->g = elt;
							b->d = temp;
						}
						else
							b->d = elt;
					else	
						b->fd =ajoutElementATR(b->fd,elt);
				}
	}
	return b;
}

ATR afficheATR(ATR b)
{
	if (b==NULL)
		return b;
	afficheATR(b->fg);
	printf("%d ",b->g);
	afficheATR(b->fd);
}

int main(void){
  struct timeval tv1,tv2;
  double duree;

  srand(time(NULL));

	ABR a=initialisation();
	ATR b = initialisationATR();
	int cpt=0;
	double moy=0;
	
	
	b = ajoutElementATR(b,5);

  /*déclenchement du chronomètre*/
  ///gettimeofday(&tv1, NULL);
  
  /* PARTIE sur ABR
  while(cpt < M)
  {
		gettimeofday(&tv1, NULL);
		a = remplirABR(a);
		gettimeofday(&tv2, NULL);
		duree = (tv2.tv_sec-tv1.tv_sec) * 1000000 + (tv2.tv_usec-tv1.tv_usec);
		moy = moy +duree;
		cpt++;
  }
  
  moy = moy/M;
  printf("la moyenne est %f microsecondes\n",moy);
  
	afficheABR(a);
	///La fonction suppresion marche mal (grande valeur restante)
	suppresionABR(a);
    a=NULL;
	afficheABR(a);
	*/
  /*arrêt du chronomètre*/
  
  
  ///gettimeofday(&tv2, NULL);  

  /*affichage de la durée en microsecondes*/
  ///duree = (tv2.tv_sec-tv1.tv_sec) * 1000000 + (tv2.tv_usec-tv1.tv_usec);
  printf("%f\n", duree);


  
  return 0;
}



