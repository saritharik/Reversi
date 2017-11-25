//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H

#include "BoardConsole.h"
#include <vector>
#include "Point.h"
#include "Human.h"

using namespace std;

class GameLogic {
public:
    /**
     * Constructor.
     * @param p1 first player.
     * @param p2 second player.
     */
    GameLogic(Player* p1, Player* p2, Board* b);
    /**
     * Running the game.
     */
    void playGame();
    /**
     * Replace one disk in other.
     * @param i the row.
     * @param j the col.
     */
    void replaceDisk(int i, int j);
    /**
     * Checking which points need to replace.
     * @param i the row.
     * @param j the col.
     * @param a the disk.
     * @return vector of all points.
     */
    vector<Point> checking(int i, int j, char a);
    /**
     * Make one move in the game.
     * @param i the row.
     * @param j the col.
     * @param a the disk.
     */
    void oneMove(int i, int j, char a);
    /**
     * Find the possible locations to put disks.
     * @param a the disk.
     * @return list of points.
     */
    vector<Point> findPoints(char a);
    /**
     * Check if the player choose right location.
     * @param p the selected point.
     * @param a the disk.
     * @return true or false.
     */
    bool possibleMoves(Point p, char a);
    int getPointsByPlayer(char player);

private:
    Board* b;
    vector<Point> v;
    Player* p1;
    Player* p2;

};


#endif //EX2_GAMEFLOW_H
