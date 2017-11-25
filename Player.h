//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "Point.h"

class Player {
public:
    /**
     * Choose square.
     * @return the location of the square.
     */
    virtual Point chooseSquare() = 0;
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk() = 0;
    void setPoint(int points);
    int getPoint();

};


#endif //EX2_PLAYER_H
