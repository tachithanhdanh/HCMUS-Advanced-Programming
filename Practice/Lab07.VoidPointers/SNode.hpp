#ifndef SNODE_HPP_
#define SNODE_HPP_

#include <iostream>

struct Node;
using Node_ptr = Node*;
using void_ptr = void*;

struct Node {
private:
    void_ptr m_data;
    Node_ptr m_next;

public:
    Node(void_ptr data = nullptr, Node_ptr next = nullptr);
    ~Node();
    Node(const Node& node) = delete;
    Node& operator=(const Node& node) = delete;
    Node_ptr nextNode() const;
    const void_ptr& getData() const;
    void setNextNode(Node_ptr next);
    friend std::ostream& operator<<(std::ostream& out, const Node& node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};

#endif