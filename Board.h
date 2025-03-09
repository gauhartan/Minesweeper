#ifndef BOARD_H
#define BOARD_H
#include "common.h"
#include <vector>


class Board {
private:
    int dimension;
    vector<vector<int> > mineBoard;
    vector<vector<int> > mineBoardPlaying;

public:
    Board(int dimension);

    void setUp(int dimension);

    void placeMines(int dimension);

    int checkAt(int x, int y);

    int checkAt(string position);

    void showBoard(int dimension, vector<vector<int> > board);

    bool isWin();
};

char i2c(int i);

int c2i(const char &c);

int getMineAmountByDimension(int dimension);

void parsePositionToCoordinate(const string &position, char &letter, int &number);

#endif //BOARD_H
