// Copyright [2020] <Olesya Nikolaeva>

#include "postfix.h"
#include "MyStack.h"

std::string infix2prefix(std::string str) {
    MyStack<char> stack(200);
    MyStack<char> stackop(200);
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] == '+') or (str[i] == '-') or (str[i] == '*') or (str[i] == '/')) {
            if (((str[i] == '+') or (str[i] == '-')) and ((stackop.get() == '*') or (stackop.get() == '/'))) {
                while ((stackop.get() != '(') or (stackop.isEmpty() == true))
                    stack.push(stackop.pop());
                stackop.push(str[i]);
            }
            else if ((((str[i] == '+') or (str[i] == '-')) and ((stackop.get() == '+') or (stackop.get() == '-'))) or (((str[i] == '*') or (str[i] == '/')) and ((stackop.get() == '*') or (stackop.get() == '/')))) {
                stack.push(stackop.pop());
                stackop.push(str[i]);
            }
            else {
                stackop.push(str[i]);
            }
        }
        else if (str[i] == '(') {
            stackop.push(str[i]);
        }
        else if (str[i] == ')') {
            while (stackop.get() != '(')
                stack.push(stackop.pop());
            stackop.pop();
        }
        else if (str[i] != ' ') {
            stack.push(str[i]);
        }
    }
    while (stackop.isEmpty() != true)
        stack.push(stackop.pop());
    char result[200] = {0};
    int index = stack.getIndex();
    while (stack.isEmpty() != true) {
        result[index] = stack.pop();
        index--;
    }
    return result;
}
