#include <stdio.h>

struct element {
	int val;
	struct element* suiv;
};
typedef struct element Element;
typedef Element* liste;

liste creerListeVides(liste l)
{
	return NULL;
}

void listeVide(liste l)
{
	if (l == NULL)
		printf("La liste est vide \n");
}

void afficheListe (liste l)
{
	while(l != NULL)
	{
		printf("%d ", l->val);
		l = l->suiv;
	}
}

liste ajout(liste l)
{
	liste x;
	
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

int main ()
{
	liste l;
	
	l=creerListeVides(l);
	listeVide(l);
	afficheListe(l);
	
	return 0;
}
