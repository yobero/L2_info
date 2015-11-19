#construit le fichier binaire graphics.o
graphics.o: graphics.c graphics.h
	rm -f police.h
	touch police.h
	if test -e /usr/include/SDL_ttf.h;           then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/include/SDL/SDL_ttf.h;       then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL_ttf.h;     then echo "#define SDL_TTF_OK" > police.h; fi
	if test -e /usr/local/include/SDL/SDL_ttf.h; then echo "#define SDL_TTF_OK" > police.h; fi
	gcc -Wall `sdl-config --cflags`  -c graphics.c
	
liste.o : liste.c graphics.o
	gcc -c liste.c -o liste.o
	
simul.o : simul.c liste.o
	gcc -c simul.c -o simul.o
	
main.o : main.c graphics.o liste.o simul.o
	gcc -c main.c -o main.o

all : graphics.o main.o liste.o simul.o
	gcc graphics.o liste.o simul.o main.o `sdl-config --libs` -lm -lSDL_ttf
	
clean : 
	rm -f *.o
	rm -f a.out
	
run : a.out
	./a.out
