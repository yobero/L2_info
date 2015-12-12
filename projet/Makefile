#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c

constante.o: constante.c
	gcc -c constante.c -o constante.o
	
structure.o: constante.o
	gcc -c structure.c -o structure.o
	
initialisation.o: initialisation.c initialisation.h structure.o
	gcc -c initialisation.c -o initialisation.o

affichage.o: affichage.c affichage.h initialisation.o
	gcc -c affichage.c -o affichage.o

interface.o: interface.c interface.h affichage.o
	gcc -c interface.c -o interface.o

mur.o: mur.c mur.h interface.o
	gcc -c mur.c -o mur.o
	
pion.o: pion.c pion.h mur.o
	gcc -c pion.c -o pion.o

fonction.o: fonction.c fonction.h pion.o
	gcc -c fonction.c -o fonction.o
	
quoridor.o: quoridor.c fonction.o 
	gcc -c quoridor.c -o quoridor.o

all:quoridor.o graphics.o
	gcc -o quoridor graphics.o constante.o structure.o initialisation.o affichage.o interface.o mur.o pion.o fonction.o quoridor.o  `sdl-config --libs` -lm -lSDL_ttf
	
clean: 
	rm -f *.o
	rm -f ./quoridor
	rm -f sauvegarde.txt
	rm -f retoutEnArriere.txt
	
run: all
	./quoridor
