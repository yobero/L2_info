	#include "pion.h"
	
	//FONCTION
	
	int finDePartie(JOUEUR j1, JOUEUR j2)
	{
		POINT t;
		t.x = 2*ED; t.y = M+TAILLE;
		
		if (j1.p.centre.y == l-PM)
		{
			aff_pol("Partie terminer, Le joueur 1 a gagne", TFIN, t, FIN);
			return 0;
		}
		if (j2.p.centre.y == PM)
		{
			aff_pol("Partie terminer, Le joueur 2 a gagne", TFIN, t, FIN);
			return 0;
		}
		
		return 1;
	}
	
	//SAUVEGARDE
	void sauvegarde(JOUEUR j1,JOUEUR j2)
	{
		FILE* fichier = fopen("sauvegarde.txt","w+");
		int n=0;
		
		///Pour le joueur 1
		fprintf(fichier,"%d\n%d\n",j1.p.centre.x,j1.p.centre.y);
		while (n<NBM)
		{
			fprintf(fichier,"%d\n%d\n%d\n%d\n",j1.m.tab[n][0].x,j1.m.tab[n][0].y,j1.m.tab[n][1].x,j1.m.tab[n][1].y);
			n++;
		}
		fprintf(fichier,"%d\n",j1.m.i);
		
		n=0;
		fprintf(fichier,"%d\n%d\n",j2.p.centre.x,j2.p.centre.y);
		while (n<NBM)
		{
			fprintf(fichier,"%d\n%d\n%d\n%d\n",j2.m.tab[n][0].x,j2.m.tab[n][0].y,j2.m.tab[n][1].x,j2.m.tab[n][1].y);
			n++;
		}
		fprintf(fichier,"%d\n",j2.m.i);
		
		fclose(fichier);
	}
	
	int faireSauvegarde(POINT utilisateur)
	{
		if(utilisateur.x > SHX && utilisateur.x < CHX && utilisateur.y > SBY && utilisateur.y < SHY)
			return 1;
		
		return 0;
	}
	
	void chargement(JOUEUR* j1, JOUEUR* j2)
	{
		FILE* fichier = fopen("sauvegarde.txt","r+");
		char tmp[4];
		int n=0;
		
		fgets(tmp,5,fichier);
		j1->p.centre.x = atoi(tmp);
		fgets(tmp,5,fichier);
		j1->p.centre.y = atoi(tmp);
		
		while (n<NBM)
		{
			fgets(tmp,5,fichier);
			j1->m.tab[n][0].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][0].y = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][1].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][1].y = atoi(tmp);
			n++;
		}
		fgets(tmp,5,fichier);
		j1->m.i =atoi(tmp);
		n=0;
		
		fgets(tmp,5,fichier);
		j2->p.centre.x = atoi(tmp);
		fgets(tmp,5,fichier);
		j2->p.centre.y = atoi(tmp);
		
		while (n<NBM)
		{
			fgets(tmp,5,fichier);
			j2->m.tab[n][0].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][0].y = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][1].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][1].y = atoi(tmp);
			n++;
		}
		fgets(tmp,5,fichier);
		j2->m.i =atoi(tmp);
		
		fclose(fichier);
	}
	
	int recuperationSauvegarde (POINT utilisateur)
	{
		//Le bouton "charger sauvegarde" si situe dans le fichier interface
		if(utilisateur.x > CHX && utilisateur.y > CBY && utilisateur.y < CHY)
			return 1;
		
		return 0;
	}
	
	//RETOUR EN ARRIERE
	void retourArriereSauv(JOUEUR j1,JOUEUR j2)
	{
		FILE* fichier = fopen("retoutEnArriere.txt","w+");
		int n=0;
		
		///Pour le joueur 1
		fprintf(fichier,"%d\n%d\n",j1.p.centre.x,j1.p.centre.y);
		while (n<NBM)
		{
			fprintf(fichier,"%d\n%d\n%d\n%d\n",j1.m.tab[n][0].x,j1.m.tab[n][0].y,j1.m.tab[n][1].x,j1.m.tab[n][1].y);
			n++;
		}
		fprintf(fichier,"%d\n",j1.m.i);
		
		n=0;
		fprintf(fichier,"%d\n%d\n",j2.p.centre.x,j2.p.centre.y);
		while (n<NBM)
		{
			fprintf(fichier,"%d\n%d\n%d\n%d\n",j2.m.tab[n][0].x,j2.m.tab[n][0].y,j2.m.tab[n][1].x,j2.m.tab[n][1].y);
			n++;
		}
		fprintf(fichier,"%d\n",j2.m.i);
		
		fclose(fichier);
	}
	
	void retourArriereCharge(JOUEUR* j1, JOUEUR* j2)
	{
		FILE* fichier = fopen("retoutEnArriere.txt","r+");
		char tmp[4];
		int n=0;
		
		fgets(tmp,5,fichier);
		j1->p.centre.x = atoi(tmp);
		fgets(tmp,5,fichier);
		j1->p.centre.y = atoi(tmp);
		
		while (n<NBM)
		{
			fgets(tmp,5,fichier);
			j1->m.tab[n][0].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][0].y = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][1].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j1->m.tab[n][1].y = atoi(tmp);
			n++;
		}
		fgets(tmp,5,fichier);
		j1->m.i =atoi(tmp);
		n=0;
		
		fgets(tmp,5,fichier);
		j2->p.centre.x = atoi(tmp);
		fgets(tmp,5,fichier);
		j2->p.centre.y = atoi(tmp);
		
		while (n<NBM)
		{
			fgets(tmp,5,fichier);
			j2->m.tab[n][0].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][0].y = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][1].x = atoi(tmp);
			fgets(tmp,5,fichier);
			j2->m.tab[n][1].y = atoi(tmp);
			n++;
		}
		fgets(tmp,5,fichier);
		j2->m.i =atoi(tmp);
		
		fclose(fichier);
	}
	
	int recuperationRetourArriere(POINT utilisateur)
	{
		if  (utilisateur.x > RAHX && utilisateur.x < RABX && utilisateur.y < RAHY && utilisateur.y > RABY)
			return 1;
		
		return 0;
	}
	
	//MUR OU PION
	
	int Pion (POINT utilisateur)
	{
		int i,j;
		
		i=j=0+PM; //centre de la case
		
		while(i<l)
		{
			while(j<l)
			{
				if (utilisateur.x > i-PM+ED && utilisateur.x < i+PM-ED)
					return 1;
				if (utilisateur.y > j-PM+ED && utilisateur.y < j+PM-ED)
					return 1;
				
				j=j+TAILLE;
			}
			j=0+PM;
			i=i+TAILLE;
		}
		
		return 0;
	}
	
	int Mur (POINT utilisateur)
	{
		int i,j;
		
		i=j=0+PM;
		
		while(i<l)
		{
			while(j<l)
			{
				if (utilisateur.x > i+PM-ED && utilisateur.x < i+PM+ED) ///vers la gauche
					return 1;
				if (utilisateur.x > i-PM-ED && utilisateur.x < i-PM+ED) ///vers la droite
					return 1;
				if (utilisateur.y > i+PM-ED && utilisateur.y < i+PM+ED) ///vers le haut
					return 1;
				if (utilisateur.y > i-PM-ED && utilisateur.y < i-PM+ED) ///vers le bas
					return 1;
				
				j=j+TAILLE;
			}
			j=0+PM;
			i=i+TAILLE;
		}
		
		return 0;
	}
	
	JOUEUR murOuPion(JOUEUR j,JOUEUR a, POINT utilisateur, int quiJoue)
	{
		if (Mur(utilisateur))
			j.m = ajoutMur(j.m,utilisateur);
		else
		{
			if (Pion(utilisateur))
				j.p = deplacementPion(j.p,a,utilisateur,quiJoue);
		}
		
		
		return j;
	}
	
