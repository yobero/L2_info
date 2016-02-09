#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc,const char** argv)
{
	//OK(partie 1)
	struct stat buf;
	
	stat(argv[1],&buf);
	
	//Montre le type du fichier demandé en utilisant ST_MODE
	printf("Le fichier est ");
	switch (buf.st_mode & S_IFMT) {
    case S_IFBLK:  printf("un périphérique de bloc\n");      break;
    case S_IFCHR:  printf("un périphérique de caractère\n"); break;
    case S_IFDIR:  printf("un répertoire\n");                break;
    case S_IFIFO:  printf("FIFO/tube\n");                 break;
    case S_IFLNK:  printf("un lien symbolique\n");           break;
    case S_IFREG:  printf("un fichier ordinaire\n");         break;
    case S_IFSOCK: printf("un socket\n");                    break;
    default:       printf("inconnu ?\n");                 break;
    }
    
    ///Correction(partie 2)
    char prot[9],*p;
    p=prot;
    sprintf(prot,"rwxrwxrwx ");
    mask=1;
    int i;
    for(i=0;i<9;i++ )
    {
		if (buf.st_mode & mask == 0)
			*p='-';
		p++;
		mask <<=1;
	}
	printf("protection %s\n",prot);
    
    /*
    //montre la taille du fichier avec ST_SIZE (%ld ==> pour le type off_t)
    printf("La taille du fichier est  %ld octet(s)\n",buf.st_size);
    
    switch (buf.st_mode) {
		case S_IRWXU: printf("Le proprietaire à tous les droits sur le fichier\n"); break;
		case S_IRUSR: printf("Le propriétaire a le droit de lecture \n"); break;
		case S_IWUSR: printf("Le proprietaire a le droit d'ecriture\n"); break;
		default:	  printf("Le proprietaire n'a aucun droit sur le fichier\n"); break;
	}
	
	printf("Mode : %lo (octal)\n",(unsigned long) buf.st_mode);
	*/
	return 1;
}

/** voir site http://manpagesfr.free.fr/man/man2/stat.2.html
* stat	
* 	dev_t     st_dev;      /* ID du périphérique contenant le fichier
    ino_t     st_ino;      /* Numéro inœud 
    mode_t    st_mode;     /* Protection 
    nlink_t   st_nlink;    /* Nb liens matériels 
    uid_t     st_uid;      /* UID propriétaire 
    gid_t     st_gid;      /* GID propriétaire
    dev_t     st_rdev;     /* ID périphérique (si fichier spécial)
    off_t     st_size;     /* Taille totale en octets
    blksize_t st_blksize;  /* Taille de bloc pour E/S
    blkcnt_t  st_blocks;   /* Nombre de blocs alloués
    time_t    st_atime;    /* Heure dernier accès
    time_t    st_mtime;    /* Heure dernière modification
    time_t    st_ctime;    /* Heure dernier changement état */
