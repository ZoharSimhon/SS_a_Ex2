#dictionery
CC = gcc
CFLAGS= -Wall -g
LIBAR = ar -rcs

all: libMat.a connections

connections: main.o libMat.a
	$(CC) $(CFLAGS) -o connections main.o libMat.a


libMat.a: my_mat.o
	$(LIBAR) libMat.a my_mat.o


main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c


.PHONY: clean all
clean:
	rm -rf *.o *.a connections