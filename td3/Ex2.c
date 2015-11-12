#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct listec {
	char* chaine;
	struct listec* suiv;
};
typedef struct listec* ListeC;

ListeC initialisation ()
{
	return NULL;
}

ListeC ajoutChaine(char* t,ListeC l) ///Ajout au debut de la liste
{
	ListeC tmp;
	
	tmp->chaine = t;
	tmp->suiv = l;
	
	return tmp;
}

///correction fonction ajoutchaine
/*ListeC ajoutChaine(char* t, ListeC l)
 * {
	 * if(t[0] == '\o')
	 * 		return 1;
	 * l=ajout_fin(l,t[0]);
	 * l=ajoutChaine(t+1, l);
 * }
 */

void afficheChaine(ListeC l)
{
	while (l!=NULL)
	{
		int i=0;
		while(l->chaine[i] != ' ')
		{
			printf("%c",l->chaine[i]);
		}
		printf(", ");
		l=l->suiv;
	}
}

int main( int argc, char* argv)
{
	ListeC l;
	
	l=initialisation();
	
	l=ajoutChaine(argv,l);
	afficheChaine(l);
	return 0;
}
