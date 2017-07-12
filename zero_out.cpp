#include <iostream>
using namespace std;

void zero_out_array(int *arr, int n);

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int i;

    zero_out_array(a, 10);

    // Print out all the elements of the array
    for (i = 0; i < 10;i++)
        cout << a[i] << " ";

    return 0;
}

// Zero-out-array function
// Assign 0 to all elements of an int array of size n.
//
void zero_out_array(int *p, int n) {
    while (n-- > 0)
        *p++ = 0;
}