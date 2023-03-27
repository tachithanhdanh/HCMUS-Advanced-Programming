CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: cutbmp.o Bitmap.o
	$(CXX) $(CXXFLAGS) $^ -o cutbmp.exe

cutbmp.o: Bitmap.hpp
	$(CXX) $(CXXFLAGS) -g -c cutbmp.cpp

Bitmap.o: Bitmap.hpp
	$(CXX) $(CXXFLAGS) -g -c Bitmap.cpp

haha:
	echo hello world
