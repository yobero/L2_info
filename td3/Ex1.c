#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/* argc un tableau de chaine de caractère
 * argc la taille du tableau */

int test(char* x)
{
	int t;
	
	t=isdigit(x);
	return t;
}

int main( int argc, char** argv)
{
	double som=0; ///La fonction atof renvoie un double.
	int t;
	
	int i;
	
	for(i=0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
		t=test(argv[i]);
		printf("T vaut %d \n",t);
		if(t)
			som = som + atof(argv[i]); /// Fonctionnne seulement si argbv[i] est un nombre.
	}
	printf("somme = %lf \n",som);
	return 0;
}

/* char** est un tableau de chaine de caractère. */

/* faire un main 3 atof (si ça marche) sur le PC. */

/* Faire de même pour cette question. */
