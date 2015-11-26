#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
	printf("P3\n");
	printf("256 256\n");
	printf("255\n");
	/*printf("255 0 0 	0 255 0		0 0 255\n");
	printf("255 255 0	255 255 255		0 0 0\n");*/
	
	int l = 256; //longueur et la largeur de l'image
	int a=0;
	int z=0;
	
	int r=0;
	int b=0;
	int i=0;
	int v=0;
	
	while (a<256)
	{
		while (z<256)
		{
			printf("%d %d %d", r,v,b);
			printf("	");
			
			b++;
			z++;
		}
		printf("\n");
		b=0;
		r++;
		
		z=0;
		a++;
	}
	return 0;
}
