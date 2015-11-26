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

fonction.o: fonction.c fonction.h constante.o
	gcc -c fonction.c -o fonction.o
	
quoridor.o: quoridor.c fonction.o
	gcc -c quoridor.c -o quoridor.o

all: fonction.o quoridor.o graphics.o
	gcc -o quoridor graphics.o constante.o fonction.o quoridor.o  `sdl-config --libs` -lm -lSDL_ttf
	
clean: 
	rm -f fonction.o
	rm -f graphics.o
	rm -f quoridor.o
	rm -f constante.o
	rm -f ./quoridor
	
run: all
	./quoridor
