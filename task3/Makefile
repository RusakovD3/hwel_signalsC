CC=gcc
CFLAGS=-Wall

all: main sender

main: main.c
	$(CC) $(CFLAGS) -o main main.c

sender: sender.c
	$(CC) $(CFLAGS) -o sender sender.c

clean:
	rm -f main sender process.pid
