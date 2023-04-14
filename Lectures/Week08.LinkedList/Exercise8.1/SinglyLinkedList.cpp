#include "SinglyLinkedList.hpp"

Node::Node(): m_data(0), m_pNext(nullptr) {}

Node::Node(int data, Node* pNext): m_data(data), m_pNext(pNext) {}

Node::~Node() {
    std::cout << "destructor called for node has" << this->getData() << "\n";
    delete this->m_pNext;
    this->m_pNext = nullptr;
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

std::ostream& operator<<(std::ostream& out, const Node& node) {
    out << "Current node: data = " << node.getData() << ", pNext = " << node.nextNode() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Node& node) {
    in >> node.m_data;
    return in;
}

SLL::SLL(): m_pHead(nullptr) {}

SLL::~SLL() {
    delete m_pHead;
}

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

void SLL::insertAtEnd(int x) {
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
    if (k < 0) {
        this->insertAtBeginning(x);
        return;
    }

    Node* pNode = getIthElement(k);
    if (pNode) {
        Node* pNext = pNode->nextNode();
        Node* new_pNode = new Node(x, pNext);
        pNode->setNextNode(new_pNode);
    } else {
        this->insertAtEnd(x);
    }
    return;
}

void SLL::insertOrderedNode(int x) {
    return;
}

void SLL::deleteAtBeginning() {
    Node* old_pHead = this->m_pHead;
    if(this->m_pHead) this->m_pHead = m_pHead->nextNode();
    old_pHead->setNextNode(nullptr);
    delete old_pHead;
    return;
}

void SLL::deleteANode(int k) {
    Node* prev = nullptr;
    Node* cur = this->m_pHead;
    for (; cur; cur = cur->nextNode()) {
        if (cur->getData() == k) {
            // if there is no prev, it must be a head.
            if (prev) {
                prev->setNextNode(cur->nextNode());
                cur->setNextNode(nullptr);
            } else {
                this->deleteAtBeginning();
            }
            break;
        }
    }
    return;
}

void SLL::deleteTail() {
    return;
}

void SLL::deleteAllNode() {
    delete this->m_pHead;
    this->m_pHead = nullptr;
    return;
}

std::ostream& operator<<(std::ostream& out, const SLL& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List:\n";
    for (Node* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << pNode;
    }
    return out;
}

std::istream& operator>>(std::istream& in, SLL& list) {
    return in;
}
