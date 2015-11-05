#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ce programme est un programme de merde que jq'ai fait quand je me
 * faisais chier :D*/
 
 ///Ici se trouve les constantes
 #define PRIO 10 //nombre de proirité
 #define VAL 100
 
 
///Ici se trouve les structures
struct requette {
	int priorite;
	int val;
};
typedef struct requette Requette;

struct Element {
	Requette req;
	struct Element* suiv;
};
typedef struct Element* liste;

///Fonction du programme
int alea(int v) // Cette fonction va servir à mettre une valeur  à la priorité et à la valeur
{
  return rand()%v;
}

liste initialisationListe()
{
	return NULL;
}

liste ajout(liste l, Requette x)
{
	liste ele;
	
	ele->req.priorite = x.priorite;
	ele->req.val = x.val;
	ele->suiv = l;
	
	return ele;
}

Requette creationRequette()
{
	Requette r;
	
	r.priorite = alea(PRIO);
	r.val = alea(VAL);
	
	printf("prio val\n");
	printf("%d   %d\n",r.priorite, r.val);
	
	return r;
}

void simulation()
{
	liste l;
	Requette r;
	int i=0;
	
	l=initialisationListe();
	while(50)
	{
		r=creationRequette();
		//l=ajout(l,r);
		
		i++;
	}
}

int main()
{
	simulation();
	
	return 0;
}
