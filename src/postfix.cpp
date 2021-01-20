// Copyright 2021 Bekina Svetlana
#include "postfix.h"
#include "MyStack.h"
#include <cctype>

std::string infix2postfix(std::string expression) {
    MyStack<char> vspom(expression.length());
    std::string drvid;
    for (int i = 0; i <= expression.length(); i++) {
        if (isdigit(expression[i])) {
            drvid += expression[i];
            drvid += ' ';
        } else if (expression[i] != ' ') {
            if (!vspom.isEmpty()) {
                if (expression[i] == '+' || expression[i] == '-') {
                    while (!vspom.isEmpty() && vspom.get() != '(') {
                        drvid += vspom.get();
                        drvid += ' ';
                        vspom.pop();
                    }
                } else if (expression[i] == '*' || expression[i] == '/') {
                    while (!vspom.isEmpty() && vspom.get()
                        != '(' && vspom.get() != '+' && vspom.get() != '-') {
                        drvid += vspom.get();
                        drvid += ' ';
                        vspom.pop();
                    }
                } else if (expression[i] == ')') {
                    while (vspom.get() != '(') {
                        drvid += vspom.get();
                        drvid += ' ';
                        vspom.pop();
                    }
                    vspom.pop();
                } else if (expression[i] == '\0') {
                    while (!vspom.isEmpty()) {
                        drvid += vspom.get();
                        drvid += ' ';
                        vspom.pop();
                    }
                } else if (expression[i] == '.') {
                    drvid.erase(drvid.length() - 1);
                    while (isdigit(expression[i]) || expression[i] == '.') {
                        drvid += expression[i];
                        i++;
                    }
                    i--;
                    drvid += ' ';
                }
                if (expression[i] != ')' && expression[i] != ' '
                    && !isdigit(expression[i])) {
                    vspom.push(expression[i]);
                }
            } else {
                vspom.push(expression[i]);
            }
        }
    }
    drvid.erase(drvid.length() - 1);
    return drvid;
}
