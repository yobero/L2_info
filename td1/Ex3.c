#include <stdio.h>

int main(){

	int a,b,c; //valeur de base
	int y;
	scanf("%d",&a);
	scanf("%d",&b);
	c=0;
	
	printf("= %d x %d \n",a,b);
	while (a!=1)
	{
		if (a%2==0)
		{
			a=a/2;
			b=2*b;
		}
		else
		{
			a=a-1;
			c=c+b;
		}
		if (c==0)
			printf("= %d x %d \n",a,b);
		else
			printf("= %d x %d + %d \n",a,b,c);
			
		if (a<=1)
		{
			y=a*b+c;
			printf("%d \n",y);
		}
	}
}
