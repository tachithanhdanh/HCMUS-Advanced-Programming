CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o DoublyLinkedList.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.hpp
	$(CXX) $(CXXFLAGS) -g -c DoublyLinkedList.cpp

main.o: DoublyLinkedList.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt