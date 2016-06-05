# makefile for building cs240 alloc project programs using the 
# tell make to use gcc as C compiler, -m32 -g -W... for C compiler flags--
# check "man gcc" to find out what -W flags do
CC = gcc-4.8
OBJS = alloctest.o alloc.o
CFLAGS = -m32 -g -Wall -Wstrict-prototypes -Wmissing-prototypes \
		-Wno-uninitialized -Wshadow #-ansi

alloc: $(OBJS)
	$(CC) $(CFLAGS) -o alloc $(OBJS)
alloctest:  $(OBJS)
	$(CC) $(CFLAGS) -o alloctest $(OBJS)

# make knows to use $(CC) and $(CFLAGS)	
alloctest.o: alloctest.c alloc.h
alloc.o: alloc.c alloc.h

clean:
	rm -f *.o core

