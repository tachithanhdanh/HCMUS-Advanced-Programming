CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o DoublyLinkedList.o DNode.o DemoDList.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

DNode.o: DNode.cpp DNode.hpp
	$(CXX) $(CXXFLAGS) -g -c DNode.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.hpp DNode.hpp
	$(CXX) $(CXXFLAGS) -g -c DoublyLinkedList.cpp

DemoDList.o: DemoDList.cpp DemoDList.hpp DoublyLinkedList.hpp DNode.hpp
	$(CXX) $(CXXFLAGS) -g -c DemoDList.cpp

main.o: DoublyLinkedList.hpp DNode.hpp DemoDList.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe