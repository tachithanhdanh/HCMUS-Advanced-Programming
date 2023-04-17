#include "DNode.hpp"

DNode::DNode(int data, DNode* pPrev, DNode* pNext)
    : m_data(data)
    , m_pPrev(pPrev)
    , m_pNext(pNext) {}

DNode::~DNode() {
    std::cout << "Destructor called for node having " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

DNode::DNode(const DNode& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

DNode& DNode::operator=(const DNode& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

DNode* DNode::prevNode() const {
    return this->m_pPrev;
}

DNode* DNode::nextNode() const {
    return this->m_pNext;
}

int DNode::getData() const {
    return this->m_data;
}

void DNode::setPrevNode(DNode *pNode) {
    this->m_pPrev = pNode;
    return;
}

void DNode::setNextNode(DNode* pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream& operator<<(std::ostream& out, const DNode& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node; 
    out << ", pPrev = " << node.prevNode();
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, DNode& node) {
//     in >> node.m_data;
//     return in;
// }