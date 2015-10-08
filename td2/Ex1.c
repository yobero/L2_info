#include <stdio.h>
void A()
{
	char tab[10];
	unsigned long int a;
	char (*p)[10] = &tab; ///Un pointeur sur un tableau de 10 caractères
	
	//partie 1
	
	a=sizeof(char);
	printf("char %lu \n",a);
	a=sizeof(int);
	printf("int = %lu \n",a);
	a=sizeof(double);
	printf("double = %lu \n",a);
	a=sizeof(char*);
	printf("char = %lu \n",a);
	a=sizeof(void*);
	printf("void* = %lu \n",a);
	a=sizeof(int*);
	printf("int* = %lu \n",a);
	a=sizeof(double*);
	printf("double* = %lu \n",a);
	a=sizeof(int**);
	printf("int** = %lu \n",a);
	a=sizeof(int[10]);
	printf("int[10] = %lu \n",a);
	a=sizeof(char[7][3]);
	printf("char[7][3] = %lu \n",a);
	a=sizeof(int[10]);
	printf("int[] = %lu \n",a);
	
	printf("\n");
	//Partie 2
	
	a=sizeof(tab);
	printf("tab = %lu \n",a);
	a=sizeof(tab[0]);
	printf("tab[0] = %lu \n",a);
	a=sizeof(&tab[0]);
	printf("&tab[0] = %lu \n",a);
	a=sizeof(*&tab);
	printf("*&tab = %lu \n",a);
	a=sizeof(*&tab[0]);
	printf("*&tab[0] = %lu \n",a);
	
	printf("\n");
	//partie 3
	
	a=sizeof(p);
	printf("p = %lu \n",a);
	a=sizeof(*p);
	printf("*p = %lu \n",a);
	a=sizeof((*p)[2]);
	printf("(*p)[2] = %lu \n",a);
	a=sizeof(&(*p)[2]);
	printf("&(*)p[2] = %lu \n",a);
	
	printf("\n");
}

void permutation(int *a,int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void reinitPointeur(int* p){ //
	*p = NULL;
}

int main()
{
	//A
	
	//A();
	
	//B
	/*{
		int z=12;
		int b=41;
	
		printf("a vaut %d et b vaut %d \n",z,b);
		permutation(&z,&b);
		printf("a vaut %d et b vaut %d \n",z,b);
	}*/
	
	//C
	{
	///Voir fonction reinitpointeur
		int p=100;
		printf("Avant %p \n",p);
		reinitPointeur(&p);
		printf("Apres %p \n",p);
	
	}
}
