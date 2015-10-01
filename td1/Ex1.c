#include <sdtio.h>

int main()
{
	int a=0;
	int b=10;
	int c=0;
	
	while (a<10)
	{
		while (c<b)
		{
			printf(" ");
			c++;
		}
		b=b-1;
		c=0;
		printf("* \n");
		a++;
	}
}
