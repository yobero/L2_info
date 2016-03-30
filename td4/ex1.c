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

//ligne de compilation : gcc -Wall ex1.c -lpthread ==> dans le terminal :D

int nthreads=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* f(void* arg);

void barriere(int max)
{
	pthread_mutex_lock(&mutex);
	nthreads++;
	
	if(nthreads==max)
	{
		pthread_cond_broadcast(&cond);
		printf("GOOOOO, focus this fucking adc !!!!!\n");
		nthreads=0;
	}
	else
		/**libere le mutex (unlock()) et endort le thread associer
		 * Le thread endormi attend qu'on le reveille avec le cond
		 * Pour reveiller tous les thread lié à cond on utilise pthread_cond_broadcast().*/
		pthread_cond_wait(&cond,&mutex);
	
	pthread_mutex_unlock(&mutex);
}

int main(int argc, char** argv)//argv ==> int
{
	int* a = (int*) argv[1];
	pthread_t th[*a];
	
	int i=0;
	while (i<*a)
	{
		pthread_create(&th[i],NULL,f,a);
		
		i++;
	}
	
	return 1;
}

void* f(void* arg)
{
	int* max = (int*)arg;
	barriere(*max);
	
	barriere(max);
	
	return NULL;
}
