CC=gcc
CFLAGS= -Wall

all:
	$(CC) $(CFLAGS) alpha.c -O3 -o alpha
