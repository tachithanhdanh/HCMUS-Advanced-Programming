#ifndef SINGLY_LINKED_LIST_HPP_
#define SINGLY_LINKED_LIST_HPP_

#include "SNode.hpp"
#include <iostream>

struct SLL {
private:
    Node* m_head = nullptr;

public:

    // constructors and destructors
    SLL();
    ~SLL();

    // deleted methods
    SLL(const SLL& list) = delete;
    SLL& operator=(const SLL& list) = delete;
    void deepCopy(const SLL& source) = delete;

    // basic methods
    bool isEmpty() const;
    void setHead(Node* pNode);
    Node* getHead() const;
    Node* getKthElement(int k) const;
    Node* getTail() const;
    void insertAtBeginning(const Fraction& frac);
    void insertAtEnding(const Fraction& frac);
    void insertAtKthElement(const Fraction& frac, int k);
    void insertAfterElement(Node* pNode, const Fraction& frac);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(const Fraction& frac);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
    void displaySLL() const;
    int countNode() const;
    friend std::ostream& operator<<(std::ostream& out, const SLL& list);
    // friend std::istream& operator>>(std::istream& in, SLL& list);
};

#endif