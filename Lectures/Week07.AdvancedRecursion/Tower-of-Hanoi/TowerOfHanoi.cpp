#include "TowerOfHanoi.hpp"
#include <iostream>

void transfer(int &step, char src, char dest) {
    std::cout << "#" << ++step << ": " << src << " -> " << dest;
    return;
}

void TowerOfHanoi(int n, char src, char inter, char dest, int &step) {
    // base case
    if (n == 1) {
        transfer(step, src, dest);
    } else {
        TowerOfHanoi(n - 1, src, dest, inter, step);
        transfer(step, src, dest);
        TowerOfHanoi(n - 1, inter, src, dest, step);
    }
    return;
}