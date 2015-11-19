#include "circonference.h"
#include "surface.h"

int main ()
{
	int r;
	scanf("%d",&r);
	
	double c;
	c=circonference(r);
	printf("La circonference du cercle de rayon %d est : %lf\n",r,c);
	c = surface(r);
	printf("La surface du cercle de rayon %d est : %lf\n",r,c);
	
	return 0;
}
