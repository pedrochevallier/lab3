CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2

main:
	$(CC) -o main main.c clave.c semaforo.c gestionarch.c $(CFLAGS) $(HEADERS)

main2:
	$(CC) -o main2 main2.c clave.c semaforo.c gestionarch.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main main2