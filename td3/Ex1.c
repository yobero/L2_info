#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* argc un tableau de chaine de caractère
 * argc la taille du tableau */
///Voir une autre ligne de commande pour windows.

int main( int argc, char** argv)
{
	int i;
	for(i=0; i<argc; i++)
		printf("%s\n", argv[i]);
	return 0;
}

/* De base un talbeau est un pointeur donc char* mais argv est un pointeur du tableau
 * donc pointeur de pointeur d'ou char**. */

/* faire un main 3 atof (si ça marche) sur le PC. */

/* Faire de même pour cette question. */
