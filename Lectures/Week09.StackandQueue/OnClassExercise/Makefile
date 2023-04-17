CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o SNode.o Stack.o Queue.o Demo.o DNode.o Deque.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

SNode.o: SNode.cpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c SNode.cpp

Stack.o: Stack.cpp Stack.hpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c Stack.cpp

Queue.o: Queue.cpp Queue.hpp SNode.hpp
	$(CXX) $(CXXFLAGS) -g -c Queue.cpp

Demo.o: Demo.cpp Demo.hpp Stack.hpp Queue.hpp SNode.hpp DNode.hpp Deque.hpp
	$(CXX) $(CXXFLAGS) -g -c Demo.cpp

Deque.o: Deque.cpp Deque.hpp DNode.hpp
	$(CXX) $(CXXFLAGS) -g -c Deque.cpp

DNode.o: DNode.cpp DNode.hpp
	$(CXX) $(CXXFLAGS) -g -c DNode.cpp

main.o: main.cpp Demo.hpp Stack.hpp Queue.hpp SNode.hpp DNode.hpp Deque.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe