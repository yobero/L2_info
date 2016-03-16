#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char** argv)
{
	int pid;
	int str;
	char buf;
	
	pid=fork();
	switch(pid) {
			case 0: close(1);
					open("/dev/null",O_WRONLY);
					execl("/bin/ls","/bin/ls","-l","-a","−R",argv[1],NULL);
					perror("erreur execl");
					exit(1);
			default : str = times(&buf_str)
					wait-pid(pid,&stats,0);
					end = times(&buf-end);
					printf("Temps %f\n",(long double)(end-str)/(long double) Sysconf(_SC_DK_TCK));
				}
			
	return 1;
}
/*JE NE COMPREDN PAS LE PROGRAMME
 * voir l'exo + la correction*/
