#include "Node.hpp"

Node_ptr getNode(int data) {
    Node_ptr node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}