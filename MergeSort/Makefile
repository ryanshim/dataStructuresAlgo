# Makefile for MergeSort main prog
CC=g++
CFLAGS=-c -std=c++11 -Wall

all: main

main: MergeSort_main.o
	$(CC) MergeSort_main.o -o main

MergeSort_main.o: MergeSort_main.cpp
	$(CC) $(CFLAGS) MergeSort_main.cpp

clean:
	rm *.o main
