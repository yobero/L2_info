#include "graphics.h"
#include "liste.c"
#include "simul.c"

// ############################
// 1. Les structures de données
// ############################

#define LARGEUR    800
#define HAUTEUR    800


// ############################
// 2. Fonctions listes chainees
// ############################


// ############################
// 3. Simulation
// ############################




// ##########
// 4. Le main
// ##########

int main(){

  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
  fill_screen(COUL_FOND);
  affiche_all();

  simulChaine();

	printf("%d \n",NB_POINTS);

  wait_escape();
  return 0;
}
