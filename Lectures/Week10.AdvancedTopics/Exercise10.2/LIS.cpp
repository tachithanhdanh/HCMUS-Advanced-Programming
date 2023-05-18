#include "LIS.hpp"
#include <iostream>

void demoLIS() {
    std::cout << "Please input the number of element in array: ";
    int n;
    std::cin >> n;
    int* a = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cout << "Input a[" << i << "] = ";
        std::cin >> a[i];
    }
    solveLISBottomUp(a, n);
    solveLISTopDown(a, n);
    delete[] a;
}

void solveLISBottomUp(int* a, int n) {
    std::cout << "Finding the longest increasing subsequence in an array";
    std::cout << " using bottom-up method.\n";
    int* trace = new int[n];
    for (int i = 0; i < n; ++i) {
        trace[i] = -1;
    }
    int* lenLIS = new int[n];
    for (int i = 0; i < n; ++i) {
        lenLIS[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && lenLIS[j] + 1 > lenLIS[i]) {
                lenLIS[i] = lenLIS[j] + 1;
                trace[i] = j;
            }
        }
    }

    int maxLIS = 0;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (lenLIS[i] > maxLIS) {
            maxLIS = lenLIS[i];
            pos = i;
        }
    }

    int* LIS = new int[n];
    int size = 0;
    while (pos != -1) {
        LIS[size++] = pos;
        pos = trace[pos];
    }

    std::cout << "Length of LIS: " << size << '\n';
    std::cout << "LIS in array: ";
    for (int i = size - 1; i >= 0; --i) {
        std::cout << a[LIS[i]] << " \n"[i == 0];
    }

    delete[] trace;
    delete[] lenLIS;
    delete[] LIS;
}

void solveLISTopDown(int* a, int n) {
    std::cout << "Finding LIS using top-down method.\n";
    int** memoTable = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        memoTable[i] = new int[n]{};
        for (int j = 0; j < n; ++j) {
            memoTable[i][j] = -1;
        }
    }
    std::cout << "Length of LIS: ";
    std::cout << LISRecursion(a, n, -1, 0, memoTable);
    std::cout << '\n';
    for (int i = 0; i <= n; ++i) {
        delete[] memoTable[i];
    }
    delete[] memoTable;
}

int LISRecursion(int* a, int n, int prev, int cur, int** memoTable) {
    if (cur == n) {
        return 0;
    }

    if (memoTable[prev + 1][cur] >= 0) {
        return memoTable[prev + 1][cur];
    }

    int include = 0;
    if (prev < 0 || a[cur] > a[prev]) {
        include = 1 + LISRecursion(a, n, cur, cur + 1, memoTable);
    }

    int exclude = LISRecursion(a, n, prev, cur + 1, memoTable);
    memoTable[prev + 1][cur] = (include > exclude ? include : exclude);
    return memoTable[prev + 1][cur];
}