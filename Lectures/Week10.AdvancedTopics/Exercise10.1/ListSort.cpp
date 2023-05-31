#include "ListSort.hpp"
#include <iostream>

void sort(List& list) {
    list.head = merge_sort(list.head);
}

Node_ptr merge_sort(Node_ptr head) {
    // static int cnt = 0;
    // if (cnt > 10) return head;
    if (head == nullptr || head->next == nullptr) {
        // std::cout << cnt << std::endl;
        // std::cout << "Invoked\n";
        return head;
    }
    
    // std::cout << head << std::endl;
    // ++cnt;
    // std::cout << cnt << std::endl;
    Node_ptr mid = findMiddle(head);
    Node_ptr head2 = mid->next;
    mid->next = nullptr;
    // std::cout << "mid = " << mid << "\n";
    // std::cout << "head2 = " << head2 << '\n';
    // std::cout << std::endl;
    // merge_sort(head); merge_sort(head2);
    Node_ptr finalHead = merge(merge_sort(head), merge_sort(head2));
    return finalHead;
}

Node_ptr merge(Node_ptr firstNode, Node_ptr secondNode) {
    Node_ptr res;
    Node_ptr temp = new Node;
    res = temp;

    while (firstNode && secondNode) {
        // std::cout << firstNode->data << " " << secondNode->data << "\n";
        if (firstNode->data < secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        } else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    
    while (firstNode) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
    
    while (secondNode) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }

    temp = res;
    res = res->next;
    delete temp;

    return res;
}

Node_ptr findMiddle(Node_ptr head) {
    Node_ptr slowNode = head;
    Node_ptr fastNode = head->next; // in case there are two nodes it should return head
    while (fastNode && fastNode->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    return slowNode;
}