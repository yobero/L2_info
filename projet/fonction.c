#include "constante.c"

//STRUCTURE
struct pion {
	POINT centre;
	int rayon;
	COULEUR coul;
};
typedef struct pion PION;

struct mur {
	POINT tab[NBM][NBM]; //tableau pour stocker deux points pour les murs
	COULEUR coul;
};
typedef struct mur MUR;

struct joueur {
	PION p;
	MUR m;
 };
typedef struct joueur JOUEUR;

//FONCTION

void dessinePlateau()// La fonction va déssiner le plateau du jeu
{
	POINT p1,p2;
	
	p1.x = 0; p1.y = 0;
	p2.x = p1.x; p2.y = l;
	
	while (p1.x < l)
	{
		draw_line(p1,p2,GRILLE);
		p2.x = p1.x = p1.x + TAILLE;
	}
	p2.y=p1.x = 0;
	p2.x = l;
	
	while (p1.y < l)
	{
		draw_line (p1,p2,GRILLE);
		p2.y = p1.y = p1.y + TAILLE;
	}
	
}
