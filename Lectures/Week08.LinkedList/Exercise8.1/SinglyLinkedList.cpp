#include "SinglyLinkedList.hpp"

Node::Node(): m_data(0), m_pNext(nullptr) {}

Node::Node(int data, Node* pNext): m_data(data), m_pNext(pNext) {}

Node::~Node() {
    delete this->m_pNext;
}

Node::Node(const Node& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

Node& Node::operator=(const Node& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

Node* Node::nextNode() const {
    return this->m_pNext;
}

int Node::getData() const {
    return this->m_data;
}

void Node::setNextNode(Node* pNode) {
    this->m_pNext = pNode;
    return;
}

SLL::SLL(): m_pHead(nullptr) {}

SLL::~SLL() {}

SLL::SLL(const SLL& list) {
    
}

SLL& SLL::operator=(const SLL& list) {
    return *this;
}

bool SLL::isEmpty() const {
    return this->m_pHead == nullptr;
}

Node* SLL::getHead() const {
    return this->m_pHead;
}

Node* SLL::getIthElement(int i) const {
    Node* pNode = this->m_pHead;
    for(int j = 0; pNode && j != i; pNode = pNode->nextNode(), ++j);
    return pNode;
}

Node* SLL::getElementWithX(int x) const {
    for (Node* pNode = this->m_pHead; pNode; pNode = pNode->nextNode()) {
        if (pNode->getData() == x) {
            return pNode;
        }
    }
    return nullptr;
}

Node* SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node* pNode = this->m_pHead;
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SLL::insertAtBeginning(int x) {
    Node* new_pHead = new Node(x, this->m_pHead);
    this->m_pHead = new_pHead;
    return;
}

void SLL::insertAfterTail(int x) {
    Node* pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(x);
        return;
    } 
    Node* new_pTail = new Node(x);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAfterK(int x, int k) {
    // chia 3 TH
    // TH1: so am -> insertAtBeginning
    // TH2: binh thuong -> chen vo sau K, 
    // nho la set new_pNode->setNextNode(pNode->nextNode()) va sau do la pNode->setNextNode(new_pNode)
    // TH3: vuot qua mang -> chen vo sau Tail
    // Node* pPrev = nullptr;
    // Node* pNode = this->m_pHead;
    // for (int i = 0; pNode && i < k; pPrev = pNode, pNode = pNode->nextNode(), ++i);
    // Node* new_pNode = new Node(k, pPrev );
    return;
}
