//
// Created by tamar on 28/11/17.
//

#include <iostream>
#include "Game.h"
Game::Game(Player *p1, Player *p2, Board *b, GameLogic* game):
        p1(p1), p2(p2), b(b), game(game) {}

void Game::playGame() {
    int count = 0;
    p1->setPoint(2);
    p2->setPoint(2);
    int sum = ((this->b->getDimensions() - 1) * (this->b->getDimensions() - 1));
    Player* currentPlayer = p1;
    vector<Point>::iterator iter;
    while(p1->getPoint() + p2->getPoint() < sum) {
        cout << "Current board:" << endl;
        this->b->printBoard();
        if (count == 0) {
            currentPlayer = p1;
        } else {
            currentPlayer = p2;
        }
        cout << currentPlayer->getDisk() << ": it's your move." << endl;
        vector<Point> po = game->findPoints(currentPlayer->getDisk());
        if (po.empty()) {
            vector<Point> v1 = game->findPoints(this->p1->getDisk());
            vector<Point> v2 = game->findPoints(this->p2->getDisk());
            cout << "No possible move. Play passes back to the other player."
                    "Press any key + enter to continue.";
            //char n;
            //cin >> n;
            if (count == 0) {
                count = 1;
            } else {
                count = 0;
            }
            if (v1.empty() && v2.empty()) {
                break;
            }
            continue;
        }
        cout << "Your possible moves:";
        for(iter = po.begin(); iter != po.end(); iter++) {
            cout << "(" << iter.base()->getX() << ", "
                 << iter.base()->getY() << ")";
        }
        cout << endl << endl;
        cout << "Please enter your move row,col: (example: x,y)";
        Point p = currentPlayer->chooseSquare();
        while ((!game->possibleMoves(p, currentPlayer->getDisk()))
               || (p.getY() == 0 && p.getX() == 0)) {
            cout << "This the possible moves:";
            po = game->findPoints(currentPlayer->getDisk());
            for(iter = po.begin(); iter != po.end(); iter++) {
                cout << "(" << iter.base()->getX() << ", "
                     << iter.base()->getY() << ")";
            }
            cout << endl;
            cout << "Please enter your move row,col: (example: x,y)";
            p = currentPlayer->chooseSquare();
        }
        vector<Point> n1 = game->checking(p.getX(), p.getY(), currentPlayer->getDisk());
        vector<Point> n2 = game->checking(p.getX(), p.getY(), currentPlayer->getDisk());
        game->oneMove(p.getX(), p.getY(), currentPlayer->getDisk());
        if (count == 0) {
            p1->setPoint(1 + n1.size());
            game->setPlayerPoints(p1->getDisk(), p1->getPoint());
            p2->setPoint(-n1.size());
            game->setPlayerPoints(p2->getDisk(), p2->getPoint());
        } else {
            p2->setPoint(1 + n2.size());
            game->setPlayerPoints(p2->getDisk(), p2->getPoint());
            p1->setPoint(-n2.size());
            game->setPlayerPoints(p1->getDisk(), p1->getPoint());
        }
        cout << endl;
        if (count == 0) {
            count = 1;
        } else {
            count = 0;
        }
    }
    this->b->printBoard();
    if (p1->getPoint() > p2->getPoint()) {
        cout << "X is the winner!";
    } else if (p2->getPoint() > p1->getPoint()) {
        cout <<  "O is the winner!";
    } else {
        cout << "The game ended in a draw";
    }
}