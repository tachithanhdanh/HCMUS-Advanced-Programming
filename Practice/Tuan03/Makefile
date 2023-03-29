CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: 22120049.o
	$(CXX) $(CXXFLAGS) $^ -o 22120049.exe

22120049.o: 22120049.cpp
	$(CXX) $(CXXFLAGS) -g -c 22120049.cpp

run: 22120049.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	REM --------------------
	REM < input.txt > output.txt
	22120049.exe 