#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "Board.h"

class Minesweeper {
private:
    int dimension;
    Board board;

public:
    Minesweeper(Board board): board(board) {
        this->dimension = dimension;
    }

    void play(Board board);
};

int welcome();

int userChoiceToDimension(int choice);

int randomInt();

#endif //MINESWEEPER_Hva
