//
// Created by sarit on 25/11/17.
//

#ifndef EX2_AI_H
#define EX2_AI_H


#include "Player.h"
#include "GameLogic.h"

class AI: public Player {
public:
    AI(GameLogic *g, Board *b);
    /**
    * Choose square.
    * @return the location of the square.
    */
    virtual Point chooseSquare();
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk();
    int maxOption();
    void setPoint(int newPoints);
    int getPoint();

private:
    Board *board;
    GameLogic *game;
    int points;
};


#endif //EX2_AI_H
