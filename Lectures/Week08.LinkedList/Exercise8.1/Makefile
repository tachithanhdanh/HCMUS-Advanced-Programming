CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o SinglyLinkedList.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

SinglyLinkedList.o: SinglyLinkedList.cpp SinglyLinkedList.hpp
	$(CXX) $(CXXFLAGS) -g -c SinglyLinkedList.cpp

main.o: SinglyLinkedList.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	$^