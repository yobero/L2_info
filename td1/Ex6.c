#include <stdio.h>

void PA()
{
	int X,Y;
	int x,y;
	int a,b;
	a=0,b=0;
	x=1;
	
	printf("Choississez un nombre X : ");
	scanf("%d",&X);
	printf("Choississez un nombre Y : ");
	scanf("%d",&Y);
	
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
		printf("%d et %d sont des amis \n", X,Y);
	else
		printf("%d et %d ne sont pas des amis \n", X,Y);
}

void PB()
{
	
}

int main(){

	printf("Partie A \n");
	PA();
	printf("Partie B \n");
	PB();
}
