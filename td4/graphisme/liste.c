#include "graphics.h"

#define COUL_FOND  noir
#define LARGEUR    800
#define HAUTEUR    800

struct element{
  POINT p;
  struct element *suiv;
};
typedef struct element *Liste;

Liste ajoutDebut(Liste l, POINT p){
  Liste tmp = malloc(sizeof(struct element));
  tmp->p = p;
  tmp->suiv = l;
  return tmp;
}

Liste supprimeDebut(Liste l){
  Liste ll;
  if(l != NULL){
    ll = l;
    l = l->suiv;
    free(ll);
  }
  return l;
}


void dessineListeRec(Liste l){
  if(l != NULL){
    draw_fill_circle(l->p, 5, bleu);
    if(l->suiv != NULL)
      draw_line(l->p, l->suiv->p, rouge);
    dessineListeRec(l->suiv);
  }
}

void dessineListe(Liste l){
  fill_screen(COUL_FOND);
  dessineListeRec(l);
  affiche_all();
}
