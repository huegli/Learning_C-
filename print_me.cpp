#include<iostream>
using namespace std;

class Printable {
    virtual void print_me(ostream &os) = 0;

    friend ostream &operator<<(ostream &os,
                       Printable &pr);
};

// Operator<< function:
// All this does is cause virtual function print_me
// to be called, sending output to the stream
//
ostream &operator<<(ostream &os, Printable &pr) {
    pr.print_me(os);
    return os;
};

// CLASSES SUBCLASSING PRINTABLE
//------------------------------

class P_int:public Printable {
    public:
      int n;

      P_int(){};
      P_int(int new_n) { n = new_n; };
      void print_me(ostream &os); // override
};

class P_dbl:public Printable {
    public:
      double val;

      P_dbl(){};
      P_dbl(double new_val) { val = new_val; };

      void print_me(ostream &os);
};

// IMPLEMENTATION OF PRINT_ME

void P_int::print_me(ostream &os) {
    os << n;
}

void P_dbl::print_me(ostream &os) {
    os << " " << val;
}

// MAIN FUNCTION
// ---------------------
int main() {
    Printable *p;
    P_int num1(5);
    P_dbl num2(6.25);

    p = &num1;
    cout << "Here is a number: " << *p << endl;
    p = &num2;
    cout << "Here is another: " << *p << endl;
    return 0;
}