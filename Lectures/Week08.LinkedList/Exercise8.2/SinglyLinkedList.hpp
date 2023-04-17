#ifndef SINGLYLINKEDLIST_HPP_
#define SINGLYLINKEDLIST_HPP_
#include "SNode.hpp"
#include <iostream>

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

#endif