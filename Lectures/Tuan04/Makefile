CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: main.o copy.o
	$(CXX) $(CXXFLAGS) $^ -o COPY.exe

copy.o: copy.cpp copy.h
	$(CXX) $(CXXFLAGS) -g -c copy.cpp

main.o: copy.h main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

haha:
	echo hello world

run: main.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	REM --------------------
	$^
