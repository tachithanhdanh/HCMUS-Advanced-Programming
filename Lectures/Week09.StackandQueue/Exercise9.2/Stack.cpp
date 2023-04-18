#include "Stack.hpp"

Stack::Stack(): m_size(0), m_topNode(nullptr) {}

Stack::~Stack() {
    // std::cout << "Stack destructor called.\n";
    while (!this->empty()) {
        this->pop();
    }
}

void Stack::setTopNode(SNode* topNode) {
    this->m_topNode = topNode;
    return;
}

SNode* Stack::getTopNode() const {
    return this->m_topNode;
}

int Stack::top() const {
    if (this->empty()) return -1;
    return this->getTopNode()->getData();
}

bool Stack::empty() const {
    return this->getTopNode() == nullptr;
}

int Stack::size() const {
    return this->m_size;
}

void Stack::push(const int& data) {
    SNode* new_topNode = new SNode(data, this->m_topNode);
    this->setTopNode(new_topNode);
    ++m_size;
    return;
}

void Stack::pop() {
    if (this->empty()) return;
    SNode* oldTopNode = this->getTopNode();
    this->setTopNode(oldTopNode->nextNode());
    delete oldTopNode;
    --m_size;
    return;
}

std::ostream& operator<<(std::ostream& out, const Stack& stack) {
    out << "Stack ADT.\n";
    out << "Size: " << stack.size() << '\n';
    out << "Top element: " << stack.top() << '\n';
    out << "Stack's node list:\n";
    SNode* cur = stack.getTopNode();
    if (cur == nullptr) out << "Empty stack!\n";
    while (cur) {
        out << *cur;
        cur = cur->nextNode();
    }
    return out;
}

void Stack::input() {
    int x;
    std::cout << "Input Stack.\n";
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) this->push(x);
    } while (x != -1);
    return;
}