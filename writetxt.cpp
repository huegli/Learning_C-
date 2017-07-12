#include <iostream>
#include <fstream>
using namespace std;

#define MAX_PATH 255

int main() {
    char filename[MAX_PATH + 1];

    cout << "Enter a file name and press ENTER: ";
    cin.getline(filename, MAX_PATH);
    ofstream file_out(filename);
    if (!file_out) {
        cout << filename << "could not be opened.";
        cout << endl;
        return -1;
    }
    cout << filename << "was opened." << endl;
    file_out << "I read the" << endl;
    file_out << "news today," << endl;
    file_out << "ooh boy.";
    file_out.close();
    return 0;
}