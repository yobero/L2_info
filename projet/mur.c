#include "affichage.h"

int nbMaxMur(MUR m)
{
	if (m.i>=NBM)
		return 0;
	return 1;
}

POINT localisationClic(POINT utilisateur, int* HV)
{
	POINT p;
	int i,j;
	i=0;
	j=0;
	
	while (i<l)
	{
		if ((utilisateur.x > i+ED) && (utilisateur.x < i+(TAILLE-ED)))
			p.x = i;
		else
		{
			if ((utilisateur.x > i-ED) && (utilisateur.x < i+ED))
			{
			p.x = i;
			*HV = 0;
			}
		}
		i=i+TAILLE;
	}
	while (j<l)
	{
		if (utilisateur.y > j-ED && utilisateur.y < j+TAILLE)
			p.y = j-ED;
		j=j+TAILLE;	
	}
	return p;
}

int rechercheEmplacementMur(MUR m) //INUTILE
{
	int recherche=0;
	int i=0;
	
	while(i<NBM)
	{
		if (m.tab[i][0].x == INIT)
			i=l;
		else
			recherche++;
		
		i++;
	}
	return recherche;
}

MUR placementMur(POINT p, POINT utilisateur, MUR m)//INUTILE	
{
	int recherche;
	
	recherche= rechercheEmplacementMur(m);
	m.tab[m.i][0].x = p.x;
	m.tab[m.i][0].y = p.y;
	m.tab[m.i][1].x = p.x + LONGM;
	m.tab[m.i][1].y = p.y + LARGM;
	m.i++;
	
	return m;
}

MUR ajoutMur (MUR m, POINT utilisateur)
{
	int HV=1;
	printf("Avant %d\n",HV);
	if (nbMaxMur(m))
	{
		POINT p;
		
		p=localisationClic(utilisateur,&HV);
		printf("Apres %d\n",HV);
		if (HV)
		{
			//m=placementMur(p,utilisateur,m);
			m.tab[m.i][0].x = p.x+ED;
			m.tab[m.i][0].y = p.y;
			m.tab[m.i][1].x = p.x + LONGM-ED;
			m.tab[m.i][1].y = p.y + LARGM;
			m.i=m.i+1;
		}
		else
		{
			m.tab[m.i][0].x = p.x-ED;
			m.tab[m.i][0].y = p.y+EPAISSEUR;
			m.tab[m.i][1].x = m.tab[m.i][0].x+ LARGM;
			m.tab[m.i][1].y = m.tab[m.i][0].y + LONGM-EPAISSEUR;
			m.i=m.i+1;
		}
	}
	else
		printf("Tu ne peux plus placer de mur.\n"); //CHANGER ET AFFICHER DANS LA FENETRE
	
	return m;
}
