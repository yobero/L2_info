#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 //valeur max pour la fonction alea

struct tableau {
	int TAILLE;
	int tab[100];
};
typedef struct tableau TABLEAU ;

int alea ()
{
	int valeur;
		valeur=rand()%N;
		return valeur;
}

void affichage(TABLEAU T)
{
	int i=0;
	
	while(i<T.TAILLE)
	{
		printf("%d  ",T.tab[i]);
		
		i=i+1;
	}
	printf("\n");
}

TABLEAU initialisation(TABLEAU T)
{
	int i=0;
	
	T.TAILLE=10;
	
	while (T.TAILLE > i)
	{
		T.tab[i]=alea();
		
		i=i+1;
	}
	
	return T;
}

void produit(TABLEAU T)
{
	int i=0;
	long int c=1;
	
	while (i<T.TAILLE)
	{
		c = c *T.tab[i];
		
		i=i+1;
	}
	
	printf("Le produit du tableau est %ld \n",c);
}

void minimum(TABLEAU T)
{
	int c = T.tab[0];
	int i=1;
	
	while (i<T.TAILLE)
	{
		if (c>T.tab[i])
			c=T.tab[i];
		
		i=i+1;
	}
	printf("La plus petite valeur du tableau est %d \n",c);
}

TABLEAU decalage(TABLEAU T, int l,int s)
{
	int i;
	
	if (s==0)
	{
		T.TAILLE = T.TAILLE + 1;
		i=T.TAILLE-1;
		
		while(i-1>=l)
		{
			T.tab[i]=T.tab[i-1];
		
			i--;
		}
		T.tab[0]=0;
	}
	else
	{	
		while(l<T.TAILLE)
		{
			T.tab[l]=T.tab[l+1];
		
			l++;
		}
		T.TAILLE = T.TAILLE - 1;
	}
	
	return T;
}

TABLEAU triInsertion(TABLEAU T,int* lecture,int* ecriture)
{
	int i=1;
	int tmp,c;
	int j=0;
	
	while (i<T.TAILLE)
	{
		while (j<i)
		{
			if (T.tab[i]<T.tab[j])			//2
			{
				c=i;
				tmp = T.tab[i];				//1
				while (c-1>=j)
				{
					T.tab[c] = T.tab[c-1];	///1 + 1
					*lecture = *lecture +1;
					*ecriture = *ecriture +1;
					
					c--;
				}
				T.tab[c] = tmp;				///1
				
				*ecriture = *ecriture +1;
				
				j=i;
			}
			
			*lecture = *lecture +3;
			
			j++;
		}
		j=0;
		i++;
	}
	
	return T;
}

TABLEAU triSelection(TABLEAU T,int* lecture,int* ecriture)
{
	int i=1;
	int tmp,c ;
	int n=0;
	
	tmp = n;
	
	while (n<T.TAILLE)
	{
		while (i<T.TAILLE)
		{
			if (T.tab[n] > T.tab[i] && T.tab[tmp]> T.tab[i])//1
				tmp=i;
			
			*lecture = *lecture + 4;
			
			i++;
		}
		c=T.tab[n];					//1
		
		*lecture = *lecture +1;
		
		T.tab[n]=T.tab[tmp];		///1 +1
		T.tab[tmp]=c;				///1
		
		*ecriture = *ecriture +2;
		*lecture = *lecture +1;
		
		n++;
		tmp=n;
		i=n+1;
	}
	
	return T;
}

TABLEAU triBulle(TABLEAU T,int* lecture, int* ecriture) //Tri à bulle
{
	int i=T.TAILLE-1;
	int tmp;
	int l=0; //compteur
	
	while (l<T.TAILLE)
	{
		while(i-1>=l)
		{
			if (T.tab[i-1]>T.tab[i]) 	//1
			{	
				tmp=T.tab[i];
				T.tab[i]=T.tab[i-1]; 	///1 +1
				T.tab[i-1]=tmp;			///1
				
				*ecriture = *ecriture +1;
				*lecture=*lecture +1;
			}
			*lecture=*lecture +1;
			
			i=i-1;
		}
		i=T.TAILLE-1;
		l++;
	}
	
	return T;
}

TABLEAU insertion(TABLEAU T, int valeur)
{
	int i=0;
	
	//localisation
	while (valeur>T.tab[i])
		i=i+1;
	
	T=decalage(T,i,0); //La fonction decalage augmente la TAILLE  de 1
	
	T.tab[i]=valeur;
	
	return T;
}

TABLEAU inverstion (TABLEAU T)
{
	int i=0;
	int j=T.TAILLE-1;
	int tmp;
	
	while (i<j)
	{
		tmp=T.tab[i];
		T.tab[i]=T.tab[j];
		T.tab[j]=tmp;
		
		j--;
		i++;
	}
	
	
	return T;
}

TABLEAU  suppression(TABLEAU T)
{
	int h=alea(T.TAILLE);
	printf("h vaut %d et T.TAILLE vaut %d \n",h,T.TAILLE);
	
	T=decalage(T,h,1);
	
	return T;
}

TABLEAU supDouble(TABLEAU T)
{
	int i=1;
	int c=0;
	
	while(c<T.TAILLE)
	{
		while(i<T.TAILLE)
		{
			if (T.tab[i] == T.tab[c])
				T=decalage(T,i,1);
				
			i++;
		}
			c++;
			i=c+1;
	}
	
	return T;
}

TABLEAU choixTri(TABLEAU T)
{
	int t;
	
	int lecture=0;
	int ecriture=0;
	
	printf("Quel tri veut tu ? \n");
	printf("1 => tri a bulle \n");
	printf("2 => tri par selection\n");
	printf("3 => tri par insertion  ");
	
	scanf("%d",&t);
	
	if(t==1)
	{
		T=triBulle(T,&lecture,&ecriture);
		printf("Il y a eu %d lectures du tableau et %d ecritures de celui ci pour le tri a bulle\n",lecture,ecriture);
	}
	lecture=0; ecriture=0;
	if(t==2)
	{
		T=triSelection(T,&lecture,&ecriture);
		printf("Il y a eu %d lectures du tableau et %d ecritures de celui ci pour le tri par selection\n",lecture,ecriture);
	}
	lecture=0; ecriture=0;
	if (t==3)
	{
		T=triInsertion(T,&lecture,&ecriture);
		printf("Il y a eu %d lectures du tableau et %d ecritures de celui ci pour le trie par insertion\n",lecture,ecriture);
	}
	lecture=0; ecriture=0;
	
	
	return T;
}



int main()
{
	TABLEAU T;
	int valeur = 7;
	
	//Initialisation pour la fonction aleatoire
	srand(time(NULL));
	
	T=initialisation(T);
	affichage(T);
	
	produit(T);
	
	minimum(T);
	
	T=decalage(T,0,0);
	affichage(T);
	
	T=insertion(T,valeur);
	affichage(T);
	
	/*T=inverstion(T);
	affichage(T);*/
	
	T=suppression(T);
	affichage(T);
	
	T=supDouble(T);
	affichage(T);
	
	T=choixTri(T); //NOUVEAU
	affichage(T);
	
	return 0;
}
