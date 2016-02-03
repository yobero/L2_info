#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int gc()
{
	int n;
	unsigned char buf;
	
	if(read(0,&buf,1)>0)
	{
		n = buf;
	}
	else
	{
		n = EOF;
	}
	//pour savoir la valeur
	printf("%d \n",n);
	
}

int main ()
{
	gc();
	
	return 1;
}
