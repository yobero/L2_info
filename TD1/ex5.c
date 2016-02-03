#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100

int getchar2()
{
	// static ... ==> initialiser qu'1 seule fois (premiere appel)
	static unsigned char buf[MAX];
	static int m=0;
	static char *p;
	
	if (m == 0)
	{
		m = read(0,buf,MAX);
		p=buf;
	}
	return (m-- >0) ? *p++:EOF;
}

int main ()
{
	getchar2();
}
