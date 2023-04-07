CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o Process.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

main.o: main.cpp Process.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

Process.o: Process.hpp Process.cpp
	$(CXX) $(CXXFLAGS) -g -c Process.cpp

run: main.exe
	$^
