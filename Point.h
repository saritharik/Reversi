//
// Created by sarit on 06/11/17.
// Sarit Harik
// 315788547
//

#ifndef EX2_POINT_H
#define EX2_POINT_H


class Point {
public:
    /**
     * Constuctor.
     * @param x the x value.
     * @param y the y value.
     */
    Point(int x, int y);
    /**
     * Return the x value.
     * @return the x.
     */
    int getX();
    /**
     * Return the y value.
     * @return the y.
     */
    int getY();

private:
    int x, y;
};


#endif //EX2_POINT_H
