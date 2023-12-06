CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2 run_script

main:
	$(CC) -o main main.c thread.c semaforo.c cola.c key.c evento.c global.c memory.c $(CFLAGS) $(HEADERS)
main2:
	$(CC) -o main2 main2.c thread.c semaforo.c cola.c key.c evento.c global.c memory.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main main2

run_script:
	bash rm.sh