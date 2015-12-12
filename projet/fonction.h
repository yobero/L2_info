#include "pion.h"

int finDePartie(JOUEUR j1, JOUEUR j2);

void sauvegarde(JOUEUR j1,JOUEUR j2);

void chargement(JOUEUR* j1, JOUEUR* j2);

int recuperationSauvegarde(POINT utilisateur);

//MUR OU PION

int Pion (POINT utilisateur);

int Mur (POINT utilisateur);

JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue);
