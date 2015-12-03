#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
	FILE* fichier = fopen(argv[1],"r+");
	char str[256];
	int r,v,b; //couleur de pixel
	int i;
	int car[3];
	
	int val=0;
	
	printf("%d\n",fgets(str, 256, fichier));
	printf("%d\n",fgets(str, 256, fichier));
	printf("%d\n",fgets(str, 256, fichier));
	
	for(i=0;i<256;i++)
	{
		fgets(str, 256, fichier);
		r = atoi(str); ///converti une chaine de caractère en entier
		fgets(str, 256, fichier);
		v = atoi(str);
		fgets(str, 256, fichier);
		b = atoi(str);
		r = (r-r%4) + (argv[2][i]*64)%4 ;
		v = (v-v%8) + (argv[2][i]*32)%8;
		b = (b-b%8) + (argv[2][i]%8);
		
		printf("%d \n %d \n %d",r,v,v);
	}
	
	
	return 0;
}
