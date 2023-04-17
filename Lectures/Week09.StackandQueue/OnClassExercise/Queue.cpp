#include "Queue.hpp"

Queue::Queue(): m_frontNode(nullptr), m_backNode(nullptr), m_size(0) {}

Queue::~Queue() {
    std::cout << "Queue destructor called.\n";
    while(!this->empty()) {
        this->pop();
    }
}

void Queue::setFrontNode(SNode* frontNode) {
    this->m_frontNode = frontNode;
    return;
}

SNode* Queue::getFrontNode() const {
    return this->m_frontNode;
}

void Queue::setBackNode(SNode* backNode) {
    this->m_backNode = backNode;
    return;
}

SNode* Queue::getBackNode() const {
    return this->m_backNode;
}

bool Queue::empty() const {
    return this->size() == 0;
}

int Queue::size() const {
    return this->m_size;
}

void Queue::push(const int& data) {
    SNode* newBackNode = new SNode(data);
    // if queue is not empty then we set current m_backNode points to newBackNode
    if (!this->empty()) {
        this->getBackNode()->setNextNode(newBackNode);
    } else {
        this->setFrontNode(newBackNode);
    }
    this->setBackNode(newBackNode);
    ++m_size;
    return;
}

void Queue::pop() {
    if (this->empty()) return;
    SNode* oldFrontNode = this->getFrontNode();
    this->setFrontNode(oldFrontNode->nextNode());
    if (this->getFrontNode() == nullptr) {
        // if queue is empty, then set backNode to nullptr
        this->setBackNode(nullptr);
    }
    delete oldFrontNode;
    --m_size;
    return;
}

int Queue::front() const {
    if (this->empty()) return -1;
    return this->getFrontNode()->getData();
}

int Queue::back() const {
    if (this->empty()) return -1;
    return this->getBackNode()->getData();
}

std::ostream& operator<<(std::ostream& out, const Queue& queue) {
    out << "Monotonic queue ADT.\n";
    out << "Size: " << queue.size() << '\n';
    out << "Front element: " << queue.front() << '\n';
    out << "Back element: " << queue.back() << '\n';
    out << "Queue node list:\n";
    SNode* cur = queue.getFrontNode();
    if (cur == nullptr) out << "Empty queue!\n";
    while (cur) {
        out << *cur;
        cur = cur->nextNode();
    }
    return out;
}

void Queue::input() {
    int x;
    std::cout << "Input Queue.\n";
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) this->push(x);
    } while (x != -1);
    return;
}