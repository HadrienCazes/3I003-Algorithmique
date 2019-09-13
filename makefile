all: main

main: functions.o main.o
	gcc -o main functions.o main.o

functions.o: functions.c
	gcc -o functions.o -c functions.c -W -Wall

main.o: main.c functions.h
	gcc -o main.o -c main.c -W -Wall

clean:
	rm -rf *.o

