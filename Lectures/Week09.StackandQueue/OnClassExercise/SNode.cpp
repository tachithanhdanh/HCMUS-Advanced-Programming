#include "SNode.hpp"

SNode::SNode(int data, SNode* pNext): m_data(data), m_pNext(pNext) {}

SNode::~SNode() {
    std::cout << "Destructor called for node having ";
    std::cout << "data = " << this->getData() << ", ";
    std::cout << "address = " << this << '\n';
}

int SNode::getData() const {
    return this->m_data;
}

SNode* SNode::nextNode() const {
    return this->m_pNext;
}

void SNode::setNextNode(SNode* pNext) {
    if (pNext == nullptr) return;
    this->m_pNext = pNext;
    return;
}

std::ostream& operator<<(std::ostream& out, const SNode& node) {
    out << "Current node: ";
    out << "data = " << node.getData() << ", ";
    out << "pNext = " << node.nextNode() << '\n';
    return out;
}
