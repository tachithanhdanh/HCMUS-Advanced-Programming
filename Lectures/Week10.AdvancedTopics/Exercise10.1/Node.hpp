#ifndef NODE_HPP_
#define NODE_HPP_

struct Node;
using Node_ptr = Node*;

struct Node {
    int data;
    Node_ptr next;
};

Node_ptr getNode(int data);

#endif