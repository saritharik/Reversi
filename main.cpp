//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//
#include <iostream>
#include "GameLogic.h"
#include "AI.h"
#include "Game.h"

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