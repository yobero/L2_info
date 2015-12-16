#include "mur.h" 

///Le mur doit être horizontal et en haut
//Les fonction s haut et bas sont inverser pour le joueur 2
int blocageHaut(PION j1, MUR j2)
{
	int n=0;
	
	while (n<j2.i) //j2.i correspond au prochain mur à placer d'où '<'
	{
		if (j1.centre.x - PM +ED == j2.tab[n][0].x || j1.centre.x - PM+ED == j2.tab[n][0].x +TAILLE)
		{
			if (j1.centre.y + PM-ED == j2.tab[n][0].y)
				return 0;
		}
		printf("%d\n",n);
		n++;
	}
	
	return 1;
}

///Le mur doit être vertical et à droite du pion à deplacé
int blocageDroite(PION j1, MUR j2)
{
	int n=0;
	
	while (n<j2.i) //j2.i correspond au prochain mur à placer d'où '<'
	{
		if (j1.centre.x + PM -ED == j2.tab[n][0].x)
		{
			if (j1.centre.y- PM+ED == j2.tab[n][0].y || j1.centre.y - PM+ED == j2.tab[n][0].y +TAILLE)
				return 0;
		}
		n++;
	}
	
	return 1;
}

int blocageGauche(PION j1, MUR j2)
{
	int n=0;
	
	while (n<j2.i) //j2.i correspond au prochain mur à placer d'où '<'
	{
		if (j1.centre.x - PM-ED == j2.tab[n][0].x)
		{
			printf("yo");
			if (j1.centre.y- PM+ED == j2.tab[n][0].y || j1.centre.y - PM+ED == j2.tab[n][0].y +TAILLE)
				return 0;
		}
		n++;
	}
	
	return 1;
}

int blocageBas(PION j1, MUR j2)
{
	int n=0;
	
	while (n<j2.i) //j2.i correspond au prochain mur à placer d'où '<'
	{
		if (j1.centre.x - PM +ED == j2.tab[n][0].x || j1.centre.x - PM+ED == j2.tab[n][0].x +TAILLE)
		{
			if (j1.centre.y - PM-ED == j2.tab[n][0].y)
				return 0;
		}
		printf("%d\n",n);
		n++;
	}
	
	return 1;
}

int blocage(PION j1, MUR j2, int f) //f va defini le type de deplacement
{	
	if (f==1)
		return blocageHaut(j1,j2);
	if (f==2)
		return blocageDroite(j1,j2);
	if (f==3)
		return blocageGauche(j1,j2);
	if (f==4)
		return blocageBas(j1,j2);
	
	return 0;
}

PION deplacementPion(PION p,JOUEUR a,POINT utilisateur)//IMPOSANTE COMME FONCTION
{
	/**If faut rajouter une condition à tous les if secondaire :D
	 * */
	if((utilisateur.y < p.centre.y + D-ED && utilisateur.y > p.centre.y + PM+ED) && (utilisateur.x > p.centre.x -PM+ED && utilisateur.x < p.centre.x +PM-ED)) //vers le haut
	{
		if (blocage(p,a.m,1))
		{
			if ((p.centre.y +TAILLE == a.p.centre.y) && (p.centre.x == a.p.centre.x))
				p.centre.y = p.centre.y + 2*TAILLE;
			else
				p.centre.y = p.centre.y + TAILLE;
		}
	}
	else
	{
		if((utilisateur.x < p.centre.x + D && utilisateur.x > p.centre.x + PM) && (utilisateur.y < p.centre.y +PM-ED && utilisateur.y > p.centre.y -PM+ED))
		{
			if(blocage(p,a.m,2))
			{
				if (((p.centre.x + TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.x)))
					p.centre.x = p.centre.x + 2*TAILLE;
				else
					p.centre.x = p.centre.x + TAILLE;
			}
		}
		else
		{
				if(utilisateur.x > (p.centre.x - D) && utilisateur.x < p.centre.x - PM)
				{
					if(blocage(p,a.m,3))
					{
						if ((p.centre.x - TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.y))
							p.centre.x = p.centre.x -2*TAILLE;
						else
							p.centre.x = p.centre.x - TAILLE;
					}
				}
			else
			{
				if (utilisateur.y > (p.centre.y -D) && utilisateur.y < (p.centre.y -PM))
				{
					if ((p.centre.y - TAILLE == a.p.centre.y) && (p.centre.x == a.p.centre.x))
						p.centre.y = p.centre.y - 2*TAILLE;
					else
						p.centre.y = p.centre.y - TAILLE;
				}
			}
		}
	}
	return p;
}
