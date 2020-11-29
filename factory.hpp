#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <string>
#include <iostream>
#include <queue>

class factory{
public:
    factory(){};
    Base* parse(char** input, int length){
        std::queue<char*> num;
        std::queue<char*> op;
        std::string temp;
        for(int i = 1; i < length; ++i) {
            temp = static_cast<std::string>(input[i]);
            if (isdigit(temp[0])) {
                num.push(input[i]);
            } else if (temp == "+" || temp == "-" || temp == "/" || temp == "*" || temp == "**") {
                op.push(input[i]);
            } else {
                std::cout << "Please type equation again." << std::endl;
                return nullptr;
            }
        }

        std::queue<Base*> calculate;
        Base* left;
        Base* right;
        Base* tempRes;
        double numRes;
        while(!num.empty()){
            std::string ope = static_cast<std::string>(op.front());
            if (ope == "+"){
                //not sure if it works fine
                left = reinterpret_cast<Base *>(num.front());
                num.pop();
                right = reinterpret_cast<Base *>(num.front());
                num.pop();
                tempRes = new Add(left, right);
                calculate.push(tempRes);
                op.pop();
            } else if (ope == "-"){
                left = reinterpret_cast<Base *>(num.front());
                num.pop();
                right = reinterpret_cast<Base *>(num.front());
                num.pop();
                tempRes = new Sub(left, right);
                calculate.push(tempRes);
                op.pop();
            } else if (ope == "*") {
                left = reinterpret_cast<Base *>(num.front());
                num.pop();
                right = reinterpret_cast<Base *>(num.front());
                num.pop();
                tempRes = new Mult(left, right);
                calculate.push(tempRes);
                op.pop();
            } else if (ope == "/") {
                left = reinterpret_cast<Base *>(num.front());
                num.pop();
                right = reinterpret_cast<Base *>(num.front());
                num.pop();
                tempRes = new Div(left, right);
                calculate.push(tempRes);
                op.pop();
            } else if (ope == "**") {
                left = reinterpret_cast<Base *>(num.front());
                num.pop();
                right = reinterpret_cast<Base *>(num.front());
                num.pop();
                tempRes = new Pow(left, right);
                calculate.push(tempRes);
                op.pop();
            } else {
                //final result
                return calculate.front();
            }
        }
    }
};


#endif
