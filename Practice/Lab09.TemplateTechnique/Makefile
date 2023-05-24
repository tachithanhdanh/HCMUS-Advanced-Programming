CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

all: main.o Fraction.o Demo.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

Fraction.o: Fraction.hpp Fraction.cpp
	$(CXX) $(CXXFLAGS) -g -c Fraction.cpp

Demo.o: Demo.hpp Demo.cpp Fraction.hpp List.hpp Node.hpp sort.hpp Array.hpp
	$(CXX) $(CXXFLAGS) -g -c Demo.cpp

main.o: main.cpp Demo.hpp Fraction.hpp List.hpp Node.hpp sort.hpp Array.hpp
	$(CXX) $(CXXFLAGS) -g -c main.cpp

22120049.0: 22120049.cpp
	$(CXX) $(CXXFLAGS) -g -c 22120049.o

22120049.exe: 22120049.o
	$(CXX) $(CXXFLAGS) $^ -o 22120049.exe

run: main.exe
	main.exe

demo: 22120049.exe
	22120049.exe < input.txt > output.txt

clean:
	del *.exe *.o