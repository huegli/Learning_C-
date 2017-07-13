#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int rand_0toN1(int n);

int main() {
    int total, n;

    srand(time(NULL));  // Set seed for random numbers

    cout << "Welcome to NIM, Pick a starting total: ";
    cin >> total;
    while (true) {

        // Pick best response and print results

        if ((total % 3) == 2) {
            total = total - 2;
            cout << "I am substracting 2." << endl;
        } else if ((total % 3) == 1) {
            total--;
            cout << "I am substracting 1." << endl;
        } else {
            n = 1 + rand_0toN1(2); // n = 1 or 2
            total = total - n;
            cout << "I am substracting ";
            cout << n << "." << endl;
        }
        cout << "New total is " << total << endl;
        if (total == 0) {
            cout << "I win!" << endl;
            break;
        }

        // Get user's response: must be 1 or 2.
        cout << "Enter num to subtract (1 or 2): ";
        cin >> n;
        while (n < 1 || n > 2) {
            cout << "Input must be 1 or 2." << endl;
            cout << "Re-enter: ";
            cin >> n;
        }
        total = total - n;
        cout << "New total is " << total << endl;
        if (total == 0) {
            cout << "You win!" << endl;
            break;
        }
    }
    return 0;

    if (1 == 0) {
        cout << "This won't print" << endl;
    }
}

int rand_0toN1(int n) {
    return rand() % n;
}
