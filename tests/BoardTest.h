//
// Created by tamar on 28/11/17.
//

#ifndef EX2_BOARDTEST_H
#define EX2_BOARDTEST_H

#include "../gtest_src/gtest.h"
#include "../BoardConsole.h"

#include <iostream>
using namespace std;

class BoardTest: public testing::Test {
public:
    BoardTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX2_BOARDTEST_H
