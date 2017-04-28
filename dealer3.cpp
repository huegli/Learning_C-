#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int rand_0toN1(int n);
void draw_a_card();
int select_next_available(int n);

bool card_drawn[52];
int cards_remaining = 52;

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
    int n,card;

    if (cards_remaining == 0) {
        cout << "Reshuffling." << endl;
        cards_remaining = 52;       // Reset variable
        for (int i=0;i<52;i++)
            card_drawn[i]=false;
    }
    n = rand_0toN1(cards_remaining--);
    card = select_next_available(n);
    r = card % 13;          // r = random 0 to 12
    s = card / 13;          // s = random 0 to 3
    cout << ranks[r] << " of " << suits[s] << endl;
}

// Select-next-available-card function.
// Find the Nth element of card_drawn, skipping over
// those elements already set to true
//
int select_next_available(int n) {
    int i = -1;

    n++;    // Set up for n + 1 counting operations

    while (n-- > 0) {
        i++;            // Advance to next card
        while (card_drawn[i]) // Skip past cards
            i++;
    }
    card_drawn[i] = true;   // Note card to be drawn
    return i;               // Return this number
}
// Random 0-to-N1 Function
// Generate a random integer from 0 to N-1
//
int rand_0toN1(int n) {
    return rand() % n;
}
