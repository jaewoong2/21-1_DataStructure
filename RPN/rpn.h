//
// Created by 82109 on 2021-04-17.
//

#ifndef RPN_RPN_H
#define RPN_RPN_H
#include "stack.h"
#include <iostream>

void rpn() {
    Stack<double> stack;
    double operand_one, operand_two;
    char word;

    while ((word = std::cin.peek()) != '\n') {
        if (isdigit(word)) {
            std::cin >> operand_one;
            stack.push(operand_one);
        } else {
            std::cin >> word;
            operand_two = stack.pop();
            operand_one = stack.pop();
            switch (word) {
                case '+':
                    stack.push(operand_one + operand_two);
                    break;
                case '-':
                    stack.push(operand_one - operand_two);
                    break;
                case '*':
                    stack.push(operand_one * operand_two);
                    break;
                case '/':
                    if (operand_two == 0) {
                        std::cerr << "Division 0 is not allowed \n";
                    } else {
                        stack.push(operand_one / operand_two);
                    }
                    break;
                default:
                    break;
            }
        }
        while ((word = std::cin.peek()) == ' ') {
            std::cin.ignore(1, ' ');
        }
    }
    std::cout << stack.pop() << std::endl;
}
#endif //RPN_RPN_H
