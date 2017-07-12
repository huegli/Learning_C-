#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void convert_to_upper(char *s);

int main() {
    char s[100];

    cout << "Enter string to convert & press ENTER: ";
    cin.getline(s, 100);

    convert_to_upper(s);
    cout << "The converted string is:" << endl;
    cout << s << endl;

    return 0;
}

void convert_to_upper(char *s) {
    int length = strlen(s);

    for (int i = 0; i < length;i++)
        s[i] = toupper(s[i]);
}