#include "Board.h"

#include <regex>

Board::Board(int dimension) {
    this->dimension = dimension;
    this->mineBoard = vector<vector<int> >(dimension, vector<int>(dimension, -2));
    this->mineBoardPlaying = vector<vector<int> >(dimension, vector<int>(dimension, -2));
    setUp(dimension);
    placeMines(dimension);
}

void Board::setUp(int dimension) {
    showBoard(dimension, mineBoard);
}

void Board::placeMines(int dimension) {
    int mines = getMineAmountByDimension(dimension);
    if (mines == 3) {
        mineBoard.at(0).at(0) = 0;
        mineBoard.at(0).at(1) = 1;
        mineBoard.at(0).at(2) = -1;
        mineBoard.at(1).at(0) = 1;
        mineBoard.at(1).at(1) = 3;
        mineBoard.at(1).at(2) = 2;
        mineBoard.at(2).at(0) = -1;
        mineBoard.at(2).at(1) = 2;
        mineBoard.at(2).at(2) = -1;
    } else if (mines == 6) {
        mineBoard.at(0).at(0) = 0;
        mineBoard.at(0).at(1) = 0;
        mineBoard.at(0).at(2) = 0;
        mineBoard.at(0).at(3) = 1;
        mineBoard.at(0).at(4) = 1;
        mineBoard.at(0).at(5) = 1;

        mineBoard.at(1).at(0) = 0;
        mineBoard.at(1).at(1) = 0;
        mineBoard.at(1).at(2) = 0;
        mineBoard.at(1).at(3) = 2;
        mineBoard.at(1).at(4) = -1;
        mineBoard.at(1).at(5) = 2;

        mineBoard.at(2).at(0) = 0;
        mineBoard.at(2).at(1) = 0;
        mineBoard.at(2).at(2) = 0;
        mineBoard.at(2).at(3) = 3;
        mineBoard.at(2).at(4) = -1;
        mineBoard.at(2).at(5) = 3;

        mineBoard.at(3).at(0) = 2;
        mineBoard.at(3).at(1) = 2;
        mineBoard.at(3).at(2) = 1;
        mineBoard.at(3).at(3) = 2;
        mineBoard.at(3).at(4) = -1;
        mineBoard.at(3).at(5) = 2;

        mineBoard.at(4).at(0) = -1;
        mineBoard.at(4).at(1) = -1;
        mineBoard.at(4).at(2) = 1;
        mineBoard.at(4).at(3) = 1;
        mineBoard.at(4).at(4) = 1;
        mineBoard.at(4).at(5) = 1;

        mineBoard.at(5).at(0) = -1;
        mineBoard.at(5).at(1) = 3;
        mineBoard.at(5).at(2) = 1;
        mineBoard.at(5).at(3) = 0;
        mineBoard.at(5).at(4) = 0;
        mineBoard.at(5).at(5) = 0;
    } else if (mines == 10) {
        mineBoard.at(0).at(0) = 0;
        mineBoard.at(0).at(1) = 1;
        mineBoard.at(0).at(2) = 1;
        mineBoard.at(0).at(3) = 1;
        mineBoard.at(0).at(4) = 0;
        mineBoard.at(0).at(5) = 0;
        mineBoard.at(0).at(6) = 0;
        mineBoard.at(0).at(7) = 0;
        mineBoard.at(0).at(8) = 0;
        mineBoard.at(0).at(9) = 0;

        mineBoard.at(1).at(0) = 0;
        mineBoard.at(1).at(1) = 1;
        mineBoard.at(1).at(2) = -1;
        mineBoard.at(1).at(3) = 1;
        mineBoard.at(1).at(4) = 0;
        mineBoard.at(1).at(5) = 0;
        mineBoard.at(1).at(6) = 0;
        mineBoard.at(1).at(7) = 0;
        mineBoard.at(1).at(8) = 0;
        mineBoard.at(1).at(9) = 0;

        mineBoard.at(2).at(0) = 1;
        mineBoard.at(2).at(1) = 2;
        mineBoard.at(2).at(2) = 1;
        mineBoard.at(2).at(3) = 1;
        mineBoard.at(2).at(4) = 0;
        mineBoard.at(2).at(5) = 1;
        mineBoard.at(2).at(6) = 2;
        mineBoard.at(2).at(7) = 2;
        mineBoard.at(2).at(8) = 1;
        mineBoard.at(2).at(9) = 0;

        mineBoard.at(3).at(0) = -1;
        mineBoard.at(3).at(1) = 1;
        mineBoard.at(3).at(2) = 0;
        mineBoard.at(3).at(3) = 0;
        mineBoard.at(3).at(4) = 0;
        mineBoard.at(3).at(5) = 2;
        mineBoard.at(3).at(6) = -1;
        mineBoard.at(3).at(7) = -1;
        mineBoard.at(3).at(8) = 1;
        mineBoard.at(3).at(9) = 0;

        mineBoard.at(4).at(0) = 1;
        mineBoard.at(4).at(1) = 1;
        mineBoard.at(4).at(2) = 1;
        mineBoard.at(4).at(3) = 1;
        mineBoard.at(4).at(4) = 2;
        mineBoard.at(4).at(5) = 3;
        mineBoard.at(4).at(6) = -1;
        mineBoard.at(4).at(7) = 3;
        mineBoard.at(4).at(8) = 1;
        mineBoard.at(4).at(9) = 0;

        mineBoard.at(5).at(0) = 0;
        mineBoard.at(5).at(1) = 0;
        mineBoard.at(5).at(2) = 1;
        mineBoard.at(5).at(3) = -1;
        mineBoard.at(5).at(4) = 2;
        mineBoard.at(5).at(5) = -1;
        mineBoard.at(5).at(6) = 2;
        mineBoard.at(5).at(7) = 1;
        mineBoard.at(5).at(8) = 0;
        mineBoard.at(5).at(9) = 0;

        mineBoard.at(6).at(0) = 0;
        mineBoard.at(6).at(1) = 0;
        mineBoard.at(6).at(2) = 1;
        mineBoard.at(6).at(3) = 1;
        mineBoard.at(6).at(4) = 2;
        mineBoard.at(6).at(5) = 1;
        mineBoard.at(6).at(6) = 1;
        mineBoard.at(6).at(7) = 0;
        mineBoard.at(6).at(8) = 0;
        mineBoard.at(6).at(9) = 0;

        mineBoard.at(7).at(0) = 0;
        mineBoard.at(7).at(1) = 0;
        mineBoard.at(7).at(2) = 0;
        mineBoard.at(7).at(3) = 1;
        mineBoard.at(7).at(4) = 1;
        mineBoard.at(7).at(5) = 1;
        mineBoard.at(7).at(6) = 0;
        mineBoard.at(7).at(7) = 0;
        mineBoard.at(7).at(8) = 1;
        mineBoard.at(7).at(9) = 1;

        mineBoard.at(8).at(0) = 1;
        mineBoard.at(8).at(1) = 1;
        mineBoard.at(8).at(2) = 1;
        mineBoard.at(8).at(3) = 1;
        mineBoard.at(8).at(4) = -1;
        mineBoard.at(8).at(5) = 1;
        mineBoard.at(8).at(6) = 0;
        mineBoard.at(8).at(7) = 0;
        mineBoard.at(8).at(8) = 1;
        mineBoard.at(8).at(9) = -1;

        mineBoard.at(9).at(0) = 1;
        mineBoard.at(9).at(1) = -1;
        mineBoard.at(9).at(2) = 1;
        mineBoard.at(9).at(3) = 1;
        mineBoard.at(9).at(4) = 1;
        mineBoard.at(9).at(5) = 1;
        mineBoard.at(9).at(6) = 0;
        mineBoard.at(9).at(7) = 0;
        mineBoard.at(9).at(8) = 1;
        mineBoard.at(9).at(9) = 1;
    }
}

