#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define N 10

int main()
{
	pid_t pid;
	*int status;
	int i=0;
	
	if (N>=1000) exit(EXIT_FAILURE);
	
	while(i<N)
	{
		pid = fork():
		if (pid==0)
			exit(getpid()%10);
		i++;
	}
	i=0;
	while (i<N)
	{
		pid = wait(&status);
		printf("pid  %d\n",pid);
		/*void ex1 avec WIFEXITED*/
		i++;
	}
	
	return 1;
}
