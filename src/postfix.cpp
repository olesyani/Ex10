// Copyright [2020] <Olesya Nikolaeva>

#include "postfix.h"
#include "MyStack.h"

std::string infix2postfix(std::string str) {
    MyStack<char> stack(400);
    MyStack<char> stackop(400);
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*')
            || (str[i] == '/')) {
            if (((str[i] == '+') || (str[i] == '-')) &&
                ((stackop.get() == '*') || (stackop.get() == '/'))) {
                while ((stackop.get() != '(') || (stackop.isEmpty() == true)) {
                    if (stack.get() != ' ')
                        stack.push(' ');
                    stack.push(stackop.pop());
                }
                stackop.push(str[i]);
            } else if ((((str[i] == '+') || (str[i] == '-'))
                        && ((stackop.get() == '+') || (stackop.get() == '-')))
                       || (((str[i] == '*') || (str[i] == '/'))
                           && ((stackop.get() == '*')
                               || (stackop.get() == '/')))) {
                if (stack.get() != ' ')
                    stack.push(' ');
                stack.push(stackop.pop());
                stackop.push(str[i]);
            } else {
                stackop.push(str[i]);
            }
        } else if (str[i] == '(') {
            stackop.push(str[i]);
        } else if (str[i] == ')') {
            while (stackop.get() != '(') {
                if (stack.get() != ' ')
                    stack.push(' ');
                stack.push(stackop.pop());
            }
            stackop.pop();
        } else if (str[i] != ' ') {
            stack.push(str[i]);
        } else {
            if (stack.get() != ' ')
                stack.push(' ');
        }
    }
    while (stackop.isEmpty() != true) {
        if (stack.get() != ' ')
            stack.push(' ');
        stack.push(stackop.pop());
    }
    char result[200] = {0};
    int index = stack.getIndex();
    while (stack.isEmpty() != true) {
        result[index] = stack.pop();
        index--;
    }
    return result;
}
