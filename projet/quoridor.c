#include "fonction.h"

int main ()
{	
	init_graphics(l+INTERFACE,l);
	affiche_auto_off();
	
	JOUEUR j1,j2;
	POINT utilisateur;
	int quiJoue=1; //1 pour le joueur 1 et 2 pour j2
	
	j1=initialisationJoueur(1);
	j2=initialisationJoueur(2);
	sauvegarde(j1,j2);
	
	affiche_auto_off();
	while(finDePartie(j1,j2))
	{
		dessinePlateau(quiJoue);
		affichageJoueur(j1,j2);
		
		utilisateur=wait_clic();
		if(recuperationSauvegarde(utilisateur))
			chargement(&j1,&j2);
			
		printf("%d %d ",j1.p.centre.x ,j1.p.centre.y);
			
		if(faireSauvegarde(utilisateur))
			sauvegarde(j1,j2);
		
		if (quiJoue==1)
		{
			j1= murOuPion(j1,j2,utilisateur,quiJoue);
			quiJoue = 2;
		}
		else
		{
			j2= murOuPion(j2,j1,utilisateur, quiJoue);
			quiJoue = 1;
		}
		affichageJoueur(j1,j2);
	}
	
	affiche_all();
	attendre(5000);
	return 0;
}
