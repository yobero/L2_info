#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t pid = fork();
	if(pid != 0)//père
	{
		printf("le pid de mon fils est %d\n",pid);
		wait(&pid);
		/**
		 **int status;
		 * wait(&status);
		 * 
		 * if (WIFEXITED(status))
		 * 		printf("retour %d\n",WIFEXITED(status));
		 * else
		 * 	printf("ERROR"); */
	}
	else //=0 fils
	{
		printf("le pid du fils est %d\n",getpid());
		printf("Le pid du père est %d\n",getppid());
		exit(getpid()%10);
	}
	
	return 1;
}
