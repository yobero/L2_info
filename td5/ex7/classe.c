#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
	srand(time(NULL));
	
	FILE* fichier = fopen("a.txt","r");
	FILE* pair = fopen("pair.txt","w");
	FILE* impaire = fopen("impair.txt","w");
	
	fgetc(fichier);
	
	
	return 0;
}
