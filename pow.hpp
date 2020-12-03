#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>

class Pow : public Base {
    public:
	Base* base;
	Base* power;
        Pow(Base* a, Base* b) : Base() { base = a; power = b; }
        virtual double evaluate() { return pow(base->evaluate(), power->evaluate());}
        virtual std::string stringify() {return base->stringify() + "**" + power->stringify();}	 
};

#endif
