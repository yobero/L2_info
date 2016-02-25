#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int compteur=0;

/* Il y a une boucle infini*/
int main(int N, char** M)
{
	pid_t pid;
	int m = M[0];
	int i=0; //processus
	int j=0; // niveaux
	
	if (N>=1000) exit(EXIT_FAILURE);
	if (m>=100) exit(EXIT_FAILURE);
	
	while(i<N)
	{
		pid = fork();
		///PAR ICI
		if (pid==0)
		{
			i=0;
			j++;
		}
		compteur++;
		i++;
	}
	i=0;
	while(i<N)
	{
		wait(&pid);
		i++;
	}
	if (pid !=0)
		printf("Il y a eu %d processus\n",compteur);
	
	return 1;
}
