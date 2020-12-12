CC=gcc
CFLAGS= -Wall -g

all: clean main clean

main: main.o utils.o
	$(CC) -o $@ $^

main.o:	main.c
	$(CC) $(CFLAGS) $^ -o $@ -c

utils.o: utils.c
	$(CC) $(CFLAGS) $^ -o $@ -c

.PHONY: all clean

clean:
	rm -f *.o
