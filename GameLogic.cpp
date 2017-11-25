//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#include "GameLogic.h"
#include <iostream>
using namespace std;

GameLogic::GameLogic(Player* p1, Player* p2, Board* b): p1(p1), p2(p2), b(b) {}
void GameLogic::playGame() {
    int count = 0;
    p1->setPoint(2);
    p2->setPoint(2);
    int sum = ((this->b->getDimensions() - 1) * (this->b->getDimensions() - 1));
    Human currentPlayer(this->p1->getDisk());
    vector<Point>::iterator iter;
    while(p1->getPoint() + p2->getPoint() < sum) {
        cout << "Current board:" << endl;
        this->b->printBoard();
        if (count == 0) {
            currentPlayer.setDisk(this->p1->getDisk());
        } else {
            currentPlayer.setDisk(this->p2->getDisk());
        }
        cout << currentPlayer.getDisk() << ": it's your move." << endl;
        vector<Point> po = findPoints(currentPlayer.getDisk());
        if (po.empty()) {
            vector<Point> v1 = findPoints(this->p1->getDisk());
            vector<Point> v2 = findPoints(this->p2->getDisk());
            cout << "No possible move. Play passes back to the other player."
                    "Press any key + enter to continue.";
            char n;
            cin >> n;
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
        Point p = currentPlayer.chooseSquare();
        while ((!possibleMoves(p, currentPlayer.getDisk()))
               || (p.getY() == 0 && p.getX() == 0)) {
            cout << "This the possible moves:";
            po = findPoints(currentPlayer.getDisk());
            for(iter = po.begin(); iter != po.end(); iter++) {
                cout << "(" << iter.base()->getX() << ", "
                     << iter.base()->getY() << ")";
            }
            cout << endl;
            cout << "Please enter your move row,col: (example: x,y)";
            p = currentPlayer.chooseSquare();
        }
        vector<Point> n1 = checking(p.getX(), p.getY(), currentPlayer.getDisk());
        vector<Point> n2 = checking(p.getX(), p.getY(), currentPlayer.getDisk());
        oneMove(p.getX(), p.getY(), currentPlayer.getDisk());
        if (count == 0) {
            p1->setPoint(1 + n1.size());
            p2->setPoint(-n1.size());
        } else {
            p2->setPoint(1 + n2.size());
            p1->setPoint(-n2.size());
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
bool GameLogic::possibleMoves(Point p, char a) {
    bool b = false;
    vector<Point>::iterator iter;
    vector<Point> v = findPoints(a);
    for(iter = v.begin(); iter != v.end(); iter++) {
        if ((iter.base()->getX() == p.getX()) &&
                iter.base()->getY() == p.getY()) {
            b = true;
            break;
        }
    }
    return b;

}
void GameLogic::replaceDisk(int i, int j) {
    char a = this->b->getSquare(i,j);
    if (a == 'X') {
        this->b->setSquare(i, j, 'O');
    }
    if (a == 'O') {
        this->b->setSquare(i, j, 'X');
    }
}
void GameLogic::oneMove(int i, int j, char a) {
    this->b->setSquare(i, j, a);
    vector<Point> vec = this->checking(i, j, a);
    vector<Point>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        this->replaceDisk(it.base()->getX(),it.base()->getY());
    }
    this->v.clear();
}
vector<Point> GameLogic::findPoints(char a) {
    vector<Point> points;
    vector<Point> check;
    vector<Point>::iterator iter;
    for (int i = 1; i < this->b->getDimensions(); i++) {
        for (int j = 1; j < this->b->getDimensions(); j++) {
            if (this->b->getSquare(i, j) == ' ') {
                check = this->checking(i, j, a);
                if (check.size() != 0) {
                    points.push_back(Point(i, j));
                    check.clear();
                    this->v.clear();
                }

            }
        }
    }
    return points;
}
vector<Point> GameLogic::checking(int i, int j, char a) {
    vector<Point>::iterator it;
    int row = i; int col = j;
    char self = a, other;
    vector<Point> vecTemp;
    if (self == 'X') {
        other = 'O';
    } else {
        other = 'X';
    }
    while (i - 1 > 0) {
        if (this->b->getSquare(i-1, j) != ' ' &&
            this->b->getSquare(i-1, j) == other) {
            vecTemp.push_back(Point(i-1, j));
            i--;
        } else {
            if (this->b->getSquare(i - 1,j) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0) {
        if (this->b->getSquare(i, j-1) != ' ' &&
            this->b->getSquare(i, j-1) == other) {
            vecTemp.push_back(Point(i, j-1));
            j--;
        } else {
            if (this->b->getSquare(i,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j) != ' ' &&
            this->b->getSquare(i+1, j) == other) {
            vecTemp.push_back(Point(i+1, j));
            i++;
        } else {
            if (this->b->getSquare(i + 1,j) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i, j+1) != ' ' &&
            this->b->getSquare(i, j+1) == other) {
            vecTemp.push_back(Point(i, j+1));
            j++;
        } else {
            if (this->b->getSquare(i,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions() &&
            i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j+1) != ' ' &&
            this->b->getSquare(i+1, j+1) == other) {
            vecTemp.push_back(Point(i+1, j+1));
            j++; i++;
        } else {
            if (this->b->getSquare(i + 1,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j + 1 < this->b->getDimensions() &&
           i - 1 > 0) {
        if (this->b->getSquare(i-1, j+1) != ' ' &&
            this->b->getSquare(i-1, j+1) == other) {
            vecTemp.push_back(Point(i-1, j+1));
            j++; i--;
        } else {
            if (this->b->getSquare(i - 1,j + 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0 && i - 1 > 0) {
        if (this->b->getSquare(i-1, j-1) != ' ' &&
            this->b->getSquare(i-1, j-1) == other) {
            vecTemp.push_back(Point(i-1, j-1));
            j--; i--;
        } else {
            if (this->b->getSquare(i - 1,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    i = row; j = col;
    while (j - 1 > 0 &&
           i + 1 < this->b->getDimensions()) {
        if (this->b->getSquare(i+1, j-1) != ' ' &&
            this->b->getSquare(i+1, j-1) == other) {
            vecTemp.push_back(Point(i+1, j-1));
            j--; i++;
        } else {
            if (this->b->getSquare(i + 1,j - 1) == self) {
                this->v.insert(v.end(), vecTemp.begin(), vecTemp.end());
            }
            break;
        }
    }
    vecTemp.clear();
    return this->v;
}
int GameLogic::getPointsByPlayer(char player) {
    if (player == p1->getDisk()) {
        return p1->getPoint();
    } else {
        return p2->getPoint();
    }
}