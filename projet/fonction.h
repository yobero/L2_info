#include "structure.c"

void dessinePlateau(); // La fonction va déssiner le plateau du jeu

int finDePartie(JOUEUR j1, JOUEUR j2);

PION initialisationPion(int a);

MUR initialisationMur(int a);

JOUEUR initialisationJoueur(int a);

void affichagePion(PION p1,PION p2);

void affichageMur(MUR m1, MUR m2);

void affichageJoueur(JOUEUR j1,JOUEUR j2);

PION deplacementPion(PION p,POINT utilisateur);

