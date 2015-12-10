#include "pion.h"

void fenetreInterface(int quiJoue);

void interface(int quiJoue);

void dessinePlateau(int quiJoue); // La fonction va déssiner le plateau du jeu

int finDePartie(JOUEUR j1, JOUEUR j2);

//MUR OU PION

int Pion (POINT utilisateur);

int Mur (POINT utilisateur);

JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue);
