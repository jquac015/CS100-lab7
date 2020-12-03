#ifndef __FACTORY_TEST_HPP_
#define __FACTORY_TEST_HPP_

#include "gtest/gtest.h"

#include "factory.hpp"
#include "string.h"

TEST(FactoryTest, EvaluateSimpleAdd) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "+";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 10);
    EXPECT_EQ(test->stringify(), "5.000000+5.000000");
}
TEST(FactoryTest, EvaluateSimpleAddDecimal) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.5";
    expression[2] = "+";
    expression[3] = "5.5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 11);
    EXPECT_EQ(test->stringify(), "5.500000+5.500000");
}
TEST(FactoryTest, EvaluateSimpleAddNeg) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "-5";
    expression[2] = "+";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "(-5.000000)+5.000000");
}


TEST(FactoryTest, EvaluateSimpleSubtract) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "-";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "5.000000-5.000000");
}
TEST(FactoryTest, EvaluateSimpleSubtractDecimal) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.5";
    expression[2] = "-";
    expression[3] = "5.2";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_NEAR(test->evaluate(), 0.3, 1);
    EXPECT_EQ(test->stringify(), "5.500000-5.200000");
}
TEST(FactoryTest, EvaluateSimpleSubtractNeg) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "-5";
    expression[2] = "-";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), -10);
    EXPECT_EQ(test->stringify(), "(-5.000000)-5.000000");
}


TEST(FactoryTest, EvaluateSimpleMultiply) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "\*";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 25);
    EXPECT_EQ(test->stringify(), "5.000000*5.000000");
}
TEST(FactoryTest, EvaluateSimpleMultiplyDecimal) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.7";
    expression[2] = "\*";
    expression[3] = "5.2";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_NEAR(test->evaluate(), 29.64, 1);
    EXPECT_EQ(test->stringify(), "5.700000*5.200000");
}
TEST(FactoryTest, EvaluateSimpleMultiplyNeg) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "-5";
    expression[2] = "\*";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), -25);
    EXPECT_EQ(test->stringify(), "(-5.000000)*5.000000");
}

TEST(FactoryTest, EvaluateSimpleDivide) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "/";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ(test->stringify(), "5.000000/5.000000");
}
TEST(FactoryTest, EvaluateSimpleDivideNeg) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "-5";
    expression[2] = "/";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), -1);
    EXPECT_EQ(test->stringify(), "(-5.000000)/5.000000");
}
TEST(FactoryTest, EvaluateSimpleDivideDecimal) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.3";
    expression[2] = "/";
    expression[3] = "5.7";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_NEAR(test->evaluate(), 0.929, 1);
    EXPECT_EQ(test->stringify(), "5.300000/5.700000");
}


TEST(FactoryTest, EvaluateSimplePower) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "**";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 3125);
    EXPECT_EQ(test->stringify(), "5.000000**5.000000");
}
TEST(FactoryTest, EvaluateSimplePowerNeg) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "-5";
    expression[2] = "**";
    expression[3] = "5";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), -3125);
    EXPECT_EQ(test->stringify(), "(-5.000000)**5.000000");
}
TEST(FactoryTest, EvaluateSimplePowerDecimal) {
    int len = 4;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.1";
    expression[2] = "**";
    expression[3] = "5.1";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_NEAR(test->evaluate(), 4060.7654, 1);
    EXPECT_EQ(test->stringify(), "5.100000**5.100000");
}


TEST(FactoryTest, EvaluateCombination) {
    int len = 12;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5";
    expression[2] = "**";
    expression[3] = "5";
    expression[4] = "*";
    expression[5] = "5";
    expression[6] = "/"; 
    expression[7] = "25";
    expression[8] = "+";
    expression[9] = "5";
    expression[10] = "-";
    expression[11] = "10";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_EQ(test->evaluate(), 620);
    EXPECT_EQ(test->stringify(), "5.000000**5.000000*5.000000/25.000000+5.000000-10.000000");
}

TEST(FactoryTest, EvaluateMixed) {
    int len = 12;
    char** expression = new char*[len];
    expression[0] = "./calculator";
    expression[1] = "5.2";
    expression[2] = "**";
    expression[3] = "3.1";
    expression[4] = "*";
    expression[5] = "-1.1";
    expression[6] = "/";
    expression[7] = "5.2";
    expression[8] = "+";
    expression[9] = "10.9";
    expression[10] = "-";
    expression[11] = "7.1";
    factory* f = new factory();
    Base* test = f->parse(expression, len);
    EXPECT_NEAR(test->evaluate(), -31.275, 1);
    EXPECT_EQ(test->stringify(), "5.200000**3.100000*(-1.100000)/5.200000+10.900000-7.100000");
}

#endif
