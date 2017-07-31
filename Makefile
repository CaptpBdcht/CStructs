CFLAGS = -Wall -g

all: array_list.o main.o utils.o
	gcc $(CFLAGS) -o cstructs array_list.o main.o utils.o

array_list.o: array_list.c
	gcc $(CFLAGS) -c array_list.c

main.o: main.c
	gcc $(CFLAGS) -c main.c

utils.o: utils.c
	gcc $(CFLAGS) -c utils.c

clean:
	rm -f *.o cstructs