//
// Created by Michael and Gabriel on 22-May-19.
//

#include "connect4_function.h"
#include <iostream>
#include <string>

using namespace std;


game_board::game_board(int width, int height) {

    this->width = width;
    this->height = height;

    this->field = new char *[this->width];

    for (int col = 0; col < this->width; ++col) {
        this->getField()[col] = new char[height];
    }

    int col = 1, row = 1;


    //fill width dots
    for (int bcol = 0; bcol < this->width; ++bcol) {
        for (int brow = 0; brow < this->height; ++brow) {
            if (bcol == (this->width - 1) && brow != (this->height - 1)) {
                this->getField()[bcol][brow] = to_string(row)[0];
                row++;
            } else if (bcol != (this->width - 1) && brow == (this->height - 1)) {
                this->getField()[bcol][brow] = to_string(col)[0];
                col++;
            } else if (bcol == (this->width - 1) && brow == (this->height - 1)) {
                this->getField()[bcol][brow] = ' ';
            } else {
                this->getField()[bcol][brow] = '.';
            }
        }
    }

}

game_board::~game_board() {
    for (int col = 0; col < this->width; ++col) {
        delete[] this->getField()[col];
    }

    delete[] this->getField();
}

bool game_board::is_full() {
    for (int row = 0; row < this->height; ++row) {
        for (int col = 0; col < this->width; ++col) {
            if (this->getField()[col][row] == '.') {
                return false;
            }
        }
    }
    return true;
}


bool game_board::is_column_full(int column) {
    --column;

    for (int row = 0; row < this->height; ++row) {
        if (this->getField()[column][row] == '.') {
            return false;
        }
    }
    return true;
}

bool game_board::put_coin(int column, char player) {
    if (!is_column_full(column)) {
        --column;
        if (column >= 0 && column < (this->width - 1)) {
            int row;
            for (row = 0; row < (this->height - 1); ++row) {
                if (this->getField()[column][row] != '.') {
                    --row;
                    break;
                }

                if (row + 1 == (this->height - 1)) {
                    break;
                }
            }

            this->getField()[column][row] = player;

            return true;
        }
    }

    return false;
}

bool game_board::win(char player) {
    int row = 0, column = 0, matches = 0;

    //check rows for 4 matches
    for (row = 0; row < (this->height - 1); ++row) {
        matches = 0;
        for (column = 0; column < (this->width - 1); ++column) {
            if (getField()[column][row] == player) {
                matches++;
            } else {
                matches = 0;
            }
            if (matches >= 4) {
                return true;
            }

        }
    }

    //check cols for 4 matches
    for (column = 0; column < (this->width - 1); ++column) {
        matches = 0;
        for (row = 0; row < (this->width - 1); ++row) {
            if (getField()[column][row] == player) {
                matches++;
            } else {
                matches = 0;
            }
            if (matches >= 4) {
                return true;
            }
        }

    }

    // check diagonals for 4 matches
    // crop the field by 3 rows and cols as there is possibility for diagonal wins
    for (row = 0; row < (this->height - 4); ++row) {
        for (column = 3; column < this->width - 1; ++column) {
            matches = 0;
            int colToCheck = column, rowToCheck = row;
            for (int count = 0; count <= 4; ++count) {
                if (colToCheck < (this->width - 1) && rowToCheck < (this->height - 1) &&
                    colToCheck >= 0 && rowToCheck >= 0 &&
                    this->getField()[colToCheck][rowToCheck] == player) {
                    matches++;
                } else break;

                if (matches >= 4) {
                    return true;
                }

                colToCheck--;
                rowToCheck++;
            }
        }
    }


    for (row = 0; row < (this->height - 4); row++) {
        for (column = (this->width - 5); column >= 0; column--) {
            matches = 0;

            int colToCheck = column, rowToCheck = row;

            for (int count = 0; count <= 4; ++count) {
                if (colToCheck < (this->width - 1) && rowToCheck < (this->height - 1) && colToCheck >= 0 &&
                    rowToCheck >= 0 && this->getField()[colToCheck][rowToCheck] == player) {
                    matches++;
                } else break;


                if (matches >= 4) return true;

                colToCheck++;
                rowToCheck++;
            }
        }
    }

    return false;
}

void game_board::print_board() {
    for (int row = 0; row < this->height; ++row) {

        for (int col = 0; col < this->width; ++col) {
            cout << this->getField()[col][row];
        }
        cout << endl;

    }
    cout << endl;
}

char **game_board::getField() {
    return this->field;
}

