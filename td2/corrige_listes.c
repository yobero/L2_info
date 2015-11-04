#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/**************  Définition des structures ***************/

struct element{
  int val;
  struct element* suiv;
};
typedef struct element Element;

typedef Element* Liste;

int alea(int n){
  return rand()%n;
}


Liste ajout(Liste l, int c){
  if(l == NULL){
    Element* pElt = malloc(sizeof(Element));
    pElt->val = c;
    pElt->suiv = l;
    l = pElt;
  }
  else
    l->suiv = ajout(l->suiv, c);
  return l;
}



Liste remplitListe(Liste l, int n){
  int e = alea(n);
  while(e != 0){
    l = ajout(l,e);
    e = alea(n);
  }
  return l;
}


void affiche(Liste l){
  if(l == NULL)
    printf("\n");
  else{
    printf("%d ", l->val);
    affiche(l->suiv);
  }
}

Liste entrelace(Liste l1, Liste l2){
  if(l1 == NULL)
    return l2;
  if(l2 == NULL)
    return l1;
  if(l1->val < l2->val){
    l1->suiv = entrelace(l1->suiv, l2);
    return l1;
  }
  l2->suiv = entrelace(l1, l2->suiv);
  return l2;
}


int nbElements(Liste l){
  if(l == NULL) return 0;
  else return 1 + nbElements(l->suiv);
}

//pour tri fusion, 1 element sur 2 dans chaque liste
void decoupe(Liste l, Liste* l1, Liste* l2, int ordre){
  Liste tmp;
  if(l != NULL){
    if(ordre == 0){
      tmp = *l1;
      *l1 = l;
      l = l->suiv;
      (*l1)->suiv = tmp;
    }
    else{
      tmp = *l2;
      *l2 = l;
      l = l->suiv;
      (*l2)->suiv = tmp;
    }
    ordre = 1 - ordre;
    decoupe(l, l1, l2, ordre);
  }
}


//tri fusion
Liste tri(Liste l){
  Liste l1 = NULL;
  Liste l2 = NULL;
  if(l != NULL && l->suiv != NULL){
    decoupe(l, &l1, &l2, 0);
    l1 = tri(l1);
    l2 = tri(l2);
    l = entrelace(l1, l2);
  }
  return l;
}


//supprime les multiples de v dans l
Liste supprime(Liste l, int v){
  Liste tmp;
  if(l != NULL){
    if(l->val % v == 0){
      tmp = l;
      l = l->suiv;
      free(tmp);
      l = supprime(l, v);
    }
    else
      l->suiv = supprime(l->suiv, v);
  }
  return l;
}


Liste eratos(Liste l){
  int v;
  affiche(l);
  if(l != NULL && l->suiv != NULL){
    v = l->val;
    l->suiv = supprime(l->suiv, v);
    l = eratos(l->suiv);
  }
  return l;
}


void remplitTab(Liste l, Liste* tab, int k){
  if(l != NULL){
    tab[l->val%k] = ajout(tab[l->val%k], l->val);
    remplitTab(l->suiv, tab, k);
  }
}

Liste* classe(Liste l, int k){
  Liste* tab = malloc(k*sizeof(Liste));
  int i;
  for(i=0; i<k; i++)
    tab[i] = NULL;
  remplitTab(l, tab, k);
  return tab;
}


/*************  Fonction main *******************************/

int main(int argc, char** argv){
  Liste l = NULL;
  int i;
  Liste* tab;
  srand(time(NULL));

  //decommenter pour tester
  /*
  l = remplitListe(l, 100);
  affiche(l);
  l = tri(l);
  affiche(l);
  */

  /*
  for(i=2; i<1000; i++)
    l = ajout(l, i);
  affiche(l);
  eratos(l);
  affiche(l);
  */
   /*
  l = remplitListe(l, 100);
  affiche(l);
  tab = classe(l,10);
  for(i=0; i<10; i++)
    affiche(tab[i]);
  */


  return 0;
}






