#include <stdio.h>
#include <stdlib.h>

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
	printf("\n");
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

liste ajoutDebut(liste l,int t)
{
	liste elt = malloc(sizeof(liste));
	
	elt->val = t;
	elt->suiv =l;
	
	return elt;
}

liste ajoutFin(liste l,int t) //Segmentation fault
{
	liste elt = malloc(sizeof(liste));
	
	elt->val = t;
	elt->suiv = NULL;
	l->suiv = elt ;
	
	return l;
}

liste ajout(liste l) //a revoir
{
	liste p=l;
	int t=1;
	int a=0;
	while (t!=0)
	{
		t=alea();
		if (a==0)
			p=ajoutDebut(p,t);
		else
			p=ajoutFin(p,t);
	}
	p=NULL;
	
	return l;
}

int recherche (liste l,int e) //e la valeur à rechercher FONCTION CORRIGE
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

liste retirer(liste l, int e) //fonction corrigé
{
	liste tmp=l;
	
	if(listeVide(l))
		return l;
	if(l->val == e)
	{
		tmp = l->suiv;
		free(l);
		return tmp;
	}
	
	while(tmp->suiv->val != e && tmp->suiv != NULL)
		tmp = tmp->suiv;
	
	if (tmp->suiv != NULL)
	{
		liste v = tmp->suiv;
		tmp->suiv = tmp->suiv->suiv;
		free(v);
	}
	return l;
}

liste concat(liste l, liste p)			//fonction corrigé
{
	if (listeVide(l))
		return p;
	l->suiv = concat(l->suiv,p);
	return l;
}

liste fusion(liste l,liste p)			//fonction corrigé
{
	liste debut,fin;
	
	if(listeVide(l))
		return p;
	if(listeVide(p))
		return l;
	
	if(l->val < p->val)
	{
		debut = l;
		fin = l;
		l=l->suiv;
	}
	else
	{
		debut = p;
		fin = p;
		p=p->suiv;
	}
	
	while (l!= NULL && p !=NULL)
	{
		if (l->val < p->val)
		{
			fin ->suiv = l;
			l=l->suiv;
			fin = fin->suiv;
		}
		else
		{
			fin->suiv = p;
			p=p->suiv;
			fin =fin->suiv;
		}
	}
	if (l == NULL)
		fin->suiv = p;
	else
		fin->suiv = l;
	
	return debut;
}

int main ()
{
	liste l;
	liste p;
	int compteur;
	
	l=creerListeVides(l);
	p=creerListeVides(p);
	
	///l=ajout(l); //Fonction merdique !!!!!!!!!!!!!
	
	int t=1;
	
	while(t!=0)
	{
		t=alea();
		l=ajoutDebut(l,t);
	}
	t=1;
	while(t!=0)
	{
		t=alea();
		p=ajoutDebut(p,t);
	}
	
	afficheListe(l); ///Fonctionnelle
	afficheListe(p);
	compteur=nombreElements(l);
	printf("il y a %d elements dans la premiere liste \n",compteur);
	
	return 0;
}
