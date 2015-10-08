#include <stdio.h>
#include <math.h>

#define N 10

void init_tableau(int T[N])
{
	int n=0;
	
	while (n<N)
	{
		T[n]=1,
		n=n+1;
	}
}

void multiplication(int T[N])
{
	int n=0;
	int c=1;
	
	while(n<N)
	{
		c=c*T[n];
		
		n=n+1;
	}
	
	printf("Le produit des elements du tableau est %d \n",c);
}

void minimum(int T[N])
{
	int n=1;
	int i=0;
	
	while(n<N)
	{
		if (T[i]>T[n])
			i=n;
		
		n=n+1;
	}
	
	printf("Le munimum du tableau est à l'indice i : %d avec la valeur %d \n",i,T[i]);
}

void decalage(int T[N])
{
	int n=N-2;
	
	while (n<0)
	{
		T[n+1]=T[n];
		n=n-1;
	}
	
	T[0]=0;
}

void insertion(int T[N], int a)// Dans l'ordre
{
	int n=0;
	int p=-1; //position de l'insertion
	
	while (n<N && p<0) //Localisation de la position
	{
		if (a<T[n])
			p=n;
		else if (n==N-1)
				p=n;
			else n=n+1;
		
	}
	if (p>=0) // Decalage + insertion
	{
		n=N-2;
		
		while (n>=p)
		{
			T[n+1]=T[n];
			n=n-1;
		}
		T[p]=a;
		
	}
	
	
}

void inversion(int T[N])
{
	int tmp;
	int n=0;
	int m=N-1;
	
	while (n<m)
	{
		tmp=T[n];
		T[n]=T[m];
		T[m]=tmp;
		
		n=n+1;
		m=m-1;
	}
}

int main()
{
	int T[N];
	int a=12;
	
	init_tableau(T);
	multiplication(T);
	minimum(T);
	decalage(T);
	
	printf("Choississez une valeur de a = ");
	//scanf("%d \n",&a); PROBLEME
	insertion(T,a);
	
	inversion(T);
}
