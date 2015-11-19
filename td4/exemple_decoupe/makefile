plam.o: plam.c plam.h
	gcc -c plam.c -o plam.o
plim.o : plim.c plam.h
	gcc -c plim.c -o plim.o
ploum.o : ploum.c plam.o plim.o
	gcc -c ploum.c -o ploum.o
	
compilation : plam.o plim.o ploum.o
	gcc plim.o plam.o ploum.o
