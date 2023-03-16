CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: main.o Process.o Fraction.o IOFunctions.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

Fraction.o: Fraction.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -g -c Fraction.cpp

IOFunctions.o: IOFunctions.cpp IOFunctions.h Fraction.h
	$(CXX) $(CXXFLAGS) -g -c IOFunctions.cpp

Process.o: Process.cpp Process.h Fraction.h
	$(CXX) $(CXXFLAGS) -g -c Process.cpp

main.o: Process.h IOFunctions.h Fraction.h
	$(CXX) $(CXXFLAGS) -g -c main.cpp

haha:
	echo hello world

run: main.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	REM --------------------
	$^
