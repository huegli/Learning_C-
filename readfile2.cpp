#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_PATH 255
#define SCR_LINES 24

using namespace std;

int main(int argc, char *argv[]) {
    int c;  // input character
    int i;  // loop counter
    char filename[MAX_PATH + 1];
    char input_line[MAX_PATH + 1];


    if (argc > 1)
        strncpy(filename, argv[1], MAX_PATH);
    else {
        cout << "Enter a file name and press ENTER: ";
        cin.getline(filename, MAX_PATH);
    }

    ifstream file_in(filename);

    if (!file_in) {
        cout << filename << " could not be opened.";
        return -1;
    }

    while (true) {
        for (i = 1; i <= SCR_LINES && !file_in.eof(); i++) {
            file_in.getline(input_line, MAX_PATH);
            cout << input_line << endl;
        }

        if (file_in.eof())
            break;
        cout << endl;
        cout << "More? (Press 'O' & ENTER to quit.)";
        cin.getline(input_line, MAX_PATH);
        c = input_line[0];
        if (c == 'Q' || c == 'q')
            break;
    }
    return 0;
}

