#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc,const char** argv)
{
	struct stat* buf;
	
	stat(argv[1],buf);
	
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
