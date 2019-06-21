#ifndef TESTS

#include "fighters.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "#### WELCOME TO THE FIGHT CLUB ####" << endl;

    Fighter * fighters[10];
    for (int i = 0; i < 10; i++) {
        fighters[i] = nullptr;
    }

MENU:
    cout << endl;
    int choice = 0;
    cout << "-1 Create fighter" << endl;
    cout << "-2 Delete fighter" << endl;
    cout << "-3 View fighters" << endl;
    cout << "-4 Pick fighters" << endl;
    cout << "-5 Last man standing" << endl;
    cout << "-6 Exit game\n" << endl;
    cout << "Your choice:" << endl;
    cin >> choice;

    if(cin.fail() || choice < 1 || choice > 6) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again (1, 2, 3, 4, 5, 6)" << endl;
        goto MENU;
    } else {
        switch(choice) {
        case 1:
            create(fighters);
            goto MENU;
            break;
        case 2:
            deleteFighter(fighters);
            goto MENU;
            break;
        case 3:
            view(fighters);
            goto MENU;
            break;
        case 4:
            pick(fighters);
            goto MENU;
            break;
        case 5:
            lastManStanding(fighters);
            goto MENU;
            break;
        case 6:
            cout << "Game ending...";
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			delete(fighters[i]);
		}
	}

    return 0;
}

#endif
