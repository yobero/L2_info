#include "affichage.h"

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
