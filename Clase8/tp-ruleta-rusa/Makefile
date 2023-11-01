CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean revolver jugadores

revolver:
	$(CC) -o revolver revolver.c cola.c semaforo.c key.c evento.c $(CFLAGS) $(HEADERS)

jugadores:
	$(CC) -o jugadores jugadores.c cola.c semaforo.c key.c evento.c thread.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o revolver jugadores