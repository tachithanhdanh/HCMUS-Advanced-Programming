CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o sumOfPrime.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

sumOfPrime.o: sumOfPrime.cpp sumOfPrime.hpp
	$(CXX) $(CXXFLAGS) -g -c sumOfPrime.cpp

main.o: sumOfPrime.hpp main.cpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	del *.o
	del *.exe