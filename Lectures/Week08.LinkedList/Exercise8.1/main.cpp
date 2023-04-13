#include "SinglyLinkedList.hpp"
#include <iostream>

int main(void) {
    SLL list;
    for (int i = 0; i < 10; ++i) {
        list.insertAtBeginning(i);
    }
    for (Node* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        std::cout << pNode->getData() << std::endl;
    }
    return 0;
}