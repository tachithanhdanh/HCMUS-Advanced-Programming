#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_
#include <iostream>

class SNode {
private:
    int m_data;
    SNode* m_pNext;

public:
    SNode();
    SNode(int data, SNode* pNext = nullptr);
    ~SNode();
    SNode(const SNode& node);
    SNode& operator=(const SNode& node);
    SNode* nextNode() const;
    int getData() const;
    void setNextNode(SNode* pNext);
    friend std::ostream& operator<<(std::ostream& out, const SNode& node);
    // friend std::istream& operator>>(std::istream& in, SNode& node);
};

class SList {
private:
    SNode* m_pHead = nullptr;

public:
    SList();
    ~SList();
    SList(const SList& list);
    SList& operator=(const SList& list);
    void deepCopy(const SList& source);
    bool isEmpty() const;
    void setHead(SNode* pNode);
    SNode* getHead() const;
    SNode* getKthElement(int i) const;
    SNode* getElementWithX(int x) const;
    SNode* getTail() const;
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAfterKthElement(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertAfterElement(SNode* pNode, int x);
    void insertOrderedList(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
    void displaySLL() const;
    int countNode() const;
    friend std::ostream& operator<<(std::ostream& out, const SList& list);
    // friend std::istream& operator>>(std::istream& in, SList& list);
};

void SLLDemo();
SList* reversedSLL(const SList& list);

#endif