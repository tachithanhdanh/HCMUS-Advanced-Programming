#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_
#include <iostream>

class DNode {
private:
    int m_data;
    DNode* m_pPrev;
    DNode* m_pNext;

public:
    DNode(int data = 0, DNode* pPrev = nullptr, DNode* pNext = nullptr);
    ~DNode();
    DNode(const DNode& node);
    DNode& operator=(const DNode& node);
    DNode* prevNode() const;
    DNode* nextNode() const;
    int getData() const;
    void setPrevNode(DNode* pNode);
    void setNextNode(DNode* pNode);
    friend std::ostream& operator<<(std::ostream& out, const DNode& node);
    // friend std::istream& operator>>(std::istream& in, DNode& node);
};

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
    DNode* getElementWithX(int x) const;
    void insertIntoEmptyList(int x);
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAfterKthElement(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertAfterElement(DNode* pNode, int x);
    void insertOrderedList(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(DNode* pNode);
    void delete1K(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputDLL();
    void displayDLL() const;
    int countNode() const;
    friend std::ostream& operator<<(std::ostream& out, const DList& list);
    // friend std::istream& operator>>(std::istream& in, DList& list);
};

void DLLDemo();

#endif