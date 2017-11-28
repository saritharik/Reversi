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
    AI p2(&gameLogic, &bC);
    Game game(&p1, &p2, &bC, gameLogic);
    game.playGame();
    return 0;
}