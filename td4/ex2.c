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

typedef struct{
	int val;
	int plein;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}mailbox;

void mbox_init(mailbox* mb) {
	mb->val=0;
	mb->plein=0;
	mb->mutex=PTHREAD_MUTEX_INITIALIZER;
	mb->cond = PTHREAD_COND_INITIALIZER;
}

void mbox_wrtie(mailbox* mb, int i) {
	pthread_mutex_lock(mb->&mutex);
		if(mb->plein==0)
		{
			mb->val = i;
			mb->plein = 1;
			pthread_cond_broadcast(&mb->cond);
			//pthread_cond_signal(&mb->cond);
		}
		else
			pthread_cond_wait(&mb->cond,&mb->mutex);
	pthread_mutex_unlock(&mb->mutex);
}

void mbox_read(mailbox* mb) {
	pthread_mutex_lock(&mb->mutex);
	if (mb->plein==1)
	{
		mb->val = 0;
		mb->plein = 0;
		pthread_cond_broadcast(&mb->cond);
	}
	else
		pthread_cond_wait(&mb->cond,mb->&mutex);
	
	pthread_mutex_unlock(&mb->mutex);
}

int main(int argv, char** argc)
{
	//argc[0] ==> l'entier n argc[1] ==> l'entier m
	
	int i=0;
	while (i<argc[0]-1)
	{
		pthread_create();
		
		i++;
	}
	
	return 1;
}
