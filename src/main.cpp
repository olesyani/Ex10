// Copyright [2020] <Olesya Nikolaeva>

#include "postfix.h"
#include "MyStack.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2=infix2postfix(s1);
    std::cout << s2 << std::endl;
    std::string s3("(6 * (4 - 4 - 2) + 5) * (2.6 + 3 * 7)");
    std::string s4=infix2postfix(s3);
    std::cout << s4;
    return 0;
}
