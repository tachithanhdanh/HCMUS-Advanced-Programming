#include "DemoDList.hpp"
#include <iostream>

using std::cout;

void DLLDemo() {
    // using std::cout;
    DList *list = new DList();
    demoInitAndCheckEmpty(list);
    demoFind(list);
    demoAdd(list);
    demoRemove(list);
    delete list;
    return;
}

void demoInitAndCheckEmpty(DList*& list) {
    cout << "Initialize doubly linked list: ";
    cout << "Check empty: isEmpty() = " << std::boolalpha << list->isEmpty() << '\n';
    list->inputDLL();
    list->displayDLL();
    return;
}

void demoFind(DList*& list) {
    int data;
    DNode* pNode = nullptr;
    cout << "findFirstData(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    cout << "list->findFirstData(" << data << "):\n";
    pNode = list->findFirstData(data);
    cout << "Data found at node having address: " << pNode << '\n';
    if (pNode) cout << "Node info: " << *pNode;

    cout << "findLastData(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    cout << "list->findLastData(" << data << "):\n";
    pNode = list->findLastData(data);
    cout << "Data found at node having address: " << pNode << '\n';
    if (pNode) cout << "Node info: " << *pNode;
    return;
}

void demoAdd(DList*& list) {
    int data;
    cout << "addHead(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    list->insertAtBeginning(data);
    cout << "List after inserting new head.\n";
    cout << *list;

    cout << "addTail(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    list->insertAtEnding(data);
    cout << "List after insering new tail.\n";
    cout << *list;

    int pos;
    cout << "addbeforeIthElement(data, i) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    cout << "Please input position to insert before: ";
    std::cin >> pos;
    list->insertBeforeKthElement(data, pos);
    cout << "List after inserting " << data << " before " << pos << ".\n";
    cout << *list;
    return;
}


void demoRemove(DList*& list) {
    cout << "removeHead() demonstration.\n";
    cout << "Removing head...\n";
    list->deleteAtBeginning();
    cout << "List after removing head.\n";
    cout << *list;

    cout << "removeTail() demonstration.\n";
    cout << "Removing Tail...\n";
    list->deleteAtEnding();
    cout << "List after removing tail.\n";
    cout << *list;

    int data;
    cout << "removeDataFirst(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    list->deleteFirstData(data);
    cout << "List after running removeDataFirst(" << data << ").\n";
    cout << *list;

    cout << "removeDataLast(data) demonstration.\n";
    cout << "Please input data: ";
    std::cin >> data;
    list->deleteLastData(data);
    cout << "List after running removeDataLast(" << data << ").\n";
    cout << *list;
    return;
}