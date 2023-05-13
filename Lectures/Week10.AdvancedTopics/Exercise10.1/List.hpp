#ifndef LIST_HPP_
#define LIST_HPP_

#include "Node.hpp"

struct List {
    Node_ptr head;
};

void init(List& list);
bool isEmpty(const List& list);
void inputList(List& list);
void deleteAllNode(List& list);
void printList(const List& list);

#endif