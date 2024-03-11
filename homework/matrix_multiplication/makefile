CC=gcc
CFLAGS=-Wall -O3
LIBS=-lm -lblas

all: matrix_multiplication

matrix_multiplication: matrix_multiplication.c
	$(CC) $(CFLAGS) -o matrix_multiplication matrix_multiplication.c $(LIBS)

clean:
	rm -f matrix_multiplication

