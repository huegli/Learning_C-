#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int n = 0;

    cout << "Enter number of items: ";
    cin >> n;

    int *p = new int[n];    // Allocate n integers

    for (int i = 0; i < n; i++) {
        cout << "Enter item #" << i << ": ";
        cin >> p[i];
        sum += p[i];
    }

    cout << "Here are the items: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << ", ";
    cout << endl;
    cout << "The total is: " << sum << endl;
    cout << "The average is: " << (double)sum / n
                            << endl;

    delete[] p; // Release n integers

    return 0;
}