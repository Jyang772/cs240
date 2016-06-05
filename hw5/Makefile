
CC=gcc
CFLAGS= -std=c11

all:	tail

tail:	tail.o lineholder.o
	$(CC) $(CFLAGS) tail.o lineholder.o -o tail
tail.o: tail.c lineholder.h
	$(CC) $(CFLAGS) -c tail.c
lineholder.o: lineholder.c 
	$(CC) $(CFLAGS) -c lineholder.c
clean:
	rm *.o tail
