#ifndef DEQUE_HPP_
#define DEQUE_HPP_
#include "DNode.hpp"
#include <iostream>

class Deque {
private:
    DNode_ptr m_frontNode;
    DNode_ptr m_backNode;
    int m_size;
    void setFrontNode(DNode_ptr frontNode);
    DNode_ptr getFrontNode() const;
    void setBackNode(DNode_ptr backNode);
    DNode_ptr getBackNode() const;

public:
    Deque();
    ~Deque();
    Deque(const Deque&) = delete;
    Deque& operator=(const Deque&) = delete;
    bool empty() const;
    int size() const;
    void push_front(const int& data);
    void push_back(const int& data);
    void pop_front();
    void pop_back();
    int front() const;
    int back() const;
    void input();
    void clear();
    friend std::ostream& operator<<(std::ostream& out, const Deque& deque);
};

#endif