#include <sys/types.h>
#include <sys/stat.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE_BUF 1024
#define N 10

void copie (int s,int d) {
	int n;
	char buf[SIZE_BUF];
	while ((n=read(s,buf,SIZE_BUF))>0) {
		if (write(d,buf,n) != n) {
			perror("Impossible d'écrire");
			exit(EXIT_FAILURE);
		}
		if(n==1 && buf[0] == '\n') //condition d'arrêt
			return;
	}
	if(n!=0) {
		perror("Impossible de lire");
		exit(EXIT_FAILURE);
	}
}

int main()
{
	int tab1[2];
	int tab2[2];
	pid_t pid;
	int i=0;
	
	tab1[0]=0;
	tab1[1]=-1;
	
	while(i<N)
	{ 
		pipe(tab2);
		if(fork()==0)
		{
			close(tab2[0]);
			copie(tab1[0],tab2[1]);
			close(tab1[0]);
			close(tab2[1]);
			exit(0);
		}
		close(tab1[0]);
		close(tab1[1]);
		close(tab2[1]);
		tab1[0] = tab2[0];
		i++;
	}
	copie(tab1[0],1);


	return 1;

}
