CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

blah.exe: blah.o
	$(CXX) blah.o -o blah.exe

blah.o: blah.cpp
	$(CXX) $(CXXFLAGS) -g -c blah.cpp

blah.cpp:
	echo int main(void) { int a = 0; return 0; } > blah.cpp

haha:
	echo hello world

run: blah.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	$^

debug: blah.exe
	gdb blah.exe

print_dir: 
	dir $(files)