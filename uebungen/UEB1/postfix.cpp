

#include <iostream>
#include <string>
#include <sstream>
#include "node.h"
#include "postfix.h"

using namespace std;

int getResult(std::istream &input) {
    node *stack = nullptr;
    int number = 0, tmp1 = 0, tmp2 = 0;
    string inputstr;

    while(std::getline(input, inputstr, ' ')) {

        if(inputstr=="=") {

            if(stack != nullptr && stack->next == nullptr) {
                return pop(&stack);
            } else {
                return 0;
            }
        } else if(inputstr=="+") {

            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 + tmp2));
        } else if(inputstr=="-") {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 - tmp2));
        } else if(inputstr=="*") {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 * tmp2));
        } else if(inputstr=="/") {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 / tmp2));
        } else if(inputstr=="%") {
            tmp2 = pop(&stack);
            tmp1 = pop(&stack);

            push(&stack, (tmp1 % tmp2));
        } else {
            number = (int) stol(inputstr, nullptr, 10);
            push(&stack, number);
        }
    }
    return 0;
}
