#include "IA.h"

int main ()
{	
	init_graphics(l+INTERFACE,l);
	
	JOUEUR j1,j2;
	POINT utilisateur;
	int quiJoue=1; //1 pour le joueur 1 et 2 pour j2
	int IaOuJoueur; // pour IA et  pour joueur
	
	j1=initialisationJoueur(1);
	j2=initialisationJoueur(2);
	
	//Pour eviter des bugs
		///Le fichier de sauvegarde ne s'effacera plus avec "make clean"
	//sauvegarde(j1,j2); //initialisation du fichier
	retourArriereSauv(j1,j2); //initialisation du fichier
	
	boutonTemporaire();
	utilisateur = wait_clic();
	IaOuJoueur = IAJoueur(utilisateur);
	
	affiche_all();
	affiche_auto_off();
	while(finDePartie(j1,j2))
	{
		dessinePlateau(quiJoue);
		affichageJoueur(j1,j2);
		affiche_all();
		
		if(recuperationSauvegarde(utilisateur))
		{
			chargement(&j1,&j2,&quiJoue);
			dessinePlateau(quiJoue);
			affichageJoueur(j1,j2);
			message(1); //affiche le message "chargement terminé"
			affiche_all();
			utilisateur=wait_clic();
		}
			
		if(faireSauvegarde(utilisateur))
		{
			sauvegarde(j1,j2);
			message(2); //affiche le message "sauvegarde terminé"
			affiche_all();
			utilisateur=wait_clic();
		}
		
		if(recuperationRetourArriere(utilisateur))
		{
			retourArriereCharge(&j1,&j2);
			dessinePlateau(quiJoue);
			affichageJoueur(j1,j2);
			message(3);
			affiche_all();
		}
		retourArriereSauv(j1,j2);
		
		if (quiJoue==1)
		{
			utilisateur=wait_clic();
			j1= murOuPion(j1,j2,utilisateur);
			quiJoue = 2;
		}
		else
		{
			if (IaOuJoueur)
			{
				utilisateur=wait_clic();
				j2= murOuPion(j2,j1,utilisateur);
			}
			else
			{
				j2 = deplaceIA(j2,j1);
			}
			quiJoue = 1;
		}
		dessinePlateau(quiJoue);
		affichageJoueur(j1,j2);
	}
	affiche_all();
	attendre(5000);
	return 0;
}
