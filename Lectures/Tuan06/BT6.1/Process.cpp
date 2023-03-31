#include "Process.hpp"
#include <iostream>
#include <iomanip>

int calculateSumUpToN(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    return n + calculateSumUpToN(n - 1);
}

long long pow(long long x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n & 1) return x * pow(x, n - 1);
    long long y = pow(x, n >> 1);
    return y * y;
}

long double calculateAlternatingHarnomicSeriesSum(int n) {
    if (n < 1) return 0.0L;
    if (n == 1) return 1.0L;
    long double sign = (n & 1 ? 1.0L : -1.0L);
    return sign / static_cast<long double>(n) + calculateAlternatingHarnomicSeriesSum(n - 1);
}

int binomialCoeff(int n, int k, int **C) {
    // base case
    if (k > n) return 0;
    if (C[n][k]) return C[n][k];
    if (k == 0 || k == n) {
        C[n][k] = 1;   
    } else {
        C[n][k] = binomialCoeff(n - 1, k - 1, C) + binomialCoeff(n - 1, k, C);
    }
    return C[n][k];
}

void printPascalTriange(int n) {
    int **C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[i + 1]{};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            // print iCj aka nCr (n >= r)
            std::cout << binomialCoeff(i, j, C) << " \n"[j == i];
        }
    }
    for (int i = 0; i < n; ++i) {
        delete []C[i];
        C[i] = nullptr;
    }
    delete []C;
    return;
}

void problemA() {
    int n;
    std::cout << "Day la cau a).\n";
    std::cout << "Moi thay nhap so nguyen duong n = ";
    std::cin >> n;
    std::cout << "Ket qua: A = " << calculateSumUpToN(n) << ".\n";
    return;
}

void problemB() {
    int n;
    long long x;
    std::cout << "Day la cau b).\n";
    std::cout << "Moi thay nhap so nguyen x = ";
    std::cin >> x;
    std::cout << "Moi thay nhap so nguyen duong n = ";
    std::cin >> n;
    std::cout << "Ket qua: B = " << pow(x, n) << ".\n";
    return;
}

void problemC() {
    int n;
    std::cout << "Day la cau c).\n";
    std::cout << "Moi thay nhap so nguyen duong n = ";
    std::cin >> n;
    std::cout << "Ket qua: C = " << std::setprecision(20)
              << calculateAlternatingHarnomicSeriesSum(n) << ".\n";
    return;
}

void problemD() {
    int N;
    std::cout << "Day la cau d).\n";
    std::cout << "Moi thay nhap so nguyen duong N = ";
    std::cin >> N;
    std::cout << "Tam giac pascal co chieu cao " << N << ": \n";
    printPascalTriange(N);
    return;
}
