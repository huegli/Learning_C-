#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int rand_0toN1(int n);
void draw_a_card();

char *suits[4] =
    {"hearts", "diamonds", "spades", "clubs"};
char *ranks[13] =
    {"ace", "two", "three", "four", "five",
     "six", "seven", "eight", "nine",
     "ten", "jack", "queen", "king"};

int main() {
    int n, i;

    srand(time(NULL)); // Set seed for randomizing

    while(1) {
        cout << "Enter no. of cards to draw";
        cout << "(0 to exit):";
        cin >> n;
        if (n == 0)
            break;
        for (i=1;i<=n;i++)
            draw_a_card();
    }
    return 0;
}

// Draw-a-card function
// Perform a card draw by getting a rondom 0-4 and a 
// random 0-12. Use these to index the strings
// arrays, ranks and suits
//
void draw_a_card() {

    int r;      // Random index (0 thru 12) into
                // ranks array
    int s;      // Random index (0 thru 3) into
                // suits array

    r = rand_0toN1(13);
    s = rand_0toN1(4);
    cout << ranks[r] << " of " << suits[s] << endl;
}

// Random 0-to-N1 Function
// Generate a random integer from 0 to N-1
//
int rand_0toN1(int n) {
    return rand() % n;
}