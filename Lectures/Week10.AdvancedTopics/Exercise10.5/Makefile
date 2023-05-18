CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o findTreasure.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

findTreasure.o: findTreasure.cpp findTreasure.hpp
	$(CXX) $(CXXFLAGS) -g -c findTreasure.cpp

main.o: findTreasure.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe