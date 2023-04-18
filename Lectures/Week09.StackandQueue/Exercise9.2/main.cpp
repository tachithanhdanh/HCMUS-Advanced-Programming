#include "NQueensStack.hpp"
#include <iostream>

int main(void) {
    int n;
    std::cout << "Please input the size of chess board: ";
    std::cin >> n;
    std::cout.put('\n');
    QueenChessBoard board(n);
    board.solveNQueens();
    return 0;
}