#include "fonction.h"

int main ()
{	
	init_graphics(l,l);
	
	JOUEUR j1,j2;
	POINT utilisateur;
	int quiJoue=1; //1 pour le joueur 1 et 2 pour j2
	
	dessinePlateau();
	j1=initialisationJoueur(1);
	j2=initialisationJoueur(2);
	
	affichageJoueur(j1,j2);
	
	while(finDePartie(j1,j2))
	{
		utilisateur=wait_clic();
		if (quiJoue==1)
		{
			j1.p=deplacementPion(j1.p,utilisateur,quiJoue);
			quiJoue = 2;
		}
		else
		{
			j2.p=deplacementPion(j2.p,utilisateur,quiJoue);
			quiJoue = 1;
		}
		affichageJoueur(j1,j2);
	}
	
	attendre(5000);
	return 0;
}
