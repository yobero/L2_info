#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/**size=fwrite (void * ptr, size_t size, size_t mnomb, FILE* stream)
 * mnomb == nombre d'element
 * size = taille de l'élément (en octet) 
 * ptr = point où écrire*/
 
int main ()
{
	char lol=97;
	int n=0;
	size_t size = sizeof(char);
	size_t mnomb = 1;
	FILE* fichier = fopen("affichage.txt","w"); 
	
	//lettre minuscule
	while (lol < 123)
	{
		fwrite(&lol,size,mnomb,fichier);
		lol++;
	}
	lol=65;
	//lettre majuscule
	while (lol<91)
	{
		fwrite(&lol,size,mnomb,fichier);
		lol++;
	}
	 lol='\n';
	//\n
	fwrite(&lol, size,mnomb,fichier);
	
	//Nombre
	while (n<=999)
	{
		fwrite(&n, size,mnomb,fichier);
		n++;
	}
	
	fclose(fichier);
	return 0;
}
