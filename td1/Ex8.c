#include <stdio.h>

#define N 100

int main()
{
	int u[N];
	int n=0;
	int i=0;
	printf("Choississez une valeur de depart : U0 = ");
	//scanf("%d \n",&u[0]);
	u[0]=101;
	
	while(n<N && u[n]!=1)
	{
		if (u[n]%2 == 0)
		{	
			u[n+1] = u[n]/2;
			i=i+2;
		}
		else
		{
			u[n+1] = u[n]+1;
			i=i+2;
		}
		i=i+2;
		
		n++;
		
		printf("Un vaut %d : \n",u[n]);
	}
	printf("Il y a %d iteration(s) \n",i);
}
