#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>

template<typename T>
class Node;

template<typename T>
using Node_ptr = Node<T>*;

template<typename T>
class Node {
private:
    T m_data;
    Node_ptr<T> m_next;

public:
    Node();
    Node(T data, Node_ptr<T> next = nullptr);
    ~Node();
    Node(const Node& node) = delete;
    Node& operator=(const Node& node) = delete;
    Node_ptr<T> nextNode() const;
    const T& getData() const;
    void setNextNode(Node_ptr<T> next);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Node<U>& node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};


template<typename T>
Node<T>::Node(): m_data{}, m_next{nullptr} {}

template<typename T>
Node<T>::Node(T data, Node_ptr<T> next): m_data(data), m_next(next) {}

template<typename T>
Node<T>::~Node() {
    // std::cout << "Node destructor called for node has data address = " << this->getData();
    // std::cout << " at address " << this << '\n';
    // delete m_data;
}

template<typename T>
Node_ptr<T> Node<T>::nextNode() const {
    return this->m_next;
}

template<typename T>
const T& Node<T>::getData() const {
    return this->m_data;
}

template<typename T>
void Node<T>::setNextNode(Node_ptr<T> next) {
    this->m_next = next;
    return;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node;
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, Node& node) {
//     in >> node.m_data;
//     return in;
// }

#endif