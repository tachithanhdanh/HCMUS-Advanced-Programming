#include "SinglyLinkedList.hpp"

SNode::SNode(): m_data(0), m_pNext(nullptr) {}

SNode::SNode(int data, SNode* pNext): m_data(data), m_pNext(pNext) {}

SNode::~SNode() {
    std::cout << "destructor called for node has " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

SNode::SNode(const SNode& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

SNode& SNode::operator=(const SNode& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

SNode* SNode::nextNode() const {
    return this->m_pNext;
}

int SNode::getData() const {
    return this->m_data;
}

void SNode::setNextNode(SNode* pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream& operator<<(std::ostream& out, const SNode& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node; 
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, SNode& node) {
//     in >> node.m_data;
//     return in;
// }

SList::SList(): m_pHead(nullptr) {}

SList::~SList() {
    std::cout << "SList destructor called\n";
    this->deleteAllNode();
}

SList::SList(const SList& list) {
    this->deepCopy(list);
}

SList& SList::operator=(const SList& list) {
    // self-assigment check
    if (this == &list) {
        return *this;
    }

    // delete all nodes before deep copying
    this->deleteAllNode();
    this->deepCopy(list);

    return *this;
}

void SList::deepCopy(const SList& list) {
    // this->deleteAllNode();
    this->setHead(nullptr);
    SNode* pNode = list.getHead();
    SNode* cur;
    for (; pNode; pNode = pNode->nextNode()) {
        if (this->getHead() == nullptr) {
            this->setHead(new SNode(pNode->getData()));
            cur = this->getHead();
        } else {
            cur->setNextNode(new SNode(pNode->getData()));
            cur = cur->nextNode();
        }
    }
    return;
}

bool SList::isEmpty() const {
    return this->getHead() == nullptr;
}

void SList::setHead(SNode* pNode) {
    this->m_pHead = pNode;
    return;
}

SNode* SList::getHead() const {
    return this->m_pHead;
}

SNode* SList::getKthElement(int k) const {
    SNode* pNode = this->getHead();
    for(int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

SNode* SList::getElementWithX(int x) const {
    for (SNode* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        if (pNode->getData() == x) {
            return pNode;
        }
    }
    return nullptr;
}

SNode* SList::getTail() const {
    if (isEmpty()) return nullptr;
    SNode* pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SList::insertAtBeginning(int x) {
    SNode* new_pHead = new SNode(x, this->getHead());
    this->setHead(new_pHead);
    return;
}

void SList::insertAtEnding(int x) {
    SNode* pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(x);
        return;
    } 
    SNode* new_pTail = new SNode(x);
    pTail->setNextNode(new_pTail);
    return;
}

void SList::insertAfterK(int x, int k) {
    SNode* pNode = this->getElementWithX(k);
    this->insertAfterElement(pNode, x);
    return;
}

void SList::insertAfterKthElement(int x, int k) {
    // chia 3 TH
    // TH1: so am -> insertAtBeginning
    // TH2: binh thuong -> chen vo sau K, 
    // nho la set new_pNode->setNextNode(pNode->nextNode()) va sau do la pNode->setNextNode(new_pNode)
    // TH3: vuot qua mang -> chen vo sau Tail
    if (k < 0) {
        this->insertAtBeginning(x);
        return;
    }

    SNode* pNode = this->getKthElement(k);
    if (pNode) {
        this->insertAfterElement(pNode, x);
    } else {
        this->insertAtEnding(x);
    }
    return;
}

void SList::insertAtKthElement(int x, int k) {
    // chia 2 TH
    // TH1: so am hoac vuot qua size cua linked list 
    //      -> khong chen, bao loi
    // TH2: binh thuong -> chen vo sau K
    int n = this->countNode();
    if (k < 0 || k > n) {
        std::cout << "Invalid index to insert new element to linked list!\n";
        return;
    }

    // head case
    if (k == 0) {
        this->insertAtBeginning(x);
        return;
    }

    // tail case
    if (k == n) {
        this->insertAtEnding(x);
        return;
    }

    // somewhere in the middle case
    this->insertAfterElement(this->getKthElement(k - 1), x);
    return;
}

void SList::insertAfterElement(SNode* pNode, int x) {
    // only insert if it is not nullptr
    if (pNode) {
        SNode* pNext = pNode->nextNode();
        SNode* new_pNode = new SNode(x, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SList::insertOrderedList(int x) {
    if (this->getHead() == nullptr) {
        this->insertAtBeginning(x);
        return;
    }
    if (this->getHead()->getData() > x) {
        SNode* tmp = new SNode(x, this->getHead());
        this->setHead(tmp);
        return;
    }
    SNode* cur = this->getHead();
    for (; cur->nextNode(); cur = cur->nextNode()) {
        if (cur->nextNode()->getData() > x) {
            break;
        }
    }
    this->insertAfterElement(cur, x);
    return;
}

void SList::deleteAtBeginning() {
    SNode* old_pHead = this->getHead();
    if(this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

void SList::deleteANode(int k) {
    SNode* prev = nullptr;
    SNode* cur = this->getHead();
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur->getData() == k) {
            // if there is no prev, it must be a head.
            if (prev) {
                prev->setNextNode(cur->nextNode());
            } else {
                this->deleteAtBeginning();
                return;
            }
            break;
        }
    }
    delete cur;
    return;
}

void SList::deleteKthNode(int k) {
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
    SNode* prev = nullptr;
    SNode* cur = this->getHead();
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

void SList::deleteAtEnding() {
    SNode* pNode = this->getHead();

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

void SList::deleteAllNode() {
    while(this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const SList& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List:\n";
    for (SNode* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    return out;
}

// std::istream& operator>>(std::istream& in, SList& list) {
//     return in;
// }

void SList::inputSLL() {
    int x;
    SNode* cur;
    std::cout << "Input a Singly Linked list.\n";
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) {
            if (this->isEmpty()) {
                this->setHead(new SNode(x));
                cur = this->getHead();
            } else {
                cur->setNextNode(new SNode(x));
                cur = cur->nextNode();
            }
        }
    } while (x != -1);
    return;
}

void SList::displaySLL() const {
    std::cout << *this;
    return;
}

int SList::countNode() const {
    int count = 0;
    for (SNode* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}


// https://www.geeksforgeeks.org/reverse-a-linked-list/
SList* reversedSLL(const SList& list) {
    // create rList using copy constructor
    SList* rList = new SList(list);
    // rList->displaySLL();
    // if the list is empty, no need to reverse
    if (rList->getHead() == nullptr) {
        return rList;
    }

    SNode* prev = nullptr;
    SNode* cur = rList->getHead();
    SNode* next = nullptr;

    for (; cur; prev = cur, cur = next) {
        // store next node address before reverse
        next = cur->nextNode();
        
        // reverse current node by setting its next node to prev
        cur->setNextNode(prev);
    }

    rList->setHead(prev);

    return rList;
}

void SLLDemo() {
    using std::cout;
    SList *list = new SList();
    list->inputSLL();
    list->displaySLL();
    cout << "countNode(): " << list->countNode() << '\n';
    std::cout << "Reverse linked list: ";
    SList *rList = reversedSLL(*list);
    rList->displaySLL();
    int x;
    cout << "Please input a number x: ";
    std::cin >> x;
    cout << "Ordered linked list after add x: ";
    list->insertOrderedList(x);
    list->displaySLL();
    std::cout << "Head: " << list->getHead() << '\n';
    std::cout << "getKthElement(5): " << list->getKthElement(5) << '\n';
    std::cout << "getElementWithX(5): " << list->getElementWithX(5) << '\n';
    std::cout << "getTail(): " << list->getTail() << '\n';
    std::cout << "insertAtBeginning(8): ";
    list->insertAtBeginning(8);
    list->displaySLL();
    std::cout << "insertAtEnding(90): ";
    list->insertAtEnding(90);
    list->displaySLL();
    std::cout << "insertAfterK(25, 20): ";
    list->insertAfterK(25, 5);
    list->displaySLL();
    cout << "insertAfterKthElement(5): ";
    list->insertAfterKthElement(45, 5);
    list->displaySLL();
    cout << "insertAtKthElement(42, 5): ";
    list->insertAfterKthElement(42, 5);
    list->displaySLL();
    cout << "insertOrderedList(10): ";
    list->insertOrderedList(10);
    cout << "insertOrderedList(0): ";
    list->insertOrderedList(0);
    cout << "insertOrderedList(5): ";
    list->insertOrderedList(5);
    cout << "insertOrderedList(6): ";
    list->insertOrderedList(6);
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
    delete rList;
    return;
}


/*
bool isEmpty() const;
    SNode* getHead() const;
    SNode* getKthElement(int i) const;
    SNode* getElementWithX(int x) const;
    SNode* getTail() const;
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertElement(SNode* pNode, int x);
    void insertOrderedNode(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
*/
