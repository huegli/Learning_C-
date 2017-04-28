#include <iostream>
using namespace std;

void double_it(int *p);

int main() {
    int a = 5, b = 6;

    cout << "Val. of a before doubling: " << a << endl;
    cout << "Val. of b before doubling: " << b << endl;

    double_it(&a);      // Pass address of a.
    double_it(&b);      // Pass address of b.

    cout << "Val. of a after doubling: " << a << endl;
    cout << "Val. of b after doubling: " << b << endl;

    return 0;
}

void double_it(int *p) {
    *p = *p * 2;
}