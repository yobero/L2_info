pi.o : pi.h
	gcc -o pi.h -o pi.o
circonference.o : circonference.c circonference.h
	gcc -c circonference.c -o circonference.o
surface.o : surface.c surface.h
	gcc -c surface.c -o surface.o
principale.o : principale.c circonference.o surface.o pi.o
	gcc -c principale.c -o principale.o
	
all : circonference.o surface.o principale.o pi.h
	gcc circonference.o surface.o principale.o pi.h

clean :
	rm -f circonference.o
	rm -f surface.o
	rm -f principale.o
	rm -f pi.o
