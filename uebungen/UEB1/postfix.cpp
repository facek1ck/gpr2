#ifndef TESTS
// Main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include "postfix.h"
#include "node.h"

using namespace std;

int getResult(std::istream &input) {
    node *stack = nullptr;
    int number = 0, tmp1 = 0, tmp2 = 0;
    string inputstr;
    getline(input,inputstr);
    for(int i = 0; i<inputstr.length();i++) {
        number = (int) stol(inputstr, nullptr, 10);

        if(inputstr.find_last_not_of('=') != std::string::npos) {

            if(stack != nullptr && stack->next == nullptr) {
                return pop(&stack);
            } else {
                return 0;
            }
        } else if(inputstr.find_last_not_of('+') != std::string::npos) {

            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 + tmp2));
        } else if(inputstr.find_last_not_of('-') != std::string::npos) {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 - tmp2));
        } else if(inputstr.find_last_not_of('*') != std::string::npos) {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 * tmp2));
        } else if(inputstr.find_last_not_of('/') != std::string::npos) {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 / tmp2));
        } else if(inputstr.find_last_not_of('%') != std::string::npos) {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 % tmp2));
        } else {
            push(&stack, number);
        }
    }
    return 0;
}

#endif