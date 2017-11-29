//
// Created by sarit on 29/11/17.
//

#ifndef EX2_USERPRINTERCONSOLE_H
#define EX2_USERPRINTERCONSOLE_H

#include "UserInterface.h"

class UserPrinterConsole: public UserInterface {
public:
    UserPrinterConsole();
    virtual void chooseRival();
    virtual void startMove();
    virtual void currentPlayerMsg(char disk);
    virtual void optionsToMove(vector<Point> points);
    virtual void uncorrectMoves(vector<Point> points);
    virtual void endOfGame(char disk);
};
#endif //EX2_USERPRINTERCONSOLE_H
