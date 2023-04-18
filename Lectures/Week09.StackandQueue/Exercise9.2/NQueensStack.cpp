#include "NQueensStack.hpp"
#include "Stack.hpp"
#include <iostream>

QueenChessBoard::QueenChessBoard(int size)
    : m_size(size)
    , m_columns(new int[size]{}) 
    , m_mainDiag(new bool[size * 4]{})
    , m_subDiag(new bool[size * 4]{}) 
    , m_countSols(0)
{
    for (int i = 0; i < m_size; ++i) {
        m_columns[i] = -1;
    }
}

QueenChessBoard::~QueenChessBoard() {
    delete[] m_columns;
    delete[] m_mainDiag;
    delete[] m_subDiag;
}

void QueenChessBoard::displayBoard() const {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cout << (i == m_columns[j] ? 'Q' : '.') << " \n"[j == m_size - 1];
        }
    }
    std::cout.put('\n');
    return;
}

void QueenChessBoard::solveNQueens() {
    Stack queens;

    int row = 0;
    int col = 0;

    while (true) {
        while (col < m_size) {
            if (isQueenSafe(row, col)) {
                queens.push(col);
                m_columns[col] = row;
                m_mainDiag[row - col + m_size - 1] = true;
                m_subDiag[row + col] = true;
                ++row;
                col = 0;
                break;
            } else {
                ++col;
            }
        }

        if (queens.size() == m_size) {
            displayBoard();
            col = queens.top();
            --row;
            row = queens.size() - 1;
            m_columns[col] = -1;
            m_mainDiag[row - col + m_size - 1] = false;
            m_subDiag[row + col] = false;
            ++m_countSols;
            queens.pop();
            ++col;
        }

        // backtrack
        if (col == m_size) {
            // all queens removed
            // no more cases left to consider
            if (queens.empty()) {
                break;
            } else {
                col = queens.top();
                --row;
                m_columns[col] = -1;
                m_mainDiag[row - col + m_size - 1] = false;
                m_subDiag[row + col] = false;
                queens.pop();
                ++col;
            }
        }
    }

    std::cout << "Number of solutions: " << m_countSols << '\n';
    return;
}

bool QueenChessBoard::isQueenSafe(int row, int col) const {
    return !m_mainDiag[row - col + m_size - 1]
        && !m_subDiag[row + col]
        && m_columns[col] == -1;
}

// void QueenChessBoard::setQueenState(int& row, int& col, Stack& queens, bool state) {
//     if (state == true) {
//         queens.push(col);
//     }
//     col = queens.top();
//     row = queens.size() - 1;
//     m_columns[col] = (state ? row : -1);
//     m_mainDiag[row - col + m_size - 1] = state;
//     m_subDiag[row + col] = state;
//     if (state == false) {
//         queens.pop();
//     }
//     return;
// }