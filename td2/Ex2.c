#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 //valeur max pour la fonction alea

struct tableau {
	int TAILLE;
	int tab[100];
};
typedef struct tableau TABLEAU ;

int alea ()
{
	int valeur;
		valeur=rand()%N;
		return valeur;
}

void affichage(TABLEAU T)
{
	int i=0;
	
	while(i<T.TAILLE)
	{
		printf("%d  ",T.tab[i]);
		
		i=i+1;
	}
	printf("\n");
}

TABLEAU initialisation(TABLEAU T)
{
	int i=0;
	
	T.TAILLE=10;
	
	while (T.TAILLE > i)
	{
		T.tab[i]=alea();
		
		i=i+1;
	}
	
	return T;
}

int main()
{
	TABLEAU T;
	
	//Initialisation pour la fonction aleatoire
	srand(time(NULL));
	
	T=initialisation(T);
	affichage(T);
	
	return 0;
}
