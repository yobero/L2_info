#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>
#include <semaphore.h>

#include <time.h>

//ligne de compilation : gcc -Wall ex1.c -lpthread ==> dans le terminal :D

#define TAILLE 20

#define PROD 1
#define CONS 1

#define PRODMAX 10

struct panier {
	int tab[TAILLE];
	int element;
};
typedef struct panier PANIER;

pthread_mutex_t producteur = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t consommateur = PTHREAD_MUTEX_INITIALIZER;
int prodMax = 0;

int alea ()
{
	int valeur;
		valeur=rand()%99;
		return valeur;
}

PANIER initialisation(PANIER p)
{
	int i=0;
	while(i<TAILLE)
	{
		p.tab[i]=0;
		i++;
	}
	p.element=0;
	return p;
}

void affichage(PANIER p)
{
	int i=0;
	while (i<TAILLE)
	{
		printf("%d ",p.tab[i]);
		i++;
	}
	printf("\n");
}
void* Producteur (void* arg);
void* Consommateur(void* arg);

int main()
{
	pthread_t producteur[PROD];
	pthread_t consommateur[CONS];
	PANIER p = initialisation(p);
	int i=0;
	int j=0;
	
	while(p.element != 0 || prodMax<PRODMAX)
	{
		pthread_create(&producteur[i],NULL,Producteur,&p);
		pthread_create(&consommateur[j],NULL,Consommateur,&p);
		
		affichage(p);
		
		pthread_join(producteur[i],NULL);
		pthread_join(consommateur[j],NULL);
	}
	
	return 1;
}

//Producteur
void* Producteur(void* arg)
{
	PANIER* p= (PANIER*) arg;
	int i=p->element;
	
	pthread_mutex_lock(&consommateur);
	pthread_mutex_lock(&producteur);
	while(i<TAILLE)
	{
		p->tab[i] = 1+alea();
		prodMax++;
		i++;
	}
	p->element = i-1;;
	
	pthread_mutex_unlock(&consommateur);
	pthread_mutex_unlock(&producteur);
	
	return NULL;
}

void* Consommateur(void* arg)
{
	PANIER* p =(PANIER*) arg;
	
	pthread_mutex_lock(&producteur);
	pthread_mutex_lock(&consommateur);
	if(p->element !=0)
	{
		printf("Le consommateur a pris %d\n",p->tab[p->element]);
		p->tab[p->element]=0;
		p->element = p->element-1;
	}
	pthread_mutex_unlock(&consommateur);
	pthread_mutex_unlock(&producteur);
	
	return NULL;
}
