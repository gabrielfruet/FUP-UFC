CC = gcc
CFLAGS = -c -W -Wall -pedantic -lm

all: banco

banco: ./bin/banco.o ./bin/contas.o ./bin/erro.o
	$(CC) -o banco ./bin/banco.o ./bin/contas.o ./bin/erro.o

./bin/banco.o: ./src/banco.c ./src/contas.h ./src/erro.h
	$(CC) -o ./bin/banco.o ./src/banco.c $(CFLAGS)

./bin/contas.o: ./src/contas.c ./src/contas.h ./src/erro.h
	$(CC) -o ./bin/contas.o ./src/contas.c $(CFLAGS)

./bin/erro.o: ./src/erro.c ./src/erro.h 
	$(CC) -o ./bin/erro.o ./src/erro.c $(CFLAGS)
