CC = gcc

CFLAGS = -Wall -std=gnu89 -O3 -pedantic-errors

HEADERS = -I./

all: clean main main2 run_script

main:
	$(CC) -o main main.c memory.c key.c thread.c evento.c cola.c $(CFLAGS) $(HEADERS)
main2:
	$(CC) -o main2 main2.c memory.c key.c thread.c evento.c cola.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *o main main2

run_script:
	bash rm.sh