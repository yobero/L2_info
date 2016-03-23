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

struct inf{
	int debut;
	int fin;
	int retour;
	pthread_t th;
};

#define N 10
#define TAILLE 30

void* recherche(void* arg):

int main(int argv, char** argc)
{
	struct inf infi[N];
	
	for(i=0;i<n;i++)
	{
		infi[i].debut= i*(TAILLE/N);
		infi[i].fin = ;
		if(i!=0)
			ptread_create();
		
	}
}

void* recherche(void* arg)
{
	struct inf* info_th = (struct inf*) arg;
	int i;
	
	for(i=info_th->debut;i<info_th->fin;i++)
	{
		if(tab[i]> info_th->retour)
			info_th->retour = ta[i];
	}
	return NULL;
}
