#include "Deque.hpp"

Deque::Deque()
    : m_frontNode(nullptr)
    , m_backNode(nullptr) 
    , m_size(0){}

Deque::~Deque() {
    std::cout << "Deque destructor called.\n";
    this->clear(); 
}

void Deque::setFrontNode(DNode_ptr frontNode) {
    m_frontNode = frontNode;
    return;
}

DNode_ptr Deque::getFrontNode() const {
    return m_frontNode;
}

void Deque::setBackNode(DNode_ptr backNode) {
    m_backNode = backNode;
    return;
}

DNode_ptr Deque::getBackNode() const {
    return m_backNode;
}

bool Deque::empty() const {
    return size() == 0;
}

int Deque::size() const {
    return m_size;
}

void Deque::push_front(const int& data) {
    DNode_ptr new_frontNode = new DNode(data, nullptr, getFrontNode());
    if (empty()) {
        setBackNode(new_frontNode);
    } else {
        // only do this if frontNode exists
        getFrontNode()->setPrevNode(new_frontNode);
    }
    setFrontNode(new_frontNode);
    ++m_size;
    return;
}

void Deque::push_back(const int& data) {
    if (empty()) {
        push_front(data);
        return;
    }
    DNode_ptr new_backNode = new DNode(data, getBackNode(), nullptr);
    getBackNode()->setNextNode(new_backNode);
    setBackNode(new_backNode);
    ++m_size;
    return;
}

void Deque::pop_front() {
    if (empty()) {
        return;
    }

    if (size() == 1) {
        delete getFrontNode();
        setFrontNode(nullptr);
        setBackNode(nullptr);
        m_size = 0;
        return;
    }

    DNode_ptr old_frontNode = getFrontNode();
    setFrontNode(old_frontNode->nextNode());
    getFrontNode()->setPrevNode(nullptr);
    delete old_frontNode;
    --m_size;
    return;
}

void Deque::pop_back() {
    if (size() <= 1) {
        pop_front();
        return;
    }

    DNode_ptr old_backNode = getBackNode();
    setBackNode(old_backNode->prevNode());
    getBackNode()->setNextNode(nullptr);
    delete old_backNode;
    --m_size;
    return;
}

int Deque::front() const {
    if (empty()) return -1;
    return getFrontNode()->getData();
}

int Deque::back() const {
    if (empty()) return -1;
    return getBackNode()->getData();
}

void Deque::clear() {
    while (getFrontNode() != nullptr) {
        pop_front();
    }
    return;
}

void Deque::input() {
    int x, mode;
    std::cout << "Input Deque.\n";
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) {
            std::cout << "Please input insert mode (0 is push_front, 1 is push_back): ";
            std::cin >> mode;
            if (mode) {
                push_back(x);
            } else {
                push_front(x);
            }
        }
    } while (x != -1);
    return;
}

std::ostream& operator<<(std::ostream& out, const Deque& deque) {
    out << "Double-ended queue ADT.\n";
    out << "Size: " << deque.size() << '\n';
    out << "Front element: " << deque.front() << '\n';
    out << "Back element: " << deque.back() << '\n';
    out << "Queue node list:\n";
    DNode* cur = deque.getFrontNode();
    if (cur == nullptr) out << "Empty deque!\n";
    while (cur) {
        out << *cur;
        cur = cur->nextNode();
    }
    return out;
}