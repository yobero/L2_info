#include "graphics.h"

//constante pour variable
#define l  720//taille de la fenetre (un mutliple de 9)
#define M l/2 //millieu du plateau
#define TAILLE l/9 //la taille de la case
#define PM  TAILLE/2 //distance Pion-Mur

//constante commune
#define INIT -1 //valeur d'initialisation
#define NBM 10 //nb de murs
#define R PM-1 //rayon du pion
#define D TAILLE+PM //"mur" suivant

//constante J1
#define coulPJ1 blue
#define coulMJ1 darkblue //couleur des murs de J1

//constante J2
#define coulPJ2 red
#define coulMJ2 darkred

//contante pour couleur
#define GRILLE white
