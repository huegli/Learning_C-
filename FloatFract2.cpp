#include<iostream>
#include"Fract.h"
using namespace std;

class FloatFraction:public Fraction {
    public:
      using Fraction::Fraction; // Inherit constr's.
      double float_val;
//      FloatFraction() { set(0, 1); }
//      FloatFraction(int n, int d) { set(n, d); }
//      FloatFraction(int n) { set(n, 1); }
//      FloatFraction(const FloatFraction &src)
//      {
//          set(src.get_num(), src.get_den()); }
//      FloatFraction& operator=(const Fraction &other) { return *this; }

        void normalize(); // overriden
};

void FloatFraction::normalize() {
    Fraction::normalize();
    float_val = (double)get_num() / get_den();
}

int main() {
    FloatFraction f1(1, 2), f2(1, 4);

    FloatFraction f3 = f1 + f2;
    cout << "1/2 + 1/4 = " << f3 << endl;
    cout << "Floating pt. value is " << f3.float_val << endl;
    cout << endl;
    return 0;
}