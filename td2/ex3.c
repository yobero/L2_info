#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int N, int M)
{
	pid_t pid;
	int i=0; //processus
	int j=0; // niveaux
	
	if (N>=1000) exit(EXIT_FAILURE);
	if (M>=100) exit(EXIT_FAILURE);
	
	while(i<N)
	{
		pid = fork();
		if (pid==0)
		{
			i=0;
			j++;
		}
		i++;
	}
	i=0;
	while (i<N)
	{
		
		i++;;
	}
	
	return 1;
}
