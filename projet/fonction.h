#include "pion.h"

int finDePartie(JOUEUR j1, JOUEUR j2);

//SAUVEGARDE

void sauvegarde(JOUEUR j1,JOUEUR j2);

int faireSauvegarde(POINT utilisateur);

void chargement(JOUEUR* j1, JOUEUR* j2);

int recuperationSauvegarde(POINT utilisateur);

//RETOUR EN ARRIERE
void retourArriereSauv(JOUEUR j1,JOUEUR j2);

void retourArriereCharge(JOUEUR* j1, JOUEUR* j2);

int recuperationRetourArriere(POINT utilisateur);

//MUR OU PION

int Pion (POINT utilisateur);

int Mur (POINT utilisateur);

JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue);