int Board::checkAt(int x, int y) {
    return mineBoard.at(x - 1).at(y - 1);
}

int Board::checkAt(string position) {
    // check if position is safe, otherwise stop the game
    char cx;
    int y;
    parsePositionToCoordinate(position, cx, y);
    int x = c2i(cx);

    int result = checkAt(x, y);

    mineBoardPlaying.at(x - 1).at(y - 1) = result;
    showBoard(dimension, mineBoardPlaying);
    return result;
}

void Board::showBoard(int dimension, vector<vector<int> > board) {
    int margin = 5, halfmargin = margin / 2;
    string nbsp = " ";
    string nbspL1;
    string dash = "-";
    string dashL2 = "-";
    string cellDelimiter = "_";
    string midCellDel;
    string midCellDelLine;

    for (int i = 0; i < halfmargin; i++) {
        nbspL1 += nbsp;
    }
    for (int i = 0; i < margin; i++) {
        dashL2 += dash;
    }

    string line1 = "   |", line2 = "   +";
    string line[dimension];
    for (int i = 0; i < dimension; i++) {
        line1 += nbspL1 + to_string(i + 1) + nbspL1 + "|";
        line2 += dashL2;

        midCellDelLine = "";
        for (int j = 0; j < dimension; j++) {
            int value = board.at(i).at(j);
            if (value == -2) midCellDelLine += "_____";
            else if (value == -1) { midCellDelLine += "  X  "; } else midCellDelLine += "  " + to_string(value) + "  ";

            midCellDelLine += (i == 9 ? cellDelimiter : "") + midCellDel + "|";
        }

        line[i] += string{i2c(i + 1)} + " " + cellDelimiter + "|" + midCellDelLine + cellDelimiter;
    }
    // Handle line2 ending
    if (dimension < 10) line2[line2.length() - 1] = '+';
    else line2 += "+";

    cout << line1 << endl;
    cout << line2 << endl;

    for (int i = 0; i < dimension; i++) {
        cout << line[i] << endl;
    }
    cout << line2 << endl;
}

