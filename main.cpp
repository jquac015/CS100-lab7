#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "factory.hpp"

int main(int argv, char** argc) {
    factory* f = new factory();
    Base* res = f->parse(argc, argv);

    if(res == nullptr) { std::cout << "Invalid input" << std::endl; }
    std::cout << "Number result is: " << res->evaluate() << std::endl;
    std::cout << "String result is: " << res->stringify() << std::endl;
    return 0;
}
