#include "Minesweeper.h"
#include <vector>
#include <limits>


int main() {
    int welcomeCode = welcome();
    const int dimension = userChoiceToDimension(welcomeCode);
    Board board(dimension);
    Minesweeper game(board);
    game.play(board);
    return 0;
}

void Minesweeper::play(Board board) {
    bool start = true;
    string position;

    while (start) {
        cout << "Which box do you want to examine?" << endl;
        cin >> position;
        int value = board.checkAt(position);

        if (value == -1) {
            cout << "Sorry. You lost 😢😢😢" << endl;
            start = false;
        }

        if (board.isWin()) {
            cout << "Good job. You won 🎉🎉🎉" << endl;
            start = false;
        }
    }
}

int welcome() {
    int dimension;
    cout << "Welcome to the Minesweeper game!" << endl;
    bool start = true;

    while (start) {
        cout << "Kindly choose board dimensions from 1 to 3" << endl;
        cout << "1) 3x3 (Tutorial)" << endl;
        cout << "2) 6x6" << endl;
        cout << "3) 10x10" << endl;
        cin >> dimension;

        if (dimension >= 1 && dimension <= 3) {
            cout << "Thank you. Good luck!" << endl << endl;
            start = false;
        } else {
            if (cin.fail()) {
                // get rid of failure state
                cin.clear();
                // discard 'bad' character(s)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cout << "Ooops! You can only choose between 1 and 3. Try again, please!" << endl;
        }
    }
    return dimension;
}

int userChoiceToDimension(int choice) {
    switch (choice) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 10;
        default: return -1;
    }
}

int randomInt() {
    return (rand() % 10) + 1;
}
