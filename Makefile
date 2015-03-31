CC=gcc
CFLAGS= -Wall -Wextra -Os

all:
	$(CC) $(CFLAGS) tifileutils/*.c tifileutils/*/*.c alpha.c -o alpha
