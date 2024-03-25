CC = gcc
CFLAGS = -Wall

.PHONY: all clean

all: main sender

main: main.c
	$(CC) $(CFLAGS) -o main main.c

sender: sender.c
	$(CC) $(CFLAGS) -o sender sender.c

clean:
	rm -f main sender
