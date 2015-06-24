CC = g++
FILES = node.cxx priority_queue.cxx main.cpp
ARGUMENTS = -std=c++11 -Wall
OUT_EXE = group8-hw02

build: $(FILES)
		$(CC) $(FILES) $(ARGUMENTS) -o $(OUT_EXE) 
		
clean:
		rm -f *.o core

rebuild: clean build
