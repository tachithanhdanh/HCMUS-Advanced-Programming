CC = cc
CXX = g++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector

files := $(wildcard *.cpp)

a := blah

$(a).exe: $(a).o
	$(CXX) blah.o -o blah.exe

$(a).o: $(a).cpp
	$(CXX) $(CXXFLAGS) -g -c blah.cpp

$(a).cpp:
	echo int main(void) { int a = 0; return 0; } > blah.cpp

haha:
	echo hello world

run: blah.exe
	REM this is a comment in cmd
	REM this outputs all prerequisites
	$^

debug: blah.exe
	REM basic GDB commands
	REM breakpoint main - Puts a breakpoint at the beginning of the program
	REM run arg1 arg2 - run program with argument list
	REM breakpoint 20 - set breakpoint at line 20
	REM b list::erase - set breakpoint at the beginning of a class member function
	REM info b - This example lists all of the breakpoints
	REM delete 20 - remove breakpoint at line 20
	REM next - next executes the current command, stops, and displays the next function in line for execution.
	REM step: executes the current command. In cases when it is a function call, it breaks at the beginning of that method. You can use it for looking for errors in nested code.
	REM The possible syntax for using print:
	REM print <exp>: to get values of expressions.
	REM print /x <exp>: to get the value of expressions in hexadecimal.
	REM print /t <exp>: to get the value of expressions in binary.
	REM print /d <exp>: to get the value of expressions as unsigned int format.
	REM print /c <exp>: to get the value of expressions as signed int format.
	REM -----
	REM During analysis of code, you might need to check which function currently runs.
	REM (gdb) where
	REM ---
	REM By typing the where command, you will learn these things:
	REM The name of the currently running function.
	REM The name of the file in which the function runs.
	REM The number of the line in which the function is.
	REM The name of the function that called the current function.
	REM The arguments the current function had.
	REM If it is a call chain, you will see all of them.
	REM call function_name - using a function
	REM set x = value - set value for variable
	gdb blah.exe

print_dir: 
	dir $(files)