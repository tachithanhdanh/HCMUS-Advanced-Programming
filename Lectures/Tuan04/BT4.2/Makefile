CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := main

all: COPY.o copy_function.o
	$(CXX) $(CXXFLAGS) $^ -o COPY.exe

copy_function.o: copy_function.cpp copy_function.hpp constants.hpp
	$(CXX) $(CXXFLAGS) -g -c copy_function.cpp

COPY.o: copy_function.hpp COPY.cpp constants.hpp
	$(CXX) $(CXXFLAGS) -g -c COPY.cpp

haha:
	echo hello world

run: main.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	REM --------------------
	$^
