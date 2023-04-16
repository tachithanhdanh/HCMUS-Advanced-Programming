#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "SNode.hpp"

class Queue {
private:
    SNode* m_frontNode;
    SNode* m_backNode;
    int m_size;
    void setFrontNode(SNode* frontNode);
    SNode* getFrontNode() const;
    void setBackNode(SNode* backNode);
    SNode* getBackNode() const;

public:
    Queue();
    ~Queue();
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
    bool empty() const;
    int size() const;
    void push(const int& data);
    void pop();
    int front() const;
    int back() const;
    void input();
    friend std::ostream& operator<<(std::ostream& out, const Queue& queue);
};

#endif