#include "fonction.h"

int main ()
{	
	init_graphics(l,l);
	
	JOUEUR j1,j2;
	
	dessinePlateau();
	j1=initialisationJoueur(1);
	j2=initialisationJoueur(2);
	
	affichageJoueur(j1,j2);
	
	attendre(5000);
	return 0;
}
