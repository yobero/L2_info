#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*AU debut du programme, on doit donner le nombre de chiffre composant
 * le nombre à convertir (CE NOMBRE SERA LA TAILLE DU TABLEAU).
 * L'utilisateur doit ensuite mettre chaque chiffre du nombre dans chaque
 * case du tableau.
 * L'utilisateur doit mettre le base du nombre puis la base de convertion.
 * Et voile le resultat */

struct element {
	int val;
	struct element* suiv;
};
typedef struct element Element;
typedef Element* Liste;

Liste initialisationListe()
{
	return NULL;
}

int main ()
{
	int taille; ///La taille du nombre (nb de chiffre)
	int base; ///La base du nombre de départ
	int nBase; ///La base de convertion;
	Liste l; ///Liste contenant le nombre converti
	l=initialisationListe();
	
	printf("Combien y a t-il de chiffre dans votre nombre ?  ");
	scanf("%d",&taille);
	
	char** T;
	
	printf("Donner votre nombre\n");
	scanf("%c",&T);
	
	printf("A quelle base est votre de nombre ?  ");
	scanf("%d",&base);
	printf("A quele base voulez-vous le convertir ?  ");
	scanf("%d",&nBase);
	
	return 0;
}
