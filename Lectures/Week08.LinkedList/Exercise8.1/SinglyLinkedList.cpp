#include "SinglyLinkedList.hpp"

Node::Node(): m_data(0), m_pNext(nullptr) {}

Node::Node(int data, Node* pNext): m_data(data), m_pNext(pNext) {}

Node::~Node() {
    std::cout << "destructor called for node has " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

Node::Node(const Node& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

Node& Node::operator=(const Node& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

Node* Node::nextNode() const {
    return this->m_pNext;
}

int Node::getData() const {
    return this->m_data;
}

void Node::setNextNode(Node* pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node; 
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, Node& node) {
//     in >> node.m_data;
//     return in;
// }

SLL::SLL(): m_pHead(nullptr) {}

SLL::~SLL() {
    std::cout << "SLL destructor called\n";
    this->deleteAllNode();
}

SLL::SLL(const SLL& list) {
    this->m_pHead = nullptr;
    Node* pNode = list.getHead();
    Node* cur;
    while (pNode) {
        cur = new Node(pNode->getData());
        if (this->m_pHead == nullptr) {
            this->m_pHead = cur;
        } else {
            cur->setNextNode(new Node(pNode->getData()));
            cur = cur->nextNode();
        }
    }
}

// SLL& SLL::operator=(const SLL& list) {
//     return *this;
// }

bool SLL::isEmpty() const {
    return this->m_pHead == nullptr;
}

Node* SLL::getHead() const {
    return this->m_pHead;
}

Node* SLL::getKthElement(int k) const {
    Node* pNode = this->m_pHead;
    for(int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

Node* SLL::getElementWithX(int x) const {
    for (Node* pNode = this->m_pHead; pNode; pNode = pNode->nextNode()) {
        if (pNode->getData() == x) {
            return pNode;
        }
    }
    return nullptr;
}

Node* SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node* pNode = this->m_pHead;
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SLL::insertAtBeginning(int x) {
    Node* new_pHead = new Node(x, this->m_pHead);
    this->m_pHead = new_pHead;
    return;
}

void SLL::insertAtEnding(int x) {
    Node* pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(x);
        return;
    } 
    Node* new_pTail = new Node(x);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAfterK(int x, int k) {
    Node* pNode = this->getElementWithX(k);
    this->insertElement(pNode, x);
    return;
}

void SLL::insertAtKthElement(int x, int k) {
    // chia 3 TH
    // TH1: so am -> insertAtBeginning
    // TH2: binh thuong -> chen vo sau K, 
    // nho la set new_pNode->setNextNode(pNode->nextNode()) va sau do la pNode->setNextNode(new_pNode)
    // TH3: vuot qua mang -> chen vo sau Tail
    if (k < 0) {
        this->insertAtBeginning(x);
        return;
    }

    Node* pNode = this->getKthElement(k);
    if (pNode) {
        this->insertElement(pNode, x);
    } else {
        this->insertAtEnding(x);
    }
    return;
}

void SLL::insertElement(Node* pNode, int x) {
    // only insert if it is not nullptr
    if (pNode) {
        Node* pNext = pNode->nextNode();
        Node* new_pNode = new Node(x, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SLL::insertOrderedNode(int x) {
    return;
}

void SLL::deleteAtBeginning() {
    Node* old_pHead = this->m_pHead;
    if(this->m_pHead) this->m_pHead = m_pHead->nextNode();
    delete old_pHead;
    return;
}

void SLL::deleteANode(int k) {
    Node* prev = nullptr;
    Node* cur = this->m_pHead;
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur->getData() == k) {
            // if there is no prev, it must be a head.
            if (prev) {
                prev->setNextNode(cur->nextNode());
            } else {
                this->deleteAtBeginning();
            }
            break;
        }
    }
    delete cur;
    return;
}

void SLL::deleteKthNode(int k) {
    // handle 5 cases:
    // k < 0: noop
    // k == 0: deleteAtBeginning
    // k > position: noop
    // k == position of last element: deleteAtEnding
    // otherwise delete normally
    if (k < 0) return;
    if (k == 0) {
        this->deleteAtBeginning();
        return;
    }
    Node* prev = nullptr;
    Node* cur = this->m_pHead;
    for (int i = 0; i != k && cur; prev = cur, cur = cur->nextNode(), ++i);
    // if cur is not nullptr
    if (cur) {
        if (prev) {
            prev->setNextNode(cur->nextNode());
        }
        delete cur;
    }
    return;
}

void SLL::deleteAtEnding() {
    Node* pNode = this->m_pHead;

    // if a list is empty then do nothing
    if (pNode == nullptr) {
        return;
    }

    // if a list has only one member (which is head) then delete head.
    if (pNode->nextNode() == nullptr) {
        this->deleteAtBeginning();
        return;
    }

    // move to the node that is adjacent to the last node
    for (; pNode->nextNode()->nextNode(); pNode = pNode->nextNode());
    // delete tail
    delete pNode->nextNode();
    pNode->setNextNode(nullptr);
    return;
}

void SLL::deleteAllNode() {
    while(this->m_pHead) {
        this->deleteAtBeginning();
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const SLL& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List:\n";
    for (Node* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    return out;
}

// std::istream& operator>>(std::istream& in, SLL& list) {
//     return in;
// }

void SLL::inputSLL() {
    int x;
    Node* cur;
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) {
            if (this->isEmpty()) {
                this->m_pHead = new Node(x);
                cur = this->m_pHead;
            } else {
                cur->setNextNode(new Node(x));
                cur = cur->nextNode();
            }
        }
    } while (x != -1);
    return;
}

void SLL::displaySLL() {
    std::cout << *this;
    return;
}

void SLLDemo() {
    using std::cout;
    SLL *list = new SLL();
    list->inputSLL();
    list->displaySLL();
    std::cout << "Head: " << list->getHead() << '\n';
    std::cout << "getKthElement(5): " << list->getKthElement(5) << '\n';
    std::cout << "getElementWithX(5): " << list->getElementWithX(5) << '\n';
    std::cout << "getTail(): " << list->getTail() << '\n';
    std::cout << "insertAtBeginning(100): ";
    list->insertAtBeginning(100);
    list->displaySLL();
    std::cout << "insertAtEnding(0): ";
    list->insertAtEnding(0);
    list->displaySLL();
    std::cout << "insertAfterK(5): ";
    list->insertAfterK(99, 5);
    list->displaySLL();
    cout << "insertAtKthElement(5): ";
    list->insertAtKthElement(98, 5);
    list->displaySLL();
    cout << "DeleteAtBeginning(): ";
    list->deleteAtBeginning();
    list->displaySLL();
    cout << "DeleteANode(5): ";
    list->deleteANode(5);
    list->displaySLL();
    cout << "DeleteKthNode(5): ";
    list->deleteKthNode(5);
    list->displaySLL();
    cout << "DeleteAllNode(): ";
    list->deleteAllNode();
    list->displaySLL();
    delete list;
    return;
}


/*
bool isEmpty() const;
    Node* getHead() const;
    Node* getKthElement(int i) const;
    Node* getElementWithX(int x) const;
    Node* getTail() const;
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertElement(Node* pNode, int x);
    void insertOrderedNode(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
*/
