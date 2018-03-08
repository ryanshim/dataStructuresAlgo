# Makefile for BinarySearchTree main program
CC=g++
CFLAGS=-c -std=c++11 -Wall

all: main

main: BinarySearchTree_main.o
	$(CC) BinarySearchTree_main.o -o main 

BinarySearchTree_main.o: BinarySearchTree_main.cpp
	$(CC) $(CFLAGS) BinarySearchTree_main.cpp

clean:
	rm *.o main
