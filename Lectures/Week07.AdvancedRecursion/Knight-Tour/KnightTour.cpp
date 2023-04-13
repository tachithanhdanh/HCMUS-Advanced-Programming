#include "KnightTour.hpp"
#include <iostream>

bool isValid(int x, int y, int n, int **position) {
    return x >= 0 && x < n && y >= 0 && y < n && position[x][y] == 0;
}

void knightTour(int k, int n, int x, int y, int **position, const int dx[8], const int dy[8]) {
    if (k == n * n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << position[i][j] << " \n"[j == n - 1];
            }
        }
        std::cout << "\n";
        return;
    }
    for (int j = 0; j < 8; ++j) {
        int x_new = x + dx[j];
        int y_new = y + dy[j];
        if (isValid(x_new, y_new, n, position)) {
            position[x_new][y_new] = k + 1;
            knightTour(k + 1, n, x_new, y_new, position, dx, dy);
            position[x_new][y_new] = 0;
        }
    }
    return;
}