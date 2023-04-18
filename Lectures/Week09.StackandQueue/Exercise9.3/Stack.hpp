#ifndef STACK_HPP_
#define STACK_HPP_
#include "SNode.hpp"
#include <iostream>

class Stack {
private:
    int m_size;
    SNode* m_topNode;
    void setTopNode(SNode* topNode);
    SNode* getTopNode() const;

public:
    Stack();
    ~Stack();
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    int top() const;
    bool empty() const;
    int size() const;
    void push(const int& data);
    void pop();
    void input();
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack);
};

#endif