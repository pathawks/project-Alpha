CC=gcc
CFLAGS= -Wall -Wextra -O3

all:
	$(CC) $(CFLAGS) tifileutils/*.c tifileutils/*/*.c alpha.c -o alpha
