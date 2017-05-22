#include<iostream>
#include"Fract.h"
using namespace std;

class FloatFraction:public Fraction {
    public:
    FloatFraction() {} // Default Constructor
    // F.F. inherits no contr's!
    double get_float() {
        double x = get_num();
        return x / get_den();
    }
};

int main() {
    FloatFraction fract1;

    fract1.set(1,2);
    cout << "1/2 is " << fract1.get_float() << endl;
    fract1.set(3, 5);
    cout << "3/5 is " << fract1.get_float() << endl;
    return 0;
}