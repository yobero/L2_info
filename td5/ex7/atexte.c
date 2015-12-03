#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 100

int alea ()
{
	int valeur;
		valeur=rand()%N;
		return valeur;
}

int main ()
{
	int c=0;
	int a;
	FILE* fichier = fopen("affichage.txt","w");
	
	while(c<1000000)
	{
		a=alea();
		fprintf(fichier,"%d\n",a);
		c++;
	}
	
	
	return 0;
}

