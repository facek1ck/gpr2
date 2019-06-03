//
// Created by Michael and Gabriel on 22-May-19.
//

#include "connect4_function.h"
#include <iostream>
#include <string>

using namespace std;

human_player::human_player(const char &name) : players::players() {
    this->mName = name;
}


human_player::~human_player() {}


int human_player::throw_coin() {
    int coin;

    cout<<"Player" << this->getmName() << " - Choose column where to throw coin: ";
    cin >> coin;

    return coin;
}

const char& human_player::getmName() const {
    return this->mName;
}