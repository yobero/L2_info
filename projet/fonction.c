#include "pion.h"

//FONCTION

void fenetreInterface(int quiJoue)
{
	POINT p1,p2;
	p1.x = l+PM; p1.y = (l/4)+(l/3);
	p2.x = (l+INTERFACE)-PM; p2.y = ((3*l)/4)-(l/3);
	draw_fill_rectangle(p1,p2,SLCOUL);
	
	if (quiJoue==1)
		aff_pol("Au joueur 1 de jouer",TAILINTER,p1,white);
	if (quiJoue == 2)
		aff_pol("Au joueur 2 de jouer",TAILINTER,p1,white);
}

void interface(int quiJoue)
{
	POINT p;
	//PARTIE POUR LE JOUEUR 1
	p.x = l+ED; p.y = l/4;
	aff_pol("Nombre de murs restants pour le joueur 1 :",TAILINTER,p,COULI);
	
	//PARTIE POUR LE JOUEUR 2
	p.y =(3*l)/4;
	aff_pol("Nombre de murs restants pour le joueur 2 :",TAILINTER,p,COULI);
	
	fenetreInterface(quiJoue);
}

void dessinePlateau(int quiJoue)// La fonction va déssiner le plateau du jeu
{
	POINT p1,p2;
	
	fill_screen(FE);
	interface(quiJoue);
	
	p1.x = 0-ED; p1.y = 0;
	p2.x = p1.x+EPAISSEUR; p2.y = l;
	
	while (p1.x < l)
	{
		draw_fill_rectangle(p1,p2,GRILLE);
		p1.x = p1.x + TAILLE;
		p2.x = p1.x + EPAISSEUR;
	}
	p1.x = 0;
	p1.y =0 -ED;
	p2.y=p1.x+EPAISSEUR;
	p2.x = l;
	
	while (p1.y < l)
	{
		draw_fill_rectangle (p1,p2,GRILLE);
		p1.y = p1.y + TAILLE;
		p2.y = p1.y + EPAISSEUR;
	}
	
}

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
