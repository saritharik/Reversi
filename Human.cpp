//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#include "Human.h"
#include <iostream>
#include <limits>

using namespace std;

Human::Human(char p): disk(p) {}
Point Human::chooseSquare() {
    int x, y;
    char a;
    cin >> x >> a >> y;
    if(!x || !y) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Point(0, 0);
    }
    return Point(x, y);
}
char Human::getDisk() {
    return this->disk;
}
void Human::setDisk(char d) {
    this->disk = d;
}
int Human::getPoint() {
    return points;
}
void Human::setPoint(int newPoints) {
    this->points += newPoints;
}