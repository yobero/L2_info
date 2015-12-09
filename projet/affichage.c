#include "initialisation.h"

void affichagePion(PION p1,PION p2)
{
	draw_fill_circle(p1.centre,p1.rayon,p1.coul);
	draw_fill_circle(p2.centre,p2.rayon,p2.coul);
}

void effacePion(PION p1, PION p2)
{
	draw_fill_circle(p1.centre,p1.rayon,NOIR);
	draw_fill_circle(p2.centre,p2.rayon,NOIR);
}

void affichageMur(MUR m1, MUR m2)
{
	int a=0;
	
	while (a<NBM)
	{
		draw_fill_rectangle(m1.tab[a][0],m1.tab[a][1],m1.coul);
		draw_fill_rectangle(m2.tab[a][0],m2.tab[a][1],m2.coul);
		a++;
	}
}

void effaceMur(MUR m1, MUR m2)
{
	int a=0;
	
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
	affiche_all();
	effacePion(j1.p,j2.p);
	effaceMur(j1.m,j2.m);
}
