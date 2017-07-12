#include <iostream>
using namespace std;

void print_arr(int *arr, int n);
void print_arr(double *arr, int n);
void print_arr(char **arr, int n);


int a[] = {1,1,2,3,5,8,13};
double b[] = {1.4142,3.141592};
char *c[] = {"Inken, Blinken, Nod"};

int main() {
    print_arr(a, 7);
    print_arr(b, 2);
    print_arr(c, 3);
    return 0;
}

void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void print_arr(double *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void print_arr(char **arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
