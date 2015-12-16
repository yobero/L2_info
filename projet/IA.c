#include "fonction.h"

int IAouJoueur(POINT utilisateur)
{
	if((utilisateur.x > IAHX0 && utilisateur.x < IABX0) && (utilisateur.y > IAHY0 && utilisateur.y < IABY0)) //0 pour IA
		return 0;
	if(utilisateur.x > IAHX1 && utilisateur.x < IABX1 && utilisateur.y > IAHY1 && utilisateur.y < IABY1) //1 pour Joueur
		return 1;
		
}

JOUEUR deplaceIA(JOUEUR IA,JOUEUR j)
{
	POINT utilisateur;
	
	if(!blocageBas(IA.p,j.m))
	{
		utilisateur.x = IA.p.centre.x; utilisateur.y = IA.p.centre.y-TAILLE;
		IA.p=deplacementPion(IA.p,j,utilisateur);
	}
	else if(!blocageGauche(IA.p,j.m))
		{
			utilisateur.x = IA.p.centre.x-TAILLE; utilisateur.y = IA.p.centre.y;
			IA.p=deplacementPion(IA.p,j,utilisateur);
		}
		else if (!blocageDroite(IA.p,j.m))
			{
				utilisateur.x = IA.p.centre.x+TAILLE; utilisateur.y = IA.p.centre.y;
				IA.p=deplacementPion(IA.p,j,utilisateur);	
			}
			else if (!blocageHaut(IA.p,j.m))
				{
					utilisateur.x = IA.p.centre.x; utilisateur.y = IA.p.centre.y+TAILLE;
					IA.p=deplacementPion(IA.p,j,utilisateur);
				}
	
	return IA;
}
