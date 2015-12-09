#include "structure.c"

//FONCTION

void fenetreInterface()
{
	POINT p1,p2;
	p1.x = l+PM; p1.y = (l/4)+(l/3);
	p2.x = (l+INTERFACE)-PM; p2.y = ((3*l)/4)-(l/3);
	draw_fill_rectangle(p1,p2,SLCOUL);
}

void interface()
{
	POINT p;
	//PARTIE POUR LE JOUEUR 1
	p.x = l+ED; p.y = l/4;
	aff_pol("Nombre de murs restants pour le joueur 1 :",TAILINTER,p,COULI);
	
	//PARTIE POUR LE JOUEUR 2
	p.y =(3*l)/4;
	aff_pol("Nombre de murs restants pour le joueur 2 :",TAILINTER,p,COULI);
	
	fenetreInterface();
}

void dessinePlateau()// La fonction va déssiner le plateau du jeu
{
	POINT p1,p2;
	
	fill_screen(FE);
	interface();
	
	p1.x = 0-ED; p1.y = 0;
	p2.x = p1.x+EPAISSEUR; p2.y = l;
	
	while (p1.x < l)
	{
		draw_fill_rectangle(p1,p2,GRILLE);
		p1.x = p1.x + TAILLE;
		p2.x = p1.x + EPAISSEUR;
	}
	p1.x = 0;
	p1.y =0 -ED;
	p2.y=p1.x+EPAISSEUR;
	p2.x = l;
	
	while (p1.y < l)
	{
		draw_fill_rectangle (p1,p2,GRILLE);
		p1.y = p1.y + TAILLE;
		p2.y = p1.y + EPAISSEUR;
	}
	
}

int finDePartie(JOUEUR j1, JOUEUR j2)
{
	POINT t;
	t.x = 2*ED; t.y = M+TAILLE;
	
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
	
	m.i = 0;
	
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

//PION

POINT rechercheMur(PION j1, MUR j2)
{
	POINT p;
	int n=0;
	
	
	
	return ;
}

int blocage(PION j1, MUR j2)
{	
	
	return 1;
}

PION deplacementPion(PION p,JOUEUR a,POINT utilisateur, int quiJoue)//IMPOSANTE COMME FONCTION
{
	/**If faut rajouter une condition à tous les if secondaire :D
	 * */
	if(quiJoue==1)
	{	
		if(utilisateur.y < p.centre.y + D && utilisateur.y > p.centre.y + PM)
		{
			if (1)
			{
				if ((p.centre.y +TAILLE == a.p.centre.y) && (p.centre.x == a.p.centre.x))
					p.centre.y = p.centre.y + 2*TAILLE;
				else
					p.centre.y = p.centre.y + TAILLE;
			}
		}
		else
		{
			if(utilisateur.x < p.centre.x + D && utilisateur.x > p.centre.x + PM)
			{
				if ((p.centre.x + TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.x))
					p.centre.x = p.centre.x + 2*TAILLE;
				else
					p.centre.x = p.centre.x + TAILLE;
			}
			else
			{
				if(utilisateur.x > (p.centre.x - D) && utilisateur.x < p.centre.x - PM)
				{
					if ((p.centre.x - TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.y))
						p.centre.x = p.centre.x -2*TAILLE;
					else
						p.centre.x = p.centre.x - TAILLE;
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
	}
	else
	{
		if(utilisateur.y > p.centre.y - D && utilisateur.y < p.centre.y - PM)
		{
			if ((p.centre.y - TAILLE == a.p.centre.y) && (p.centre.x == a.p.centre.x))
				p.centre.y = p.centre.y - 2*TAILLE;
			else
				p.centre.y = p.centre.y - TAILLE;
		}
		else
		{
			if(utilisateur.x < p.centre.x + D && utilisateur.x > p.centre.x + PM)
			{
				if((p.centre.x + TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.y))
					p.centre.x = p.centre.x + 2*TAILLE;
				else
					p.centre.x = p.centre.x + TAILLE;
			}
			else
			{
				if(utilisateur.x > (p.centre.x - D) && utilisateur.x < p.centre.x - PM)
				{
					if ((p.centre.x - TAILLE == a.p.centre.x) && (p.centre.y == a.p.centre.y))
						p.centre.x = p.centre.x - 2*TAILLE;
					else
						p.centre.x = p.centre.x - TAILLE;
				}
				else
				{
					if(utilisateur.y < p.centre.y + D && utilisateur.y > p.centre.y + PM)
					{
						if ((p.centre.y +TAILLE == a.p.centre.y) && (p.centre.x == a.p.centre.x))
							p.centre.y = p.centre.y + 2*TAILLE;
						else
							p.centre.y = p.centre.y + TAILLE;
					}
				}
			}
		}
	}
	return p;
}

//MUR

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

//MUR OU PION

int Pion (POINT utilisateur)
{
	int i,j;
	
	i=j=0+PM; //centre de la case
	
	while(i<l)
	{
		while(j<l)
		{
			if (utilisateur.x > i-PM+ED && utilisateur.x < i+PM-ED)
				return 1;
			if (utilisateur.y > j-PM+ED && utilisateur.y < j+PM-ED)
				return 1;
			
			j=j+TAILLE;
		}
		j=0+PM;
		i=i+TAILLE;
	}
	
	return 0;
}

int Mur (POINT utilisateur)
{
	int i,j;
	
	i=j=0+PM;
	
	while(i<l)
	{
		while(j<l)
		{
			if (utilisateur.x > i+PM-ED && utilisateur.x < i+PM+ED) ///vers la gauche
				return 1;
			if (utilisateur.x > i-PM-ED && utilisateur.x < i-PM+ED) ///vers la droite
				return 1;
			if (utilisateur.y > i+PM-ED && utilisateur.y < i+PM+ED) ///vers le haut
				return 1;
			if (utilisateur.y > i-PM-ED && utilisateur.y < i-PM+ED) ///vers le bas
				return 1;
			
			j=j+TAILLE;
		}
		j=0+PM;
		i=i+TAILLE;
	}
	
	return 0;
}

JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue)
{
	if (Mur(utilisateur))
		j.m = ajoutMur(j.m,utilisateur);
	else
	{
		if (Pion(utilisateur))
			j.p = deplacementPion(j.p,a,utilisateur,quiJoue);
	}
	
	
	return j;
}
