#include "DemoSList.hpp"

// https://www.geeksforgeeks.org/reverse-a-linked-list/
SList* reversedSLL(const SList& list) {
    // create rList using copy constructor
    SList* rList = new SList(list);
    // rList->displaySLL();
    // if the list is empty, no need to reverse
    if (rList->getHead() == nullptr) {
        return rList;
    }

    SNode* prev = nullptr;
    SNode* cur = rList->getHead();
    SNode* next = nullptr;

    for (; cur; prev = cur, cur = next) {
        // store next node address before reverse
        next = cur->nextNode();
        
        // reverse current node by setting its next node to prev
        cur->setNextNode(prev);
    }

    rList->setHead(prev);

    return rList;
}

void SLLDemo() {
    using std::cout;
    SList *list = new SList();
    list->inputSLL();
    list->displaySLL();
    cout << "countNode(): " << list->countNode() << '\n';
    std::cout << "Reverse linked list: ";
    SList *rList = reversedSLL(*list);
    rList->displaySLL();
    int x;
    cout << "Please input a number x: ";
    std::cin >> x;
    cout << "Ordered linked list after add " << x << " into list.\n";
    list->insertOrderedList(x);
    list->displaySLL();
    delete list;
    delete rList;
    return;
}
