CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main

main:
	$(CC) -o main main.c thread.c semaforo.c cola.c key.c evento.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main