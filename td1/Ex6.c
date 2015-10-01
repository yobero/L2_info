#include <stdio.h>

int PA(int X, int Y)
{
	int x,y;
	int a,b;
	a=0,b=0;
	x=1;
	
	while (x<X)
	{
		if (X%x==0)
		{
			a=a+x;
			x++;
		}
		else
			x++;
	}
	
	if (a==Y)
		y=1;
	else
		y=Y;
		
	while (y<Y)
	{
		if (Y%y==0)
		{
			b=b+y;
			y++;
		}
		else
			y++;
	}
	
	if (b==X)
	{
		printf("%d et %d sont des amis \n", X,Y);
		return 1;
	}
	else
	{
		printf("%d et %d ne sont pas des amis \n", X,Y);
		return 0;
	}
}

void PB(int nmax)
{
	int X,Y;
	int compteur=0;
	
	X=1;
	Y=nmax;
	
	while(Y>=nmax)
	{
		while (X<=nmax)
		{
			compteur=PA(X,Y)+ compteur;
			X++;
		}
		X=1;
		Y--;
	}
	printf("Il y a %d couples pour un nmax de %d \n",compteur,nmax);
}

int main()
{

	int X,Y;
	int nmax;
	
	printf("Partie A \n");
	printf("Choississez un nombre X : ");
	scanf("%d",&X);
	printf("Choississez un nombre Y : ");
	scanf("%d",&Y);
	PA(X,Y);
	printf("Partie B \n");
	printf("Choississez un nombre au pif \n");
	scanf("%d",&nmax);
	PB(nmax);
}
