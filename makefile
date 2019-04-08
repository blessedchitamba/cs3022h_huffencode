# Makefile for CS3022H Huffencode application
# Author: Blessed Chitamba
# April 2019

# Directories

SRC=./src
BIN=./bin

CC=g++
CCFLAGS=-std=c++11

SOURCES=HuffmanNode.cpp HuffmanTree.cpp huffencode.cpp
OBJECTS=HuffmanNode.o HuffmanTree.o huffencode.o

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o huffencode $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies

depend:

	$(CC) -M $(SOURCES) > incl.defs

run:
	./huffencode inputfile outputfile

clean:
	rm *.o
	rm huffencode
	rm outputfile*

