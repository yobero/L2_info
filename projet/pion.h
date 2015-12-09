#include "mur.h" 

int blocageHaut(PION j1, MUR j2);

int blocageDroite(PION j1, MUR j2);

int blocageGauche(PION j1, MUR j2);

int blocageBas(PION j1, MUR j2);

int blocage(PION j1, MUR j2, int f);

PION deplacementPion(PION p,JOUEUR a, POINT utilisateur,int quiJoue);
