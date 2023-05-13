CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o Node.o List.o ListSort.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -g -c Node.cpp

List.o: List.cpp List.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -g -c List.cpp

ListSort.o: ListSort.cpp ListSort.hpp List.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -g -c ListSort.cpp

main.o: main.cpp List.hpp ListSort.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe