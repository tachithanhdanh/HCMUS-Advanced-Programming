#include "Process.hpp"
#include <cstring>
// #include <cassert>

int max(int a, int b) {
    return (a > b ? a : b);
}

int findMaximumElement(int *arr, int l, int r) {
    // assert(r < n);
    // assert(l < n);
    if (l == r) {
        return arr[l];
    }
    int mid = (l + r) / 2;
    int maxLeft = findMaximumElement(arr, l, mid);
    int maxRight = findMaximumElement(arr, mid + 1, r);
    return max(maxLeft, maxRight);
}

int findAnElementInArray(int *arr, int x, int l, int r) {
    if (l == r) {
        return (arr[l] == x ? l : -1);
    }
    int mid = (l + r) / 2;
    int findLeft = findAnElementInArray(arr, x, l, mid);
    int findRight = findAnElementInArray(arr, x, mid + 1, r);
    return max(findLeft, findRight);
}

void reverseString(char *s, int l, int r) {
    // similar to merge sort
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    reverseString(s, l, mid);
    reverseString(s, mid + 1, r);
    merge(s, l, mid, r);
    return;
}

void merge(char *s, int l, int mid, int r) {
    // int n = r - l + 1;
    int nLeft = mid - l + 1; // from left to mid
    int nRight = r - mid; // from mid + 1 to right
    char *sLeft = new char[nLeft]{};
    char *sRight = new char[nRight]{};
    for (int i = 0; i < nLeft; ++i) {
        sLeft[i] = s[i + l];
    }
    for (int i = 0; i < nRight; ++i) {
        sRight[i] = s[i + mid + 1];
    }
    int pos = l;
    for (int i = 0; i < nRight; ++i) {
        s[pos++] = sRight[i];
    }
    for (int i = 0; i < nLeft; ++i) {
        s[pos++] = sLeft[i];
    }
    return;
}

void currencyFormatter(long long m, char *money, int len, int cnt) {
    if (m == 0) return;
    money[len++] = static_cast<char>(m % 10 + '0');
    ++cnt;
    if (cnt % 3 == 0 && m / 10) {
        money[len++] = ',';
    }
    currencyFormatter(m / 10, money, len, cnt);
    money[std::strlen(money)] = '\0';
    return;
}