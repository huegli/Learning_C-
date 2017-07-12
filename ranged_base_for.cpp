#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE_OF_ARRAY 5

int main() {
    int arr[SIZE_OF_ARRAY];
    int total = 0;

    // For each element, prompt for a value,
    // store, and add to total.
    // 
    for (int& n : arr) {
        cout << "Enter array value: ";
        cin >> n;
        total += n;
    }
    cout << "Here are the values: " << endl;

    // Print each element.
    //
    for (int n : arr)
        cout << n << endl;

    cout << "Total is: " << total << endl;
    cout << "Now, I'm going to zero out ";
    cout << "the values." << endl;

    // Set each element to 0.
    // 
    for (int& n : arr)
        n = 0;

    cout << "Here are the values: " << endl;
    for (int n: arr)
        cout << n << endl;
    return 0;  
}
