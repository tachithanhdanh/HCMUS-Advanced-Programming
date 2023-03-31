CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o Process.o IOFunctions.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

IOFunctions.o: IOFunctions.cpp IOFunctions.hpp Process.hpp
	$(CXX) $(CXXFLAGS) -g -c IOFunctions.cpp

Process.o: Process.cpp Process.hpp
	$(CXX) $(CXXFLAGS) -g -c Process.cpp

main.o: main.cpp Process.h IOFunctions.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

haha:
	echo hello world

run: main.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	REM --------------------
	$^