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
	switch (a) {
		case 1: return LECTURE;
		case 2: return ECRITURE;
		case 3: return LE;
		default : return LECTURE;
	}
}

FICHIER my_open(const char* argv,int mode)
{
	FICHIER f = malloc(sizeof(struct fichier));
	f->mode = mode;
	f->fd = open(argv,mode,0666);
	f->reste =0;
	f->p = f->buf;
	return f;
}

int my_getc(FICHIER f)
{
	//if ((f->mode & F_R) ==0)
		//return EOF;
	if (f->reste <= 0)
	{
		f->reste = read(f->fd, f->buf,MAX);
		f->p = f->buf;
	}
	if (f->reste <=0)
		return EOF;
	else
	{
		f->reste --;
		return (*(f->p++));
	}
}

int my_putc()

int main (int argc,const char** argv)
{
	FICHIER f;
	f=my_open(argv[1],choixMode()); 
	printf("%c\n",my_getc(f));
	return 1;
}
