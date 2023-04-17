CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o SinglyLinkedList.o SNode.o DemoSList.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

SNode.o: SNode.cpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c SNode.cpp

SinglyLinkedList.o: SinglyLinkedList.cpp SinglyLinkedList.hpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c SinglyLinkedList.cpp

DemoSList.o: DemoSList.cpp DemoSList.hpp SinglyLinkedList.hpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c DemoSList.cpp

main.o: SinglyLinkedList.hpp SNode.hpp DemoSList.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe