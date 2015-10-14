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

void produit(TABLEAU T)
{
	int i=0;
	long int c=1;
	
	while (i<T.TAILLE)
	{
		c = c *T.tab[i];
		
		i=i+1;
	}
	
	printf("Le produit du tableau est %ld \n",c);
}

void minimum(TABLEAU T)
{
	int c = T.tab[0];
	int i=1;
	
	while (i<T.TAILLE)
	{
		if (c>T.tab[i])
			c=T.tab[i];
		
		i=i+1;
	}
	printf("La plus petite valeur du tableau est %d \n",c);
}

TABLEAU decalage(TABLEAU T, int l,int s)
{
	int i;
	
	if (s==0)
	{
		T.TAILLE = T.TAILLE + 1;
		i=T.TAILLE-1;
		
		while(i-1>=l)
		{
			T.tab[i]=T.tab[i-1];
		
			i--;
		}
		T.tab[0]=0;
	}
	else
	{	
		while(l<T.TAILLE)
		{
			T.tab[l]=T.tab[l+1];
		
			l++;
		}
		T.TAILLE = T.TAILLE - 1;
	}
	
	return T;
}

TABLEAU tri(TABLEAU T)
{
	int i=T.TAILLE-1;
	int tmp;
	int l=0;
	
	while (l<T.TAILLE)
	{
		while(i-1>=l)
		{
			if (T.tab[i-1]>T.tab[i])
			{
				tmp=T.tab[i];
				T.tab[i]=T.tab[i-1];
				T.tab[i-1]=tmp;
			}
			
			i=i-1;
		}
		i=T.TAILLE-1;
		l++;
	}
	
	return T;
}

TABLEAU insertion(TABLEAU T, int valeur)
{
	int i=0;
	
	//localisation
	while (valeur>T.tab[i])
		i=i+1;
	
	T=decalage(T,i,0); //La fonction decalage augmente la TAILLE  de 1
	
	T.tab[i]=valeur;
	
	return T;
}

TABLEAU inverstion (TABLEAU T)
{
	int i=0;
	int j=T.TAILLE-1;
	int tmp;
	
	while (i<j)
	{
		tmp=T.tab[i];
		T.tab[i]=T.tab[j];
		T.tab[j]=tmp;
		
		j--;
		i++;
	}
	
	
	return T;
}

TABLEAU  suppression(TABLEAU T)
{
	int h=alea(T.TAILLE);
	printf("h vaut %d et T.TAILLE vaut %d \n",h,T.TAILLE);
	
	T=decalage(T,h,1);
	
	return T;
}

TABLEAU supDouble(TABLEAU T)
{
	int i=1;
	int c=0;
	int tmp=T.tab[0];
	
	while(c<T.TAILLE)
	{
		if (tmp == T.tab[i])
			T=decalage(T,i,1);
		else
		{
			tmp=T.tab[i];
			i++; c++;
		}
	}
	
	return T;
}

int main()
{
	TABLEAU T;
	int valeur = 7;
	
	//Initialisation pour la fonction aleatoire
	srand(time(NULL));
	
	T=initialisation(T);
	affichage(T);
	
	produit(T);
	
	minimum(T);
	
	T=decalage(T,0,0);
	affichage(T);
	
	T=tri(T);
	affichage(T);
	
	T=insertion(T,valeur);
	affichage(T);
	
	/*T=inverstion(T);
	affichage(T);*/
	
	T=suppression(T);
	affichage(T);
	
	T=supDouble(T);
	affichage(T);
	
	return 0;
}
