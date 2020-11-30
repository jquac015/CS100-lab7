#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
    public:
        Base* val1;
        Base* val2;
        Add(Base* value1, Base* value2) : Base() { val1 = value1; val2 = value2;}
        virtual double evaluate() {return val1->evaluate()+val2->evaluate();}
        virtual std::string stringify() { return val1->stringify() + "+" + val2->stringify();}
};

#endif
