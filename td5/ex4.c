#include <sys/types.h>
#include <sys/stat.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE_BUF 1024

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
	int tab[2];
	pid_t pid;
	pipe(tab);
		
	pid =fork();
	
	if(pid) {//lire l'info
		close(tab[0]);
		copie(0,tab[1]);
		close(tab[1]);
	}
	else {//afficher l'info
		close(tab[1]);
		copie(tab[0],1);
		close(tab[0]);
	}
	return 1;
}
