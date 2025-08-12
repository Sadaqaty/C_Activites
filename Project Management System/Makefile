CC = gcc
CFLAGS = -Wall

all: task_manager

task_manager: main.o task_manager.o
	$(CC) $(CFLAGS) -o task_manager main.o task_manager.o

main.o: main.c task_manager.h
	$(CC) $(CFLAGS) -c main.c

task_manager.o: task_manager.c task_manager.h
	$(CC) $(CFLAGS) -c task_manager.c

clean:
	rm -f *.o task_manager
