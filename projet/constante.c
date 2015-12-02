#include "graphics.h"

///constante pour variable

//Base
#define l  720//taille de la fenetre (un mutliple de 9)
#define MULTIPLE 9
#define M l/2 //millieu du plateau
#define TAILLE l/MULTIPLE //la taille de la case
#define PM  TAILLE/2 //distance Pion-Mur
#define EPAISSEUR 10 
#define ED (EPAISSEUR/2)

//constante commune
#define INIT -1 //valeur d'initialisation

#define NBM 10 //nb de murs
#define EM 10 //epaisseur du mur
#define LONGM (TAILLE) //longueur du mur
#define LARGM EPAISSEUR //largeur du mur
#define LIMITE PM/2

#define R (PM-ED-1) //rayon du pion

#define D (TAILLE+PM) //"mur" suivant

#define NOIR black //pour effacer le pion

///pour le texte de fin
#define TFIN 38
#define FIN green

//constante J1
#define coulPJ1 blue
#define coulMJ1 darkblue //couleur des murs de J1
#define AIDEJ1 0x3498db

//constante J2
#define coulPJ2 red
#define coulMJ2 darkred
#define AIDEJ2 0xf1c40f //jaune

//contante pour couleur de la grille
#define GRILLE white
#define FE 0x95a5a6 ///gris concrete
