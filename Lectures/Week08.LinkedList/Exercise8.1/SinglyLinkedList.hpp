#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_
#include <iostream>

class Node {
private:
    int m_data;
    Node* m_pNext;

public:
    Node();
    Node(int data, Node* pNext = nullptr);
    ~Node();
    Node(const Node& node);
    Node& operator=(const Node& node);
    Node* nextNode() const;
    int getData() const;
    void setNextNode(Node* pNext);
    friend std::ostream& operator<<(std::ostream& out, const Node& node);
    friend std::istream& operator>>(std::istream& in, Node& node);
};

class SLL {
private:
    Node* m_pHead;

public:
    SLL();
    ~SLL();
    SLL(const SLL& list);
    SLL& operator=(const SLL& list);
    bool isEmpty() const;
    Node* getHead() const;
    Node* getIthElement(int i) const;
    Node* getElementWithX(int x) const;
    Node* getTail() const;
    void insertAtBeginning(int x);
    void insertAtEnd(int x);
    void insertAfterK(int x, int k);
    void insertOrderedNode(int x);
    void deleteAtBeginning();
    void deleteTail();
    void deleteANode(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    friend std::ostream& operator<<(std::ostream& out, const SLL& list);
    friend std::istream& operator>>(std::istream& in, SLL& list);
};

#endif