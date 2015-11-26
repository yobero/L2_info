#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int argc, char** argv)
{
	FILE* fichier = fopen(argv[1],"r");
	int compteur=0;
	
	while (fgetc(fichier) != EOF)
		compteur++;
		
	printf("Il y a  %d dans tion fichier.\n",compteur);
	
	return 0;
}
