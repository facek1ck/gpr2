#include <iostream>
#include <string>
#include "node.h"

void push(node** stack, int number){
    node* current = *stack;

    node* newNode = (node*) malloc(sizeof(node));

    newNode->next = nullptr;
    newNode->number = number;

    if(current != nullptr) {
        while(current->next != nullptr) {

            current = current->next;
        }
        current->next = newNode;
    } else {

        *stack = newNode;
    }
}

int pop(node** stack) {
    node* current = nullptr;
    current = *stack;

    int tempNum;
    tempNum = 0;

    if(size(current) == 1) {
        tempNum = current->number;
        free(current);
        *stack = nullptr;
    } else if(size(current) > 1) {
        while(current->next != nullptr) {
            if(current->next->next == nullptr) {
                break;
            }
            current = current->next;
        }
        tempNum = current->next->number;
        free(current->next);
        current->next = nullptr;
    }

    return tempNum;
}


int size(node* stack){
    node* current = stack;

    int size;
    size = 0;

    if(current != nullptr) {
        ++size;

        while(current->next != nullptr) {
            current = current->next;
            ++size;
        }
    }

    return size;
}