//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#ifndef EX2_BOARDCONSOLE_H
#define EX2_BOARDCONSOLE_H

#include "Board.h"

class BoardConsole: public Board {
public:
    /**
     * Constructor.
     * @param row numbers of rows.
     * @param col numbers of columns.
     */
    BoardConsole(int row, int col);
    /**
     * Constructor.
     */
    BoardConsole();
    /**
     * Destructor.
     */
    ~BoardConsole();
    /**
     * Print the board.
     */
    virtual void printBoard() const;
    /**
     * Return the specific square.
     * @param i the row.
     * @param j the col.
     * @return the square.
     */
    virtual char getSquare(int i, int j);
    /**
     * Set square in the specific location.
     * @param i the row.
     * @param j the col.
     * @param p the char.
     */
    virtual void setSquare(int i, int j, char p);
    /**
     * Return the dimensions of the board.
     * @return the dimensions.
     */
    virtual int getDimensions();


private:
    int row;
    int col;
    char** array;
};

#endif //EX2_BOARDCONSOLE_H
