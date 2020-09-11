CC=gcc
CFLAGS=-I.

hellomake: main.o
	$(CC) -o simplehello main.c