#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    public:
        Base* a;
	Base* b;
        Sub(Base* first, Base* second) : Base() { a = first; b = second;}
        virtual double evaluate() {return (a->evaluate() - b->evaluate());}
        virtual std::string stringify() {return a->stringify() + "-" + b->stringify(); }
};

#endif
