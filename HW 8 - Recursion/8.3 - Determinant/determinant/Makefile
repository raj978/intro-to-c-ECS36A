# Makefile for determinant.c and matrix.c and matrix.h

determinant.out: determinant.o matrix.o
	gcc -g -Wall -Werror -o determinant.out determinant.o matrix.o

matrix.o: matrix.c matrix.h
	gcc -g -Wall -Werror -c -o matrix.o matrix.c

determinant.o: determinant.c determinant.h
	gcc -g -Wall -Werror -c -o determinant.o determinant.c

clean:
	rm -f *.out *.o
