CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all = clean prog

prog:
	$(CC) -o miprog main.c funciones.c global.c $(CFLAGS) $(HEADERS)

clean: rm -rf *o miprog