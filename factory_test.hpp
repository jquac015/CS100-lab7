#ifndef __FACTORY_TEST_HPP_
#define __FACTORY_TEST_HPP_

#include "gtest/gtest.h"

#include "factory.hpp"

TEST(FactoryTest, EvaluateSimpleAdd) {
    char expression[] = "12 + 13";
    char** exp;
    *exp = expression;
    int len = 7;
    factory* f = new factory();
    Base* test = f->parse(exp, len);
    EXPECT_EQ(test->evaluate(), 15);
}

TEST(FactoryTest, EvaluateSimpleSubtract) {
    char expression[] = "12 - 13";
    char** exp;
    *exp = expression;
    int len = 7;
    factory* f = new factory();
    Base* test = f->parse(exp, len);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(FactoryTest, EvaluateSimpleMultiply) {
    char expression[] = "12 * 13";
    char** exp;
    *exp = expression;
    int len = 7;
    factory* f = new factory();
    Base* test = f->parse(exp, len);
    EXPECT_EQ(test->evaluate(), 156);
}
#endif
