#include <stdio.h>

#define N 10

struct element {
	int val;
	struct element* suiv;
};
typedef struct element Element;
typedef Element* liste;

int alea ()
{
	int valeur;
		valeur=rand()%N;
		return valeur;
}

liste creerListeVides(liste l)
{
	return NULL;
}

int listeVide(liste l)
{
	if (l == NULL)
	{
		printf("La liste est vide \n");
		return 0;
	}
	 return 1;
}

void afficheListe (liste l)
{
	while(l != NULL)
	{
		printf("%d ", l->val);
		l = l->suiv;
	}
}

liste tri(liste l)
{
	liste sauv=l;
	liste p=l->suiv;
	int tmp;
	
	while(l != NULL)
	{
		while(p!=NULL)
		{
			if (l->val > p->val)
			{
				tmp= l->val;
				l->val = p->val;
				p->val = tmp;
				p=l;
			}
			p=p->suiv;
		}
		l=l->suiv;
	}
	return sauv;
}

liste ajoutDebut(liste l)
{
	liste elt = malloc(sizeof(liste));
	int t;
	
	printf("Choisir une valeur a ajouter dans la liste ");
	scanf("%d",&t);
	
	elt->val = t;
	elt->suiv =l;
	
	return elt;
}

liste ajoutFin(liste l)
{
	liste elt = malloc(sizeof(liste));
	int t;
	
	printf("Choisir une valeur a ajouter dans la liste ");
	scanf("%d",&t);
	
	elt->val = t;
	elt->suiv = NULL;
	l->suiv = elt ;
	
	return l;
}

int recherche (liste l,int e) //e la valeur à rechercher
{
	if (listeVide)
		return 0;
	if (l->val == e)
		return 1;
	else
		return recherche(l->suiv,e);
}

int nombreElements(liste l)
{
	int compteur=0;
	while(l!=NULL)
	{
		l=l->suiv;
		compteur++;
	}
	return compteur;
}

int main ()
{
	liste l;
	int compteur;
	
	l=creerListeVides(l);
	l= ajoutDebut(l);
	afficheListe(l);
	
	compteur=nombreElements(l);
	
	return 0;
}
