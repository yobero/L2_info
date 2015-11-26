#include "constante.c"

//STRUCTURE
struct pion {
	POINT centre;
	int rayon;
	COULEUR coul;
};
typedef struct pion PION;

struct mur {
	POINT tab[NBM][2]; //tableau pour stocker deux points pour les murs
	COULEUR coul;
	int reste; //nb de mur a ajouté
};
typedef struct mur MUR;

struct joueur {
	PION p;
	MUR m;
 };
typedef struct joueur JOUEUR;
