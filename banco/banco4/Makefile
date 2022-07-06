CC = gcc
CFLAGS = -c -W -Wall -pedantic -lm

all: ./bin/banco.o
	$(CC) -o banco ./bin/banco.o

./bin/banco.o: banco.c
	$(CC) -o ./bin/banco.o banco.c $(CFLAGS)
