#include <iostream>

using pint = int *;

int main()
{
    pint ptr{ new int }; // dynamically allocate an integer
    *ptr = 7; // put a value in that memory location
    std::cout << *ptr;
    std::cout << "Hello World!\n";
    int x = 10;

    std::cout << x << '\n';

    std::cout << x << '\n';
    
    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

    // std::cout << *ptr; // Indirection through a dangling pointer will cause undefined behavior
    // delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.

    return 0;
}