#include <stdio.h>
#include <math.h>

#define N 4

int racine_carree(int n,float a)
{
	if (n<=N)
		{
			a= a + racine_carree(n+1,a) + sqrt(n);
		}
	
	return a;
}

int main()
{
	//sqrt(x)
	int n=1;
	float a=0;
	a=racine_carree(n,a);
	printf("%f",a);
}
