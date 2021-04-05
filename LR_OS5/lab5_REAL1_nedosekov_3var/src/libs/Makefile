CC = gcc

CCFLAGS = -g3 -Wall -pedantic 


all: libshared1.so libshared2.so



libshared1.so: SinIntegralRectangle.c gcdEvc.c lib1.c 
	$(CC) $(CCFLAGS) -c -fPIC SinIntegralRectangle.c gcdEvc.c lib1.c 
	$(CC) $(CCFLAGS) -shared SinIntegralRectangle.o gcdEvc.o lib1.o -o libshared1.so -l m

libshared2.so: SinIntegralRectangle.c gcdEvc.c lib2.c 
	$(CC) $(CCFLAGS) -c -fPIC SinIntegralTrapezoid.c gcdSimple.c lib2.c 
	$(CC) $(CCFLAGS) -shared SinIntegralTrapezoid.o gcdSimple.o lib2.o -o libshared2.so -l m 
clean:
	rm *.o *.so 

