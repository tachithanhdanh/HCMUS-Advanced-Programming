#include <iostream>
#include <iomanip>

constexpr int N = 5;
constexpr int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
constexpr int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};


bool is_valid(int i, int j, int sol[N][N]) {
    return i >= 0 && i < N && j >= 0 && j < N && sol[i][j] == -1;
}

int cnt = 0;

bool knight_tour(int sol[N][N], int i, int j, int step_count, const int x_move[], const int y_move[]) {
    if (step_count == N * N) {
        if (sol[N - 1][0] == 25 && ++cnt == 10) return true;
        return false;
    }

    for (int k = 0; k < 8; ++k) {
        int next_i = i + x_move[k];
        int next_j = j + y_move[k];
        if (is_valid(next_i, next_j, sol)) {
            sol[next_i][next_j] = step_count + 1;
            if (knight_tour(sol, next_i, next_j, step_count + 1, x_move, y_move)) {
                return true;
            }
            sol[next_i][next_j] = -1;
        }
    }
    
    return false;
}

void start_knight_tour() {
    int sol[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sol[i][j] = -1;
        }
    }
    sol[2][2] = 1;
    if (knight_tour(sol, 2, 2, 1, x_move, y_move)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << std::setw(5) << std::left << sol[i][j];
            }
            std::cout << '\n';
        }
    }
}

int main(void) {
    start_knight_tour();
}