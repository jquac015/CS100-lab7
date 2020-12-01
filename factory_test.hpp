#ifndef __FACTORY_TEST_HPP_
#define __FACTORY_TEST_HPP_

#include "gtest/gtest.h"

#include "factory.hpp"

TEST(FactoryTest, EvaluateSimpleAdd) {
    char** p = new char*[3];
    p[0] = "./calculator";
    p[1] = "-9";
    p[2] = "+";
    p[3] = "10";
    factory* f = new factory();
    Base* test = f->parse(p, 4);
    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "(-9.000000)+10.000000");
}

TEST(FactoryTest, EvaluateSimpleMinus) {
    char** p = new char*[3];
    p[0] = "./calculator";
    p[1] = "10";
    p[2] = "-";
    p[3] = "9";
    factory* f = new factory();
    Base* test = f->parse(p, 4);
    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "10.000000-9.000000");
}



#endif