#ifndef NQUEENSTACK_HPP_
#define NQUEENSTACK_HPP_
#include "Stack.hpp"

class QueenChessBoard {
private:
    int m_size;
    int* m_columns;
    bool* m_mainDiag;
    bool* m_subDiag;
    int m_countSols;

public:
    QueenChessBoard(int size = 0);
    ~QueenChessBoard();
    QueenChessBoard(const QueenChessBoard&) = delete;
    QueenChessBoard& operator=(const QueenChessBoard&) = delete;
    void displayBoard() const;
    void solveNQueens();
    bool isQueenSafe(int row, int col) const;
    // void setQueenState(int& row, int& col, Stack& queens, bool state);
};

#endif