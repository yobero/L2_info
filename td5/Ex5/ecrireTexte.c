#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main ()
{
	char lol=97;
	int n=0;
	FILE* fichier = fopen("affichage.txt","w"); 
	
	//lettre minuscule
	while (lol < 123)
	{
		fprintf(fichier,"%c",lol);
		lol++;
	}
	fprintf(fichier,"\n");
	lol=65;
	//lettre majuscule
	while (lol<91)
	{
		fprintf(fichier,"%c",lol);
		lol++;
	}
	printf("\n");
	
	//Nombre
	while (n<=999)
	{
		fprintf(fichier, "%4d", n);
		if (n%10 == 0)
			fprintf(fichier, "\n");
		n++;
	}
	
	
	fclose(fichier);
	return 0;
}
