#ifndef EX2_GAME_H
#define EX2_GAME_H


#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

class Game {

public:
    /**
     * Constructor
     * @param p1 - first player.
     * @param p2 - second player.
     * @param b - the board.
     * @param game - game logic.
     */
    Game(Player* p1, Player* p2, Board* b, GameLogic* game);
    /**
     * Running the game.
     */
    void playGame();

private:
    Board* b;
    Player* p1;
    Player* p2;
    GameLogic* game;
};


#endif //EX2_GAME_H
