#ifndef SINGLY_LINKED_LIST_HPP_
#define SINGLY_LINKED_LIST_HPP_

#include "SNode.hpp"
#include <iostream>

struct SLL {
private:
    int m_data_size;
    Node_ptr m_head = nullptr;

public:

    // constructors and destructors
    SLL(int data_size = 1, Node_ptr head = nullptr);
    ~SLL();

    // deleted methods
    SLL(const SLL& list) = delete;
    SLL& operator=(const SLL& list) = delete;
    void deepCopy(const SLL& source) = delete;

    // basic methods
    bool isEmpty() const;
    void setHead(Node_ptr pNode);
    Node_ptr getHead() const;
    Node_ptr getTail() const;
    Node_ptr getKthElement(int k) const;

    // operation 1
    void inputSLL() = delete;
    void insertAtBeginning(void_ptr data);

    // operation 2
    void displaySLL() const = delete;
    friend std::ostream& operator<<(std::ostream& out, const SLL& list) = delete;

    // operation 3
    void deleteAllNode();

    // operation 4
    void insertAtEnding(void_ptr data);
    
    // operation 5
    void insertAfterElement(Node_ptr pNode, void_ptr data);

    // operation 6
    void insertBeforeElement(Node_ptr pNode, void_ptr data);

    // operation 7
    void deleteAtBeginning();

    // operation 8
    void deleteAtEnding();

    // operation 9
    void deleteMiddle(Node_ptr pNode);

    // operation 10
    int countNode() const;

    // operation 11
    void insertBeforeKthElement(void_ptr data, int k);

    // operation 12
    void deleteKthNode(int k);
    
    // miscellaneous methods
    void deleteANode(void_ptr data);


    // void insertAfterKthElement(void_ptr data, int k);
    // friend std::istream& operator>>(std::istream& in, SLL& list);
};

#endif