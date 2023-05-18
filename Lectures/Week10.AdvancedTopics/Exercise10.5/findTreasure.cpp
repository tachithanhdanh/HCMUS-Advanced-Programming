#include "findTreasure.hpp"
#include <iostream>
using std::cout;
using std::cin;

void findTreasure() {
    int M;
    int N;
    int** rooms;
    inputRooms(rooms, M, N);

    int** maxTreasure;
    int** trace;
    findMaxTreasure(rooms, maxTreasure, trace, M, N);

    findPathToMaxTreasure(rooms, maxTreasure, trace, M, N);

    deleteMatrix(rooms, M);
    deleteMatrix(maxTreasure, M);
    deleteMatrix(trace, M);    
}

void inputRooms(int**& rooms, int& M, int& N) {
    cout << "Nhap so tang lau M = ";
    cin >> M;
    cout << "Nhap so phong moi tang N = ";
    cin >> N;
    initMatrix(rooms, M + 1, N + 2);
    for (int i = 1; i <= M; ++i) {
        cout << "Nhap thong tin cua cac phong tren tang " << i;
        cout << "(ngan cach boi khoang trang): ";
        // rooms[i] = new int[N + 2];
        for (int j = 1; j <= N; ++j) {
            // cout << "Nhap so tien co trong ruong cua phong so " << j << ": ";
            cin >> rooms[i][j];
        }
    }
}

void findMaxTreasure(int**& rooms, int**& maxTreasure, int**& trace, int M, int N) { 
    initMatrix(maxTreasure, M + 1, N + 2);
    initMatrix(trace, M + 1, N + 2);
    
    for (int i = 1; i <= M; ++i) {
        // maxTreasure[i] = new int[N + 2]{};
        for (int j = 1; j <= N; ++j) {
            // cout << rooms[i][j] << " \n"[j == N];
            for (int k = -1; k <= 1; ++k) {
                if (maxTreasure[i][j] < maxTreasure[i - 1][j + k] + rooms[i][j]) {
                    maxTreasure[i][j] = maxTreasure[i - 1][j + k] + rooms[i][j];
                    trace[i][j] = k;
                }
            }
        }
    }
}

void findPathToMaxTreasure(int**& rooms, int**& maxTreasure, int**& trace, int M, int N) {
    int maxValue = -1;
    int pos = -1;
    for (int i = 1; i <= N; ++i) {
        if (maxTreasure[M][i] > maxValue) {
            maxValue = maxTreasure[M][i];
            pos = i;
        }
    }

    int* pathway = new int[M + 1];
    for (int i = M; i > 0; --i) {
        pathway[i] = pos;
        pos += trace[i][pos];
    }

    cout << "\nKho bau thu duoc nhieu nhat la " << maxValue << " dong.\n";
    for (int i = 1; i <= M; ++i) {
        cout << "Tai tang " << i << ", tham phong " << pathway[i];
        cout << " de lay so tien la " << rooms[i][pathway[i]] << " dong.\n";
    }

    delete[] pathway;
}

void initMatrix(int**& a, int m, int n) {
    a = new int*[m]{};
    for (int i = 0; i < m; ++i) {
        a[i] = new int[n]{};
    }
}

void deleteMatrix(int**& a, int m) {
    for (int i = 0; i < m; ++i) {
        delete[] a[i];
    }
    delete[] a;
}