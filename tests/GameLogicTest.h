//
// Created by tamar on 29/11/17.
//

#ifndef EX2_GAMELOGICTEST_H
#define EX2_GAMELOGICTEST_H
#include "../gtest_src/gtest.h"
#include "../GameLogic.h"
#include <iostream>
using namespace std;

class GameLogicTest: public testing::Test {
public:
    GameLogicTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX2_GAMELOGICTEST_H