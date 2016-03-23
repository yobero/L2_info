#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>

#include <time.h>

//ligne de compilation : gcc -Wall ex1.c -lpthread ==> dans le terminal :D

#define A 100
#define N 10
#define M 20

int tab[M];
int MAX=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct limite {
	int min;
	int max;
	int ecart;
};
typedef struct limite LIMITE;

int alea ()
{
	int valeur;
		valeur=rand()%A;
		return valeur;
}

void initialisationTab()
{
	int i=0;
	while (i<M)
	{
		tab[i] = alea();
		i++;
	}
}

void affichageTab()
{
	int i=0;
	while (i<M)
	{
		printf("%d ",tab[i]);
		i++;
	}
	printf("\n");
}

void affichageMax(int max[N])
{
	int i=0;
	
	while(i<N)
	{
		printf("%d ",max[i]);
		i++;
	}
	printf("\n");
}

void* recherche(void* l);

int recherchePere(int Max[N])
{
	int i=1;
	int max=Max[0];
	while(i<N)
	{
		if(max<Max[i])
			max=Max[i];
		i++;	
	}
	return max;
}

int main()
{
	srand(time(NULL));
	
	initialisationTab();
	affichageTab();
	
	pthread_t thread[N];
	LIMITE l;
	
	l.min=0;
	l.ecart=l.max=M/N;
	int i=0;
	
	while(i<N)
	{
		pthread_create(&thread[i],NULL,recherche,&l);
		i++;
	}
	i=0;
	/*void* join;
	int Max[N];*/
	
	while(i<N)//recupération des valeurs
	{
		pthread_join(thread[i],NULL);
		/*Max[i]=*(int*)(join);
		free(join);*/
		i++;
	}
	//affichageMax(Max);
	
	printf("la valeur max du tableau est %d\n", MAX);
	
	return 1;
}

void* recherche(void* l)
{
	LIMITE* a = (LIMITE*)l;
	int i=a->min;
	int* tmp=malloc(sizeof(int));
	*tmp = tab[a->min];
	while(i<a->max)
	{
		if (*tmp<tab[i])
			*tmp = tab[i];
		i++;
	}
	a->min = a->max;
	a->max = a->max + a->ecart;
	
	pthread_mutex_lock(&mutex);
	if(*tmp>MAX)
		MAX=*tmp;
	pthread_mutex_unlock(&mutex);
	return NULL;
}
