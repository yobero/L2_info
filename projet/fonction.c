#include "structure.c"

//FONCTION

void dessinePlateau()// La fonction va déssiner le plateau du jeu
{
	POINT p1,p2;
	
	p1.x = 0; p1.y = 0;
	p2.x = p1.x; p2.y = l;
	
	while (p1.x < l)
	{
		draw_line(p1,p2,GRILLE);
		p2.x = p1.x = p1.x + TAILLE;
	}
	p2.y=p1.x = 0;
	p2.x = l;
	
	while (p1.y < l)
	{
		draw_line (p1,p2,GRILLE);
		p2.y = p1.y = p1.y + TAILLE;
	}
	
}

PION initialisationPion(int a)
{
	PION p;
	
	if(a==1)
	{
		p.centre.y = PM;
		p.coul = coulPJ1;
	}
	else
	{
		p.centre.y = l-PM;
		p.coul = coulPJ2;
	}
	p.centre.x = M;
	p.rayon = R;
	
	return p;
}

MUR initialisationMur(int a)
{
	MUR m;
	
	if(a==1)
		m.coul = coulMJ1;
	else
		m.coul = coulMJ2;
	
	m.reste=NBM; //Le reste de mur à placer
	
	int i=0;
	int j=0;
	while(i<NBM)
	{
		while(j<2)
		{
			m.tab[i][j].x = INIT;
			m.tab[i][j].y = INIT;
			j++;
		}
		j=0;
		i++;
	}
	
	return m;
}

JOUEUR initialisationJoueur(int a)
{
	JOUEUR j;
	
	j.p=initialisationPion(a);
	j.m=initialisationMur(a);
	
	return j;
}

void affichagePion(JOUEUR j1,JOUEUR j2)
{
	
}
