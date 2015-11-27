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

int finDePartie(JOUEUR j1, JOUEUR j2)
{
	POINT t;
	t.x = 1; t.y = M+TAILLE;
	
	if (j1.p.centre.y == l-PM)
	{
		aff_pol("Partie terminer, Le joueur 1 a gagne", TFIN, t, FIN);
		return 0;
	}
	if (j2.p.centre.y == PM)
	{
		aff_pol("Partie terminer, Le joueur 2 a gagne", TFIN, t, FIN);
		return 0;
	}
	
	return 1;
}

//INITIALISATION

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

//AFFICHAGE

void affichagePion(PION p1,PION p2)
{
	draw_fill_circle(p1.centre,p1.rayon,p1.coul);
	draw_fill_circle(p2.centre,p2.rayon,p2.coul);
}

void affichageMur(MUR m1, MUR m2)
{
	int a=0;
	int z=0;
	
	while (a<NBM)
	{
		draw_fill_rectangle(m1.tab[a][0],m1.tab[a][1],m1.coul);
		draw_fill_rectangle(m2.tab[a][0],m2.tab[a][1],m2.coul);
		a++;
	}
}

void affichageJoueur(JOUEUR j1,JOUEUR j2)
{
	affichagePion(j1.p,j2.p);
	affichageMur(j1.m,j2.m);
}

//DEPLACEMENT

PION deplacementPion(PION p,POINT utilisateur, int quiJoue)
{
	if(quiJoue==1)
	{
		if(utilisateur.y < p.centre.y + D && utilisateur.y > p.centre.y + PM)
			p.centre.y = p.centre.y + TAILLE;
		else
		{
			if(utilisateur.x < p.centre.x + D && utilisateur.x > p.centre.x + PM)
				p.centre.x = p.centre.x + TAILLE;
			else
			{
				if(utilisateur.x > (p.centre.x - D) && utilisateur.x < p.centre.x - PM)
					p.centre.x = p.centre.x - TAILLE;
			}
		}
	}
	else
	{
		if(utilisateur.y > p.centre.y - D && utilisateur.y < p.centre.y - PM)
			p.centre.y = p.centre.y - TAILLE;
		else
		{
			if(utilisateur.x < p.centre.x + D && utilisateur.x > p.centre.x + PM)
				p.centre.x = p.centre.x + TAILLE;
			else
			{
				if(utilisateur.x > (p.centre.x - D) && utilisateur.x < p.centre.x - PM)
					p.centre.x = p.centre.x - TAILLE;
			}
		}
	}
	return p;
}

//AJOUT MUR
