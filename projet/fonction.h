#include "structure.c"

void dessinePlateau(); // La fonction va déssiner le plateau du jeu

int finDePartie(JOUEUR j1, JOUEUR j2);

//INITIALISATION

PION initialisationPion(int a);

MUR initialisationMur(int a);

JOUEUR initialisationJoueur(int a);

//AFFICHAGE

void affichagePion(PION p1,PION p2);

void effacePion(JOUEUR j1, JOUEUR j2);

void affichageMur(MUR m1, MUR m2);

void effaceMur(MUR m1, MUR m2);

void affichageJoueur(JOUEUR j1,JOUEUR j2);

//DEPLACEMENT

PION deplacementPion(PION p,PION a,POINT utilisateur,int quiJoue);

//AJOUT MUR

POINT localisationClic(POINT utilisateur);

int rechercheMur(MUR m);

MUR placementMur(POINT p, POINT utilisateur, MUR m);

MUR ajoutMur (MUR m, POINT utilisateur);

//MUR OU PION

int Pion (POINT utilisateur);

int Mur (POINT utilisateur);

JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue);