bool Board::isWin() {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            int val0 = mineBoard.at(i).at(j);
            if (val0 == -1) continue; // skip the mine
            if (val0 != mineBoardPlaying.at(i).at(j)) return false;
        }
    }

    return true;
}

/* Implement function in .h*/
char i2c(int i) {
    try {
        switch (i) {
            case 1: return 'a';
            case 2: return 'b';
            case 3: return 'c';
            case 4: return 'd';
            case 5: return 'e';
            case 6: return 'f';
            case 7: return 'g';
            case 8: return 'h';
            case 9: return 'i';
            case 10: return 'j';
            default: throw (i);
        }
    } catch (int errorCode) {
        cerr << "Out of range:" << errorCode << ". Allowed range is between 1 and 10 including." << endl;
    }
}

int c2i(const char &c) {
    try {
        switch (c) {
            case 'a': return 1;
            case 'b': return 2;
            case 'c': return 3;
            case 'd': return 4;
            case 'e': return 5;
            case 'f': return 6;
            case 'g': return 7;
            case 'h': return 8;
            case 'i': return 9;
            case 'j': return 10;
            default: throw (c);
        }
    } catch (char error) {
        cerr << "Out of range:" << string{error} << ". Allowed letter is between a and j including." << endl;
    }
}

int getMineAmountByDimension(int dimension) {
    switch (dimension) {
        case 3: return 3;
        case 6: return 6;
        case 10: return 10;
        default: return 3;
    }
}

void parsePositionToCoordinate(const std::string &position, char &letter, int &number) {
    if (!position.empty()) {
        letter = position[0]; // First character is the letter
        number = std::stoi(position.substr(1)); // Extract numeric part
    }
}
