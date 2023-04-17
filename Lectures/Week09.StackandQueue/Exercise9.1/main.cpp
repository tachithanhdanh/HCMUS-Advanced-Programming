#include "Process.hpp"
#include <iostream>

int main(void) {
    int t;
    std::cout << "Please input the number of numbers to convert to binary: ";
    std::cin >> t;
    std::cout.put('\n');
    unsigned int x;
    while (t--) {
        std::cout << "Please input a non-negative number: ";
        std::cin >> x;
        print_binary(x);
    }
    return 0;
}