#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
	double val;
        Op(double value) : Base() { val = value;}
        virtual double evaluate() {return val;}
        virtual std::string stringify() { 
		if(val<0){return "(" + std::to_string(val) + ")"; }
		else{return std::to_string(val);}
	}
};

#endif
