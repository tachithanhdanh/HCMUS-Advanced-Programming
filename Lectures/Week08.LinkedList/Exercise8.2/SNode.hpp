#ifndef SNODE_HPP_
#define SNODE_HPP_
#include <iostream>

class SNode {
private:
    int m_data;
    SNode* m_pNext;

public:
    SNode();
    SNode(int data, SNode* pNext = nullptr);
    ~SNode();
    SNode(const SNode& node);
    SNode& operator=(const SNode& node);
    SNode* nextNode() const;
    int getData() const;
    void setNextNode(SNode* pNext);
    friend std::ostream& operator<<(std::ostream& out, const SNode& node);
    // friend std::istream& operator>>(std::istream& in, SNode& node);
};

#endif