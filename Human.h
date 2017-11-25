//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#ifndef EX2_HUMAN_H
#define EX2_HUMAN_H


#include "Player.h"
#include "Point.h"

class Human: public Player {
public:
    /**
     * Constructor.
     * @param p the disk.
     */
    Human(char p);
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
    /**
     * Set disk.
     * @param d the char of the disk.
     */
    void setDisk(char d);
    void setPoint(int newPoints);
    int getPoint();


private:
    char disk;
    int points;
};


#endif //EX2_HUMAN_H
