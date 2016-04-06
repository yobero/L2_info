#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE_BUF 1024

void copie (int s,int d) {
	int n;
	char[SIZE_BUF];
	while ((n=read(s,buf,SIZE_BUF))>0) {
		if (write(d,buf,n != n) {
			perror("Impossible d'écrire");
			exit(EXIT_FAILURE);
		}
	}
	if(n!=0) {
		perror("Impossible de lire");
		exit(EXIT_FAILURE);
	}
}
