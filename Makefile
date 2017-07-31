CFLAGS = -Wall -g

all: main.o
	gcc $(CFLAGS) -o cstructs main.o

main.o: main.c
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o cstructs