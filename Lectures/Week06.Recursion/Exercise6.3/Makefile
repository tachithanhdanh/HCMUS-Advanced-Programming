CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: main.o Process.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

Process.o: Process.cpp Process.hpp
	$(CXX) $(CXXFLAGS) -g -c Process.cpp

main.o: Process.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	$^