#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

void initTableau(int t[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			t[i][j]=0;
		}
	}
}

int alea (int n)
{
	int valeur;
	valeur=rand()%n;
	return valeur;
}

int valLigne (int t[N][N],int i,int j,int valeur) //Mettre une valeur unique dans une ligne
{
	int sauv =j;
	j=0;
	
	while (j<N)
	{
		if (valeur==t[i][j])
		{
			t[i][sauv] = valeur;
			return 0;
		}
		j++;
	}
	return 1;
}

int valColonne(int t[N][N],int i,int j,int valeur) //Mettre une valeur unique dans une colonne
{
	int tmp=i;
	i=0;
	while(i<N)
	{
		if (valeur==t[i][j])
		{
			t[tmp][j] = valeur;
			return 0;
		}
		i++;
	}
	return 1;
}

int valCarree (int t[N][N], int i,int j, int valeur)//mettre une valeur unique dans le carree
{
	int tmpi=i;
	int tmpj=j;
	int it,jt;
	
	//Etape 1 recherche de la position la plus haute et la plus à gauche dans un carree de 3X3
	while ((i%3)!=0)
		i--;
	while ((j%3)!=0)
		j++;
		
	it=i+3;
	jt=j+3;
	
	while(i<it)
	{
		while(j<jt)
		{
			j++;
		}
		j=jt-3;
		i++;
	}
}

void validation (int t[N][N],int i, int j, int valeur)// Les trois conditions doivent être respecter
{
	/*if (valeur>0 && valeur <=9)
				t[i][j] = valeur;
			else
				t[i][j]= 0;*/
	int ligne=1;
	int colonne=1;
	int carree=1;
	
	ligne=valLigne(t,i,j,valeur);
	colonne=valColonne(t,i,j,valeur);
	carree=valCarree(t,i,j,valeur);
	
	if (ligne && colonne && carree)
		t[i][j]=valeur;
}

void initialisation(int t[N][N])
{
	int i=0;
	int j=0;
	int valeur;
	
	for (i=0; i<N;i++)
	{
		for (j=0; j<N; j++)
		{
			valeur =  alea((N+1)*2);
			validation(t,i,j,valeur);
		}
	}
}

void affichage (int t[N][N])
{
	int i,j;
	int compteurx=1;
	int compteury=1;
	int y;
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%d ",t[i][j]);
			if (compteurx == 3)
			{
				printf("| ");
				compteurx=1;
			}
			else
				compteurx++;
		}
		printf("\n");
		if(compteury == 3)
		{
			y=0;
			while(y<N+14)
			{
				printf("-");
				y++;
			}
			compteury=1;
			printf("\n");
		}
		else
			compteury++;
	}
}

int main()
{
	srand(time(NULL));
	
	int t[N][N];
	
	initTableau(t);
	initialisation(t);
	affichage(t);
	
	return 0;	
}
