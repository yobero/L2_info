#include <stdio.h>

#define N 10

int factorielle (int n)
{
	int f;
	
	if (n <=1)
		f=1;
	else
		f = n * factorielle(n-1);
	
	return f;
}

int main()
{
	int n=N;
	
	n=factorielle(n);
	printf("%d \n",n);
}
