#include <stdio.h>

int main(){

	int a;
	int x;
	printf("Pouvez-vous choisir votre nombre, s'il vous plait :D \n");
	scanf("%d",&a);
	
		if (a==1 || a==2 || a==3 || a==5 || a==7 )
		{
		 x=11;
		 printf("%d est un nombre premier \n",a);
		}
		else
			x=2;
			
	while (x<=10)
	{
		if (a%x==0)
		{
			x=11;
			printf("%d n'est pas un nombre premier. \n",a);
		}
		else
		{
			x++;
			if (x == 11)
				printf("%d est un nombre premier \n",a);
		}
	}
}
