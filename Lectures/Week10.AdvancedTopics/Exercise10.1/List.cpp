#include "List.hpp"
#include <iostream>

void init(List& list) {
    list.head = nullptr;
}

bool isEmpty(const List& list) {
    return list.head == nullptr;
}

void inputList(List& list) {
    int x = -1;
    Node_ptr cur;
    std::cout << "Input a Singly Linked List.\n";
    do {
        std::cout << "Please input a number to add to linked list (-1 to stop): ";
        std::cin >> x;
        if (x != -1) {
            if (list.head == nullptr) {
                list.head = getNode(x);
                cur = list.head;
            } else {
                cur->next = getNode(x);
                cur = cur->next;
            }
        }
    } while (x != -1);
}

void deleteAllNode(List& list) {
    Node_ptr oldHead;
    while (list.head) {
        oldHead = list.head;
        list.head = list.head->next;
        delete oldHead;
    }
}

void printList(const List& list) {
    if (isEmpty(list)) {
        std::cout << "Empty list!\n";
        return;
    }
    std::cout << "Singly Linked List (print order from head to tail):\n";
    Node_ptr cur = list.head;
    for (; cur; cur = cur->next) {
        std::cout << cur->data;
        // std::cout << cur;
        if (cur->next) {
            std::cout << " -> ";
        }
    }
    std::cout.put('\n');
    // cur = list.head;
    // for (; cur; cur = cur->next) {
    //     // std::cout << cur->data;
    //     std::cout << cur;
    //     if (cur->next) {
    //         std::cout << " -> ";
    //     }
    // }
    // std::cout.put('\n');
}
