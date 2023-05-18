#include "sumOfPrime.hpp"
#include <iostream>

constexpr int MAX = static_cast<int>(1E5 + 10);

void solve() {
    std::cout << "Nhap so nguyen N = ";
    int N;
    std::cin >> N;
    int primeCount = 0;
    int* primeArray = new int[MAX / 10]{};
    generatePrimeArray(primeArray, primeCount);
    int* minPrimeSum = new int[N + 1]{};
    int* trace = new int[N + 1]{};
    sumOfPrime(N, minPrimeSum, primeCount, primeArray, trace);
    printSumOfPrime(N, trace);
    // for (int i = 0; i <= N; ++i) {
    //     std::cout << minPrimeSum[i] << '\n';
    // }
    // for (int i = 0; i <= N; ++i) {
    //     printSumOfPrime(i, trace);
    // }
    delete[] primeArray;
    delete[] minPrimeSum;
    delete[] trace;
}

void printSumOfPrime(int num, int* trace) {
    std::cout << "So nguyen " << num << " bieu dien duoi dang tong cac so nguyen to:\n";
    if (num < 2) {
        std::cout << "Khong ton tai cach bieu dien cho N = " << num << '\n';
        return;
    }
    std::cout << num << " = ";
    while (num) {
        std::cout << trace[num];
        num -= trace[num];
        if (num) std::cout << " + ";
    }
    std::cout.put('\n');
}

void sumOfPrime(int num, int* minPrimeSum, int primeCount, int* primeArray, int* trace) {
    for (int i = 1; i <= num; ++i) {
        minPrimeSum[i] = MAX;
    }
    int prevNum;
    for (int i = 0; i <= num; ++i) {
        for (int j = 0; j < primeCount; ++j) {
            prevNum = i - primeArray[j];
            if (prevNum < 0) {
                break;
            }
            if (minPrimeSum[i] > minPrimeSum[prevNum] + 1) {
                trace[i] = primeArray[j];
                minPrimeSum[i] = minPrimeSum[prevNum] + 1;
            }
        }
    }
}

void generatePrimeArray(int* primeArray, int& size) {
    bool* isPrime = new bool[MAX]{};
    for (int i = 0; i < MAX; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i ; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    size = 0;
    for (int i = 0; i < MAX; ++i) {
        if (isPrime[i]) {
            primeArray[size++] = i;
        }
    }
}