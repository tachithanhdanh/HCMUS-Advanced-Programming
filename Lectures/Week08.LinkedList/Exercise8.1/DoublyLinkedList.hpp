#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_
#include "DNode.hpp"
#include <iostream>

class DList {
private:
    DNode* m_pHead = nullptr;
    DNode* m_pTail = nullptr;

public:
    DList();
    ~DList();
    DList(const DList& list);
    DList& operator=(const DList& list);
    void deepCopy(const DList& source);
    bool isEmpty() const;
    void setHead(DNode* pNode);
    void setTail(DNode* pNode);
    DNode* getHead() const;
    DNode* getTail() const;
    DNode* getKthElement(int i) const;
    DNode* findFirstData(int data) const;
    DNode* findLastData(int data) const;
    void insertIntoEmptyList(int x);
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAfterKthElement(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertBeforeKthElement(int x, int k);
    void insertAfterElement(DNode* pNode, int x);
    void insertOrderedList(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(DNode* pNode);
    void delete1K(int k);
    void deleteKthNode(int k);
    void deleteLastData(int data);
    void deleteFirstData(int data);
    void deleteAllNode();
    void inputDLL();
    void displayDLL() const;
    int countNode() const;
    friend std::ostream& operator<<(std::ostream& out, const DList& list);
    // friend std::istream& operator>>(std::istream& in, DList& list);
};

#endif