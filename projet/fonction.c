	#include "pion.h"
	
	//FONCTION
	
	int finDePartie(JOUEUR j1, JOUEUR j2)
	{
		POINT t;
		t.x = 2*ED; t.y = M+TAILLE;
		
		if (j1.p.centre.y == l-PM)
		{
			aff_pol("Partie terminer, Le joueur 1 a gagne", TFIN, t, FIN);
			return 0;
		}
		if (j2.p.centre.y == PM)
		{
			aff_pol("Partie terminer, Le joueur 2 a gagne", TFIN, t, FIN);
			return 0;
		}
		
		return 1;
	}
	
	void recuperationSauvegarde(JOUEUR* j1, JOUEUR* j2)
	{
		
	}
	
	int sauvegarde ()
	{
		
	}
	
	//MUR OU PION
	
	int Pion (POINT utilisateur)
	{
		int i,j;
		
		i=j=0+PM; //centre de la case
		
		while(i<l)
		{
			while(j<l)
			{
				if (utilisateur.x > i-PM+ED && utilisateur.x < i+PM-ED)
					return 1;
				if (utilisateur.y > j-PM+ED && utilisateur.y < j+PM-ED)
					return 1;
				
				j=j+TAILLE;
			}
			j=0+PM;
			i=i+TAILLE;
		}
		
		return 0;
	}
	
	int Mur (POINT utilisateur)
	{
		int i,j;
		
		i=j=0+PM;
		
		while(i<l)
		{
			while(j<l)
			{
				if (utilisateur.x > i+PM-ED && utilisateur.x < i+PM+ED) ///vers la gauche
					return 1;
				if (utilisateur.x > i-PM-ED && utilisateur.x < i-PM+ED) ///vers la droite
					return 1;
				if (utilisateur.y > i+PM-ED && utilisateur.y < i+PM+ED) ///vers le haut
					return 1;
				if (utilisateur.y > i-PM-ED && utilisateur.y < i-PM+ED) ///vers le bas
					return 1;
				
				j=j+TAILLE;
			}
			j=0+PM;
			i=i+TAILLE;
		}
		
		return 0;
	}
	
	JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue)
	{
		if (Mur(utilisateur))
			j.m = ajoutMur(j.m,utilisateur);
		else
		{
			if (Pion(utilisateur))
				j.p = deplacementPion(j.p,a,utilisateur,quiJoue);
		}
		
		
		return j;
	}
	
