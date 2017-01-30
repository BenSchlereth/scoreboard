#Makefile to compile code that includes wiringPi software
#This is a quick and dirty solution (07.09.2016)

CC	= /usr/bin/gcc
CFLAGS	= -c -Wall 
WIRINGPI = -lwiringPi -lwiringPiDev

all: run

#creates the executable file named run and needs all ~.o files
run: main.o
	$(CC) main.o -o run $(WIRINGPI)


main.o: main.c
	$(CC) $(CFLAGS) main.c


#example.o: example.c
#	$(CC) $(CFLAGS) example.c

#clean
clean: 
	rm -fr *o run