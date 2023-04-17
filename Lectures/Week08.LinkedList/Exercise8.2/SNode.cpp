#include "SNode.hpp"

SNode::SNode(): m_data(0), m_pNext(nullptr) {}

SNode::SNode(int data, SNode* pNext): m_data(data), m_pNext(pNext) {}

SNode::~SNode() {
    std::cout << "destructor called for node has " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

SNode::SNode(const SNode& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

SNode& SNode::operator=(const SNode& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

SNode* SNode::nextNode() const {
    return this->m_pNext;
}

int SNode::getData() const {
    return this->m_data;
}

void SNode::setNextNode(SNode* pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream& operator<<(std::ostream& out, const SNode& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node; 
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, SNode& node) {
//     in >> node.m_data;
//     return in;
// }