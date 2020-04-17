CC=gcc

all: ejemplo.bin

ejemplo.bin: Principal.o Operaciones.o
	$(CC) -o ejemplo.bin Principal.o Operaciones.o

Principal.o: Principal.c
	$(CC) -c Principal.c -g

Operaciones.o: Operaciones.c
	$(CC) -c Operaciones.c -g

clean:
	rm -f *.o *.bin
