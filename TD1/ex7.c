#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 1000
#define LECTURE O_RDONLY
#define ECRITURE O_WRONLY
#define LE O_RDWR //lecture et écriture

struct fichier{
	char buf[MAX];
	char* p; //pointeur sur buf
	int reste; //place disponible dans le buf
	int mode;//mode d'ouverture (l|e|l&e)
	int fd; //descripteur du fichier
};
typedef struct fichier* FICHIER;

int choixMode()
{
	int a;
	unsigned char buf;
	printf("Quel mode d'ouverture : 1 ==> lecture 2 ==> ecriture 3 ==> lecture/ecriture\n");
	a = read(0,&buf,1);
	printf("%d",a);
	switch (a) {
		case 1: return LECTURE;
		case 2: return ECRITURE;
		case 3: return LE;
		default : return LECTURE;
	}
}

FICHIER my_open(const char* argv,int mode)
{
	FICHIER f;
	f->mode = mode;
	f->fd = open(argv,mode,0666);
	f->reste =0;
	f->p = f->buf;
	return f;
}

int my_getc(FICHIER f)
{
	int z;
	char buf;
	z = read(f->fd,&buf,1);
	return z;
}

int main (int argc,const char** argv)
{
	FICHIER f;
	f=my_open(argv[1],choixMode());
	//printf("%d",my_getc(f->fd));
	return 1;
}
