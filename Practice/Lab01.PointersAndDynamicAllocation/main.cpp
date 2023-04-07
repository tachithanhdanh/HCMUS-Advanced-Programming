#include "Process.h"
#include "IOFunctions.h"
#include "Fraction.h"
#include <iostream>

int main(void) {
    Fraction *p;
    int n;
    InputFractionArray(p, n);
    std::cout << "Mang phan so sau khi nhap: \n";
    OutputFractionArray(p, n);
    Fraction *a = new Fraction{2, 3};
    InsertAFractionToArray(p, n, a);
    std::cout << "Mang phan so sau khi chen (2/3): \n";
    OutputFractionArray(p, n);
    DeleteLastElement(p, n);
    std::cout << "Mang phan so sau khi xoa (2/3): \n";
    OutputFractionArray(p, n);
    // Ham huy vung nho sau khi cap phat
    DeleteFractionArray(p);
    return 0;
}