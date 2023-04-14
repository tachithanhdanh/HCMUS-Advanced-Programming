#include "SinglyLinkedList.hpp"
#include <iostream>

int main(void) {
    SLL list;
    for (int i = 0; i < 10; ++i) {
        list.insertAtBeginning(i);
    }
    list.insertAfterK(99, 3);
    list.deleteANode(9);
    for (Node* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        std::cout << pNode->getData() << std::endl;
    }
    // list.deleteAllNode();
    list.deleteAtBeginning();
    std::cout << "da xong";
    return 0;
}