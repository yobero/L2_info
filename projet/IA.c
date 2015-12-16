#include "fonction.h"

int IAJoueur(POINT utilisateur)
{
	if(utilisateur.x < l/2) //0 pour IA
		return 0;
		
	return 1;
		
}

JOUEUR deplaceIA(JOUEUR IA,JOUEUR j)
{
	POINT utilisateur;
	
	if(blocageBas(IA.p,j.m))
	{
		utilisateur.x = IA.p.centre.x; utilisateur.y = IA.p.centre.y-TAILLE;
		IA.p=deplacementPion(IA.p,j,utilisateur);
	}
	else if(blocageGauche(IA.p,j.m))
		{
			utilisateur.x = IA.p.centre.x-TAILLE; utilisateur.y = IA.p.centre.y;
			IA.p=deplacementPion(IA.p,j,utilisateur);
		}
		else if (blocageDroite(IA.p,j.m))
			{
				utilisateur.x = IA.p.centre.x+TAILLE; utilisateur.y = IA.p.centre.y;
				IA.p=deplacementPion(IA.p,j,utilisateur);	
			}
			else if (blocageHaut(IA.p,j.m))
				{
					utilisateur.x = IA.p.centre.x; utilisateur.y = IA.p.centre.y+TAILLE;
					IA.p=deplacementPion(IA.p,j,utilisateur);
				}
	
	return IA;
}

JOUEUR placementIA(JOUEUR IA,JOUEUR j)
{
	int i=0;
	POINT utilisateur;
	
	//fonction non fini
	
	return IA;
}
