//
// Created by Michael and Gabriel on 22-May-19.
//
#ifndef TESTS

#include <iostream>
#include <string>
#include "connect4_function.h"

using namespace std;


int main() {

    game_board *board = new game_board(9, 6);

    players *player1;
    players *player2;

    int option, draw = 0, col = -2;

    START:
    cout << "Choose: Human vs. Human (1), Human vs. Computer (2), Computer vs. Computer(3)" << endl;
    cin >> option;


    switch (option) {
        case 1:
            player1 = new human_player('A');
            player2 = new human_player('B');
            break;
        case 2:
            player1 = new human_player('A');
            player2 = new computer_player('B', board);
            break;
        case 3:
            player1 = new computer_player('A', board);
            player2 = new computer_player('B', board);
            break;
        default:
            cout << "Invalid option." << endl;
            goto START;
    }

    board->print_board();


    while (!board->is_full() && (!board->win(player1->getmName()) && !board->win(player2->getmName()))) {
        col = draw % 2 == 0 ? player1->throw_coin() : player2->throw_coin();

        if (!board->put_coin(col, draw % 2 == 0 ? player1->getmName() : player2->getmName())) {
            cout << "Not valid" << endl;
            continue;
        }

        board->print_board();
        ++draw;
    }


    if (board->win(player1->getmName())) {
        cout << "Player " << player1->getmName() << " won!";
    } else if (board->win(player2->getmName())) {
        cout << "Player " << player2->getmName() << " won!";
    } else if (board->is_full()) {
        cout << "Draw. No one won!";
    }


    delete (player1);
    delete (player2);
    delete (board);

    return 0;

}


#endif