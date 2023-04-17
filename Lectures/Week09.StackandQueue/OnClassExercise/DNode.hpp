#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <iostream>

class DNode {
private:
    int m_data;
    DNode* m_pPrev;
    DNode* m_pNext;

public:
    DNode(int data = 0, DNode* pPrev = nullptr, DNode* pNext = nullptr);
    ~DNode();
    DNode(const DNode& node);
    DNode& operator=(const DNode& node);
    DNode* prevNode() const;
    DNode* nextNode() const;
    int getData() const;
    void setPrevNode(DNode* pNode);
    void setNextNode(DNode* pNode);
    friend std::ostream& operator<<(std::ostream& out, const DNode& node);
    // friend std::istream& operator>>(std::istream& in, DNode& node);
};

using DNode_ptr = DNode*;

#endif