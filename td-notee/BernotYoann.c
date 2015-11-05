#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************  Constantes   *****************************/
#define NbPriorite 10    //nombre total de priorités
#define Nmax       8    //nombre de requêtes générées


/**************  Définition des structures ***************/

struct requete{
  int numero;    // numéro de la requête
  int priorite;  // priorité de la requête
};
typedef struct requete Requete;



/* Définir ici la structure Fap1 et Fap2 */

struct fap1 {
	Requete req;
	struct fap1* suiv;
};
typedef struct fap1* Fap1;

struct Fap2 {
	
	
	
};
typedef struct Fap2 Fap2;

/* à compléter */


/**************  Fonctions de manipulation des structures *******/

// file initialisée vide
Fap1 initialiseFile1(){
  return NULL;
}

// file initialisée vide
Fap2 initialiseFile2(){
  /* à compléter */
}

void afficheFile1(Fap1 f){
	 if(f == NULL)
		printf("\n");
	else{
		printf("Prio num\n");
		printf("%d    %d \n", (f->req).priorite, (f->req).numero);
		afficheFile1(f->suiv);
	}
}

void afficheFile2(Fap2 f){
  /* à compléter */
}


 Fap1 ajoutFile1(Fap1 f, Requete r){
	
    if(f == NULL){
		Fap1 Elt = malloc(sizeof(Fap1));
		Elt->req = r;
		Elt->suiv = f;
		f = Elt;
		return f;
	}
	f->suiv = ajoutFile1(f->suiv, r);
		
	return f;
}



Fap2 ajoutFile2(Fap2 f, Requete r){
  /* à compléter */
}


Fap1 traiteRequete1(Fap1 f){
	Fap1 t,tmp; //t ==> permettre de localiser la plus grande valeur et tmp sauvegarde la plus grande trouver
	Fap1 prec;
	tmp=f;
	t=f;
	prec=t;
	
	if(f==NULL && f->suiv == NULL)
		return f;
	else
	{
		/*while (tmp!=NULL)//recherche de la première plus grande priorité dans la liste
		{
			if ((tmp->req.priorite) > (t->suiv->req.priorite))
			{
				prec=t;
				t=tmp;
			}
			tmp=tmp->suiv;
		}
		if (t == f)
			f=f->suiv;
		else
			prec->suiv = t->suiv;
		
		free(t);*/
	}
	
	return f;
}


Fap2 traiteRequete2(Fap2 f){
    /* à compléter */
}



void libereMemoire1(Fap1 f){
  free(f);
}

void libereMemoire2(Fap2 f){
  /* à compléter */
}





/************** Génération des requêtes pour simulation *****************/

//retourne un entier aléatoire entre 0 et n-1
int alea(int n){
  return rand()%n;
}

Requete generationRequete(){
  static int numero = 0;
  Requete r;
  numero++;
  r.numero = numero;
  r.priorite = alea(NbPriorite);
  return r;
}



/************ Simulation file *****************************/


//structure 1
void simulationFile1(){
  Fap1 f1 = initialiseFile1();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f1 = traiteRequete1(f1);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f1 = ajoutFile1(f1, r);
    }
    afficheFile1(f1);
  }
  libereMemoire1(f1);
  printf("#######################################\n");
}


//structure 2
void simulationFile2(){
  Fap2 f2 = initialiseFile2();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f2 = traiteRequete2(f2);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f2 = ajoutFile2(f2, r);
    }
    afficheFile2(f2);
  }
  libereMemoire2(f2);
  printf("########################################\n");
}


/*************  Fonction main *******************************/

int main(){
  srand(time(NULL));

  /********  à décommenter pour lancer une simulation *********/
  simulationFile1();
    
  //simulationFile2();


  
  return 0;
}






