#include "IOFunctions.hpp"
#include "Process.hpp"
#include <iostream>

void readInputString(char *&s, int &n) {
    char cur, pre;
    cur = pre = '\0';
    do {
        pre = cur;
        std::cin.get(cur);
        // std::cout << cur << '\n';
        InsertCharToString(s, n, cur);
    } while (!(cur == '\n' && pre == '.'));
}

void printResultString(char **stringArray, const int arrayLen, const int countWords) {
    std::cout << countWords << '\n';
    for (int i = 0; i < arrayLen; ++i) {
        std::cout << stringArray[i] << '\n';
    }
    return;
}