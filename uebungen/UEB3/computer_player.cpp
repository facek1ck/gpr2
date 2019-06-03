//
// Created by Michael and Gabriel on 22-May-19.
//

#include "connect4_function.h"
#include <iostream>
#include <string>

using namespace std;

computer_player::computer_player(const char &name, game_board *spielfeld) {
    this->mName = name;

    this->gameboard = spielfeld;
}

computer_player::~computer_player() {}


int computer_player::throw_coin() {
    int i = 1;
    while (this->gameboard->is_column_full(i)) {
        i++;
    }
    return i;
}

const char &computer_player::getmName() const { return this->mName; }