CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2

main:
	$(CC) -o supermercado supermercado.c key.c cola.c memory.c semaforo.c $(CFLAGS) $(HEADERS)

main2:
	$(CC) -o repositorio repositorio.c key.c cola.c memory.c semaforo.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o supermercado repositorio