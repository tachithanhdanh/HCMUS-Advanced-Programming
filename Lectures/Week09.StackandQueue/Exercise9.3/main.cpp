#include "Process.hpp"
#include <iostream>
#include <limits> // for std::numeric_limits

constexpr int MAX = 500;

int main(void) {
    int t;
    std::cout << "Please input number of expressions to calculate: ";
    std::cin >> t;
    char expression[MAX]{};
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (t--) {
        getExpression(expression, MAX);
        printResultOfExpression(expression);
    }
    return 0;
}