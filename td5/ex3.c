#include <sys/types.h>
#include <sys/stat.h>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

/** Signal :
 * 			↓ processus
 * 			↓
 * →→→→→→→→→_ →→→→→→→handler
 * signal	↑←←←←←		↓
 * 					←←←	↓ si exit() le processus s'arrete
*/
/* sigsegv ==> segmentation fault (violation des protections mémoire
 * sigaction(SIGALARM,&Sa,NULL);
 * */
#define BUFFER 1024
int taille;

void afficher(int a)
{
	printf("%d\n",taille);
	exit(0);
}

int main (){
	int B[2];
	pipe(B);
	char* C;
	struct sigaction Sa;
	sigemptyset(&Sa.sa_mask);
	Sa.sa_flags = 0;
	Sa.sa_handler = afficher;
	
	sigaction(SIGALRM,&Sa,NULL);
	
	while(1) {
		alarm(1);
		write(B[1],C,BUFFER);
	}
	return 1;
}

