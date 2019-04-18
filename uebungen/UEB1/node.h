//
// Created by Gabriel Asherov on 2019-04-18.
//

#ifndef NODE_H
#define NODE_H


class node {
public:
    int number;
    node* next;
};

void push(node** stack, int number);
int pop(node** stack);
int size(node* stack);


#endif
