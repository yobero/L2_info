#include <stdio.h>

int main(){
	
	int secondes;
	int h;
	int m;
	int s;
	
	printf("Quelle est votre duree en secondes ,s'il vous plait :D?");
	scanf("%d",&secondes);
	
	h = secondes/3600;
	m = (secondes%3600)/60;
	s = secondes%60;
	printf("%d heures %d minutes %d secondes \n",h,m,s);
}
