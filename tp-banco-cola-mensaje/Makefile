CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2

main:
	$(CC) -o banco banco.c key.c cola.c memory.c semaforo.c $(CFLAGS) $(HEADERS)

main2:
	$(CC) -o cajero cajero.c key.c cola.c memory.c semaforo.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o supermercado repositorio