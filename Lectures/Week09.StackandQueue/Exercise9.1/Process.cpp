#include "Process.hpp"
#include "Stack.hpp"
#include <iostream>

void print_binary(unsigned int x) {
    Stack s;
    int rem = 0;
    std::cout << "Binary representation of " << x << ": ";
    do {
        rem = x % 2;
        x /= 2;
        s.push(rem);
    } while (x != 0);

    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout.put('\n');
    return;
}