#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

int rand_0toN1(int n);

int hits[10];

int main() {
    int n;  // Number of trials, prompt from user
    int i;  // All-purpose loop variable
    int r;  // Holds a random value

    srand(time(NULL));  // Set seed for randomizing

    cout << "Enter how many trials and press ENTER: ";
    cin >> n;

    // Run n trials. For each trial, get a numb 0 to 9
    // and then increment the corresponding element
    // in the hits array.

    for (i = 0; i < n; i++) {
        r = rand_0toN1(10);
        hits[r]++;
    }

    // Print all elements in the hits array, along
    // with ratio of hits to EXPECTED hits (n / 10).

    for(i = 0;i < 10;i++) {
        cout << i << ":" << hits[i] << " Accuracy:";
        double results = hits[i];
        cout << results / (n / 10) << endl;
    }

    return 0;
}

// Random 0-to-N1 Function.
// Generate a random integer from 0 to N–1.
int rand_0toN1(int n) {
        return rand() % n;
}


