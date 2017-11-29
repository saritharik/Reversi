//
// Created by sarit on 29/11/17.
//

#ifndef EX2_HUMANTEST_H
#define EX2_HUMANTEST_H
#include "../gtest_src/gtest.h"
#include "../Human.h"

class HumanTest: public testing::Test {
public:
    HumanTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX2_HUMANTEST_H
