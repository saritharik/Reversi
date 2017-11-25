//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//
#include <iostream>
#include "GameLogic.h"

using namespace std;

int main() {
    Human p1('X');
    Human p2('O');
    BoardConsole bC(8, 8);
    GameLogic game(&p1, &p2, &bC);
    game.playGame();
    return 0;
}