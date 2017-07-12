#include"fract.h"
#include <iostream>

// -------------------------------------
// FRACTION CLASS FUNCTIONS

Fraction::Fraction(Fraction const &src) {
    cout << "Now calling copy constructor." << endl;
    num = src.num;
    den = src.den;
}

// Normalize: put fraction into standard form, unique
// for each mathematically different value.
//
void Fraction::normalize() {

    // Handle cases involving 0
    if (den == 0 || num == 0) {
        num = 0;
        den = 1;
    }

    // Put neg. sign in numerator only.
    if (den < 0) {
        num *= -1;
        den *= -1;
    }

    // Factor out GCF from numerator and denominator
    int n = gcf(num, den);
    num = num / n;
    den = den / n;

}

// Greatest Common Factor
//
int Fraction::gcf(int a, int b) {
    if (b == 0)
        return abs(a);
    else
        return gcf(b, a%b);
}

// Lowest Common Multiple
// 
int Fraction::lcm(int a, int b) {
    int n = gcf(a, b);
    return a / n * b;
}

Fraction Fraction::add(const Fraction &other) {
    Fraction fract;
    int lcd = lcm(den, other.den);
    int quot1 = lcd/den;
    int quot2 = lcd/other.den;
    fract.set(num * quot1 + other.num * quot2, lcd);
    return fract;
}

Fraction Fraction::mult(const Fraction &other) {
    Fraction fract;
    fract.set(num * other.num, den * other.den);
    return fract;
}

bool Fraction::operator==(const Fraction &other) {
    return (num == other.num && den == other.den);
}

// -------------------------------------
// FRACTION CLASS FRIEND FUNCTION
ostream &operator<<(ostream &os, Fraction &fr) {
    os << fr.num << "/" << fr.den;
    return os;
}