#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand() : Base() {}
	double val = std::rand()%100;
        virtual double evaluate() {return val;}
        virtual std::string stringify() { return std::to_string(val); }
};

#endif
