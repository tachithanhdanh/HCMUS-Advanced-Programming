#ifndef SNODE_HPP_
#define SNODE_HPP_
#include <iostream>

class SNode {
private:
    int m_data;
    SNode* m_pNext;
public:
    SNode(int data = 0, SNode* pNext = nullptr);
    ~SNode();
    int getData() const;
    SNode* nextNode() const;
    void setNextNode(SNode* pNext);
    friend std::ostream& operator<<(std::ostream& out, const SNode& node);
};

#endif