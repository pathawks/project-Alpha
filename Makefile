CC=gcc
CFLAGS= -Wall -Wextra -O3

all:
	$(CC) $(CFLAGS) alpha.c -o alpha
