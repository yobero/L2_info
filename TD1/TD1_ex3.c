#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,const char** argv)
{
	int copier = open(argv[1], O_RDONLY);
	int coller = open(argv[2], O_WRONLY | O_CREAT);
	
	char a[1024];
	int m;
	
	while ((m = read(copier,a,1024))>0)
	{
		if (write(coller,a,m)!=m)
			return -1;
	}
	
	close(copier);
	close(coller);
	
	return 1;
}
