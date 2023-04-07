#include "EightQueens.hpp"

void countEightQueensSols(int i, int n, int *queens, bool *column, bool *mainDiag, bool *subDiag, int &res) {
    for (int j = 0; j < n; ++j) {
        if (!column[j] && !mainDiag[i - j + n - 1] && !subDiag[i + j]) {
            queens[i] = j;
            if (i == n) {
                ++res;
            } else {
                column[j] = mainDiag[i - j + n - 1] = subDiag[i + j] = true;
                countEightQueensSols(i, n, queens, column, mainDiag, subDiag, res);
                column[j] = mainDiag[i - j + n - 1] = subDiag[i + j] = false;
            }
        }
    }
    return;
}