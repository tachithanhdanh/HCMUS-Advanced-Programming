#ifndef FRACTION_HPP_
#define FRACTION_HPP_

#include <iostream>

struct Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction& frac);
    Fraction& operator=(const Fraction& frac);
    ~Fraction();
    void reduce();
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    static int gcd(int a, int b);
};

using Fraction_ptr = Fraction*;

#endif