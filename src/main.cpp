#include <iostream>
#include "../include/GameLogic.h"
#include "../include/AI.h"
#include "../include/Game.h"

using namespace std;

int main() {

    BoardConsole bC(8, 8);
    GameLogic gameLogic(&bC);
    Human p1('X');
    cout << "Select your rival player:" << endl
         << "1 - Human player" << endl << "2 - AI player" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        Human p2('O');
        Game game(&p1, &p2, &bC, &gameLogic);
        game.playGame();
    } else if (choice == 2) {
        AI p2(&gameLogic, &bC);
        Game game(&p1, &p2, &bC, &gameLogic);
        game.playGame();
    }

    return 0;
}