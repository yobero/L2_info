#include "graphics.h"

//constante pour variable
#define l  720//taille de la fenetre (un mutliple de 9)
#define MULTIPLE 9
#define M l/2 //millieu du plateau
#define TAILLE l/MULTIPLE //la taille de la case
#define PM  TAILLE/2 //distance Pion-Mur

//constante commune
#define INIT -1 //valeur d'initialisation

#define NBM 10 //nb de murs
#define EM 10 //epaisseur du mur
#define TM (2*TAILLE) //longueur du mur
#define LIMITE PM/2

#define R (PM-(PM/2)) //rayon du pion
#define D (TAILLE+PM) //"mur" suivant

#define NOIR black //pour effacer le pion

///pour le texte de fin
#define TFIN 38
#define FIN green

//constante J1
#define coulPJ1 blue
#define coulMJ1 darkblue //couleur des murs de J1

//constante J2
#define coulPJ2 red
#define coulMJ2 darkred

//contante pour couleur
#define GRILLE white
