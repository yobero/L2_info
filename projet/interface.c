#include "affichage.h"

void boutonTemporaire()
{
	///Bouton qui s"affiche au début du programme
		//jouer avec une IA ou un Joueur
		p1.x = IAHX; p1.y = IAHY;
		p2.x = IABX; p2.y = IABY;
		draw_fill_rectangle(p1,p2,COUL2);
		draw_rectangle(p1,p2,COUL1);
		p1.x = RAHX + ECART;
		aff_pol("Humain",TAILINTER,p1,COULB);
}

void bouton ()
{
	POINT p1,p2;
	
	//bouton sauvegarde
	p1.x = SHX+1; p1.y = SHY;
	p2.x = SBX; p2.y = SBY;
	draw_fill_rectangle(p1,p2,COUL2);
	draw_rectangle(p1,p2,COUL1);
	p1.x =SHX+2*ECART;
	aff_pol("sauvegarder",TAILINTER,p1,COULB);
	
	//bouton recup sauvegarde
	p1.x = CHX; p1.y =  CHY;
	p2.x = CBX; p2.y = CBY;
	draw_fill_rectangle(p1,p2,COUL2);
	draw_rectangle(p1,p2,COUL1);
	p1.x = CHX +ECART;
	aff_pol("Charger La sauvegarde",TAILINTER,p1,COULB);
	
	//bouton retour en Arriere
	p1.x = RAHX; p1.y = RAHY;
	p2.x = RABX; p2.y = RABY;
	draw_fill_rectangle(p1,p2,COUL2);
	draw_rectangle(p1,p2,COUL1);
	p1.x = RAHX + ECART;
	aff_pol("retour en arriere",TAILINTER,p1,COULB);
	
}

void message(int n)
{
	POINT p;
	p.x = POINTX; p.y = POINTY;
	if(n==1) //chargement
		aff_pol("Chargement termine",POINTT,p,POINTC);
	if(n==2)
		aff_pol("Partie sauvegarde",POINTT,p,POINTC);
	if(n==3)
		aff_pol("Retour en arriere",POINTT,p,POINTC);
	if (n==4)
		aff_pol("Plus de mur disponible",POINTT,p,POINTC);
}

void fenetreInterface(int quiJoue)
	{
		POINT p1,p2;
		p1.x = l+PM; p1.y = l-1;
		p2.x = (l+INTERFACE)-PM; p2.y = p1.x - l/4;
		draw_fill_rectangle(p1,p2,COULI2);
		draw_rectangle(p1,p2,COULI1);
		p1.x = p1.x +10;
		if (quiJoue==1)
			aff_pol("Au joueur 1 de jouer",TAILINTER,p1,COULIT);
		if (quiJoue == 2)
			aff_pol("Au joueur 2 de jouer",TAILINTER,p1,COULIT);
	}
	
	void interface(int quiJoue)
	{
		POINT p;
		//PARTIE POUR LE JOUEUR 1
		p.x = l+ED; p.y = l/4;
		aff_pol("Nombre de murs restants pour le joueur 1 :",TAILINTER,p,COULRESTE);
		
		//PARTIE POUR LE JOUEUR 2
		///p.y =(3*l)/4;
		aff_pol("Nombre de murs restants pour le joueur 2 :",TAILINTER,p,COULRESTE);
		
		fenetreInterface(quiJoue);
		bouton();
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
