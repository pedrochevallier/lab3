CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2

main:
	$(CC) -o main main.c thread.c semaforo.c cola.c key.c evento.c $(CFLAGS) $(HEADERS)
main2:
	$(CC) -o main2 pateador.c thread.c semaforo.c cola.c key.c evento.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main main2