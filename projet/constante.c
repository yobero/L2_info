#include "graphics.h"

///constante pour variable

//Base
#define l  720//taille de la fenetre (un mutliple de 9)
#define MULTIPLE 9

//BOUTON
	///bouton sauvegarde
	#define SHX l+ED
	#define SHY l-l/3
	#define SBX (SHX + (4*PM-1))
	#define SBY SHY-PM

	///Bouton chargement
	#define CHX l+4*PM 
	#define CHY SHY
	#define CBX CHX + 5*PM
	#define CBY SBY
	
	///retour en arrière
	#define RAHX (SHX+((SBX-SHX)/2)) 
	#define RAHY SBY
	#define RABX (RAHX + (4*PM-1))
	#define RABY RAHY-PM
	
	#define ARCOUL black
	#define ARCOULB white
	
#define COUL1 0xe67e30
#define COUL2 0x3f2204
#define COULB white
	
//MESSAGE
#define POINTX (l+PM+1)
#define POINTY (l-(l/12))
#define POINTT TAILINTER+10 //La taille du texte
#define POINTC white

//Interface
#define INTERFACE l/2 // constante utiliser pour le deuxieme point de la fonction interface
#define COULI1 0x4e3d28
#define COULI2 0xad4f09
#define COULRESTE black
#define COULIT white
#define TAILINTER INTERFACE/25

#define M l/2 //millieu du plateau
#define TAILLE l/MULTIPLE //la taille de la case
#define PM  TAILLE/2 //distance Pion-Mur
#define EPAISSEUR 10 
#define ED (EPAISSEUR/2)

//constante commune
#define INIT 0 //valeur d'initialisation

#define NBM 10 //nb de murs
#define EM 10 //epaisseur du mur
#define LONGM (2*TAILLE) //longueur du mur
#define LARGM EPAISSEUR //largeur du mur
#define LIMITE PM/2

#define R (PM-ED-1) //rayon du pion

#define D (TAILLE+PM) //"mur" suivant

//#define NOIR black //pour effacer le pion

///pour le texte de fin
#define TFIN 38
#define FIN yellow

//constante J1
#define coulPJ1 blue
#define coulMJ1 darkblue //couleur des murs de J1
#define AIDEJ1 0x3498db

//constante J2
#define coulPJ2 red
#define coulMJ2 darkred
#define AIDEJ2 0xf1c40f //jaune

//contante pour couleur de la grille
#define GRILLE 0x2F1B0C
#define FE 0x703516
