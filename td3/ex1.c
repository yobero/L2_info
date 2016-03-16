#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>

#define N 10

int numero[N];

void* affichage(void* arg);
void* f(void*arg);

int main()
{
	pthread_t thread[N];
	int arg=0;
	int i=0;

	while(i<N)
	{
		numero[i] = i+1;
		pthread_create(&thread[i],NULL,affichage,&numero[i]);
		i++;
	}

	i=0;
	void* join;
	while(i<N)
	{
		pthread_join(thread[i],&join);
		printf("%d\n",*(int*)(join));
		free(join);
		
		i++;
	}
	
	return 1;
}

void* f(void* arg)
{
	int* val = (int*) arg;
	*val;
}

void* affichage(void* arg)
{
	int* ret = malloc(sizeof(int));
	int val = *((int*)arg);
	printf("thread %d\n",val);
	*ret = val*2;
	return ret;
}
