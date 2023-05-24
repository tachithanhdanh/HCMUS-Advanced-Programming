#include "Fraction.hpp"
#include <limits>
#include <cmath>

const Fraction nullFrac(0, 0);

Fraction::Fraction(int num, int den) : m_numerator(num), m_denominator(den) {
    this->reduce();
}

Fraction::Fraction(const Fraction& frac) : Fraction(frac.m_numerator, frac.m_denominator) {}

Fraction& Fraction::operator=(const Fraction& frac) {
    // self-assignment check
    if (this == &frac) {
        return *this;
    }

    this->m_numerator = frac.m_numerator;
    this->m_denominator = frac.m_denominator;
    this->reduce();
    return *this;
}

Fraction::~Fraction() {}

void Fraction::reduce() {
    int _gcd = gcd(this->m_numerator, this->m_denominator);
    if (_gcd) {
        this->m_numerator /= _gcd;
        this->m_denominator /= _gcd;
    }

    if (this->m_numerator * this->m_denominator >= 0) {
        this->m_numerator = std::abs(this->m_numerator);
    } else {
        this->m_numerator = -std::abs(this->m_numerator);
    }
    this->m_denominator = std::abs(this->m_denominator);
    return;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    in >> frac.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> frac.m_denominator;
    frac.reduce();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.m_numerator << '/' << frac.m_denominator;
    return out;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(operator==(f1, f2));
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    return (operator<(f1, f2) || operator==(f1, f2));
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    return !operator<=(f1, f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    return !operator<(f1, f2);
}

// https://stackoverflow.com/questions/5373107/how-to-implement-static-class-member-functions-in-cpp-file
int Fraction::gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return std::abs(a);
}