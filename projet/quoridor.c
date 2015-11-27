#include "fonction.h"

int main ()
{	
	init_graphics(l,l);
	
	JOUEUR j1,j2;
	POINT utilisateur;
	
	dessinePlateau();
	j1=initialisationJoueur(1);
	j2=initialisationJoueur(2);
	
	affichageJoueur(j1,j2);
	
	while(1)
	{
	utilisateur=wait_clic();
	j1.p=deplacementPion(j1.p,utilisateur);
	affichageJoueur(j1,j2);
	}
	
	attendre(5000);
	return 0;
}
