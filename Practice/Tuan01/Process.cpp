#include "Process.h"
#include <algorithm>
#include <iostream>

void InsertAFractionToArray(Fraction *&p, int &n, Fraction *a) {
    int m = n + 1;
    Fraction *p_new = new Fraction[m];
    // if p_new != nullptr
    if (p_new) {
        std::copy(p, p + n, p_new);
        delete []p;
        std::swap(p, p_new);
        p[n] = *a;
        std::swap(n, m);
    } else {
        std::cout << "Khong the them duoc phan tu moi vao cuoi mang!\n";
    }
    return;
}

void DeleteLastElement(Fraction *&p, int &n) {
    int m = n - 1;
    Fraction *p_new = new Fraction[m];
    // if p_new != nullptr
    if (p_new) {
        std::copy(p, p + n - 1, p_new);
        delete []p;
        std::swap(p, p_new);
        std::swap(n, m);
    } else {
        std::cout << "Khong the xoa duoc phan tu moi vao cuoi mang!\n";
    }
    return;
}

void DeleteFractionArray(Fraction *&p) {
    delete []p;
    p = nullptr;
    return;
}