#include "interface.h"

POINT localisationClic(POINT utilisateur);

int rechercheEmplacementMur(MUR m);

MUR placementMur(POINT p, POINT utilisateur, MUR m);

int chevauchement (POINT p, MUR m);

MUR ajoutMur (MUR m, POINT utilisateur);
