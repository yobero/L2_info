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

void* f(void* arg)
{
	int val;
}

int main()
{
	pthread_t thread[N];
	int arg=0;
	int i=0;

	while(i<N)
	{
		numero[i] = i+1;
		i++;
	}
	
	pthread_create(&thread,NULL,&f,(void*)&arg);
	
	return 1;
}
