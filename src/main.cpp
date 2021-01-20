// Copyright [2020] <Olesya Nikolaeva>

#include "postfix.h"
#include "MyStack.h"
#include <iostream>

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2=infix2prefix(s1);
    std::cout << s2 << std::endl;
    std::string s3("(5+9 - (7*6)/2)");
    std::string s4=infix2prefix(s3);
    std::cout << s4;
    return 0;
}
