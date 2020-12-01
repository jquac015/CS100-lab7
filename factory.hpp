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
#include <stack>
#include <vector>
class factory{
public:
    factory(){};
    Base* parse(char** input, int length){
        std::queue<char*> num;
        std::queue<char*> op;
        std::string temp;
        for(int i = 1; i < length; ++i) {
            temp = static_cast<std::string>(input[i]);
            if (isdigit(temp[0]) || isdigit(temp[1])) {
                num.push(input[i]);
            } else if (temp == "+" || temp == "-" || temp == "/" || temp == "*" || temp == "**") {
                op.push(input[i]);
            } else {
                std::cout << "Please type equation again." << std::endl;
                return nullptr;
            }
        }

        std::vector<Base*> calculate;
        int sz = num.size();
        for(int i = 0; i < sz; ++i){
            Op* in = new Op(stod(static_cast<std::string>(num.front())));
            calculate.push_back(in);
            num.pop();
        }
        std::stack<Base*> eval;
        for(int i = sz; i > 0; --i){
            eval.push(calculate[i - 1]);
        }
        Base* left;
        Base* right;
        Base* tempRes;
        double numRes;
        while(!op.empty()){
            std::string ope = static_cast<std::string>(op.front());
            if (ope == "+"){
                left = eval.top();
                eval.pop();
                right = eval.top();
                eval.pop();
                tempRes = new Add(left, right);
                eval.push(tempRes);
                op.pop();
            } else if (ope == "-"){
                left = eval.top();
                eval.pop();
                right = eval.top();
                eval.pop();
                tempRes = new Sub(left, right);
                eval.push(tempRes);
                op.pop();
            } else if (ope == "*") {
                left = eval.top();
                eval.pop();
                right = eval.top();
                eval.pop();
                tempRes = new Mult(left, right);
                eval.push(tempRes);
                op.pop();
            } else if (ope == "/") {
                left = eval.top();
                eval.pop();
                right = eval.top();
                eval.pop();
                tempRes = new Div(left, right);
                eval.push(tempRes);
                op.pop();
            } else if (ope == "**") {
                left = eval.top();
                eval.pop();
                right = eval.top();
                eval.pop();
                tempRes = new Pow(left, right);
                eval.push(tempRes);
                op.pop();
            }
        }
        return eval.top();
    }
};


#endif