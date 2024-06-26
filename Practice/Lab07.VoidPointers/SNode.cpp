#include "SNode.hpp"

Node::Node(void_ptr data, Node_ptr next): m_data(data), m_next(next) {}

Node::~Node() {
    std::cout << "Node destructor called for node has data address = " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete m_data;
}

Node* Node::nextNode() const {
    return this->m_next;
}

const void_ptr& Node::getData() const {
    return this->m_data;
}

void Node::setNextNode(Node_ptr next) {
    this->m_next = next;
    return;
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
    out << "Current node:";
    out << " address of data = " << node.getData();
    out << ", address = " << &node;
    out << ", pNext = " << node.nextNode();
    return out;
}

// std::istream& operator>>(std::istream& in, Node& node) {
//     in >> node.m_data;
//     return in;
// }
