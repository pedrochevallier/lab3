CC = gcc

CFLAGS = -Wall -std=gnu89 -Og -pedantic-errors -g

HEADERS = -I./

all: clean main junto run_script

main:
	$(CC) -o main main.c memory.c key.c thread.c evento.c cola.c semaforo.c $(CFLAGS) $(HEADERS)
main2:
	$(CC) -o main2 main2.c memory.c key.c thread.c evento.c cola.c semaforo.c $(CFLAGS) $(HEADERS)
junto:
	$(CC) -o junto junto.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main main2 junto

run_script:
	bash rm.sh