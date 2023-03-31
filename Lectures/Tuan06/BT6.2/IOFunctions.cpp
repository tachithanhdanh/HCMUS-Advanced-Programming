#include "IOFunctions.hpp"
#include "Process.hpp"
#include "constants.hpp"
#include <iostream>
#include <cstring>
#include <cassert>
#include <limits> // for std::numeric_limits

void solve() {
    std::cout << "Day la bai 6.2 (chia de tri)\n";
    int n = 0;
    int *arr = nullptr;
    readArray(arr, n);
    assert(arr != nullptr);

    // cau a
    std::cout << "Phan tu lon nhat trong mang la ";
    std::cout << findMaximumElement(arr, 0, n - 1) << ".\n";

    // cau b
    int x;
    std::cout << "Nhap phan tu x can tim trong mang nguyen 1 chieu: ";
    std::cin >> x;
    std::cout << "Vi tri cua phan tu x trong mang nguyen 1 chieu la (-1 la khong tim duoc): ";
    std::cout << findAnElementInArray(arr, x, 0, n - 1) << ".\n";

    // cau c
    char *s = new char[MAX]{};
    std::cout << "Nhap chuoi s can duoc dao nguoc thu tu: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(s, MAX);
    int len = static_cast<int>(std::strlen(s));
    reverseString(s, 0, len - 1);
    std::cout << "Chuoi s sau khi duoc dao: " << s << '\n';

    // cau d
    long long m;
    std::cout << "Nhap so tien m = ";
    std::cin >> m;
    std::memset(s, 0, MAX);
    currencyFormatter(m, s, 0, 0);
    len = static_cast<int>(std::strlen(s));
    s[len] = ' ';
    s[len + 1] = '$';
    s[len + 2] = '\0';
    len = static_cast<int>(std::strlen(s));
    reverseString(s, 0, len - 1);
    std::cout << "Dinh dang tien te cua m la: " << s << '\n';
    delete []s;
    s = nullptr;
}

void readArray(int *&arr, int &n) {
    std::cout << "Nhap so phan tu cua mang n = ";
    std::cin >> n;
    arr = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap phan tu thu " << i << ": ";
        std::cin >> arr[i];
    }
    return;
}