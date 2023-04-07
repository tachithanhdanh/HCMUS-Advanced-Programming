#include "IOFunctions.h"
#include <iostream>

void InputFractionArray(Fraction *&p, int &n) {
    std::cout << "Nhap so phan tu n = ";
    std::cin >> n;
    p = new Fraction[n];
    std::cout << "Nhap mang phan so p (tu so va mau so cach nhau boi khoang trang): \n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap phan so thu " << i + 1 << ": ";
        std::cin >> p[i].numerator >> p[i].denominator;
    }
    return;
}

void OutputFractionArray(Fraction *p, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << p[i].numerator << '/' << p[i].denominator << '\n';
    }
    return;
}
