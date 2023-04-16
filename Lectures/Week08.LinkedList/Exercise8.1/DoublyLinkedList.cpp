#include "DoublyLinkedList.hpp"

DNode::DNode(int data, DNode* pPrev, DNode* pNext)
    : m_data(data)
    , m_pPrev(pPrev)
    , m_pNext(pNext) {}

DNode::~DNode() {
    std::cout << "destructor called for node has " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

DNode::DNode(const DNode& node): m_data(node.m_data), m_pNext(node.m_pNext) {}

DNode& DNode::operator=(const DNode& node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

DNode* DNode::prevNode() const {
    return this->m_pPrev;
}

DNode* DNode::nextNode() const {
    return this->m_pNext;
}

int DNode::getData() const {
    return this->m_data;
}

void DNode::setPrevNode(DNode *pNode) {
    this->m_pPrev = pNode;
    return;
}

void DNode::setNextNode(DNode* pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream& operator<<(std::ostream& out, const DNode& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node; 
    out << ", pPrev = " << node.prevNode();
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, DNode& node) {
//     in >> node.m_data;
//     return in;
// }

DList::DList(): m_pHead(nullptr), m_pTail(nullptr) {}

DList::~DList() {
    std::cout << "DList destructor called\n";
    this->deleteAllNode();
}

DList::DList(const DList& list) {
    this->deepCopy(list);
}

DList& DList::operator=(const DList& list) {
    // self-assigment check
    if (this == &list) {
        return *this;
    }

    // delete all nodes before deep copying
    this->deleteAllNode();
    this->deepCopy(list);

    return *this;
}

void DList::deepCopy(const DList& list) {
    // this->deleteAllNode();
    this->setHead(nullptr);
    DNode* pNode = list.getHead();
    DNode* cur = nullptr;
    DNode* new_pTail = nullptr;
    for (; pNode; pNode = pNode->nextNode()) {
        // first ever node
        if (this->getHead() == nullptr) {
            DNode* firstNode = new DNode(pNode->getData());
            this->setHead(firstNode);
            this->setTail(firstNode);
            cur = this->getHead();
        } else {
            new_pTail = new DNode(pNode->getData(), cur, nullptr);
            cur->setNextNode(new_pTail);
            this->setTail(new_pTail);
            cur = cur->nextNode();
        }
    }
    return;
}

bool DList::isEmpty() const {
    return this->getHead() == nullptr;
}

void DList::setHead(DNode* pNode) {
    this->m_pHead = pNode;
    return;
}

void DList::setTail(DNode* pNode) {
    this->m_pTail = pNode;
    return;
}

DNode* DList::getHead() const {
    return this->m_pHead;
}

DNode* DList::getTail() const {
    return this->m_pTail;
}

DNode* DList::getKthElement(int k) const {
    DNode* pNode = this->getHead();
    for(int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

DNode* DList::getElementWithX(int x) const {
    for (DNode* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        if (pNode->getData() == x) {
            return pNode;
        }
    }
    return nullptr;
}

void DList::insertIntoEmptyList(int x) {
    DNode* pNode = new DNode(x);
    this->setHead(pNode);
    this->setTail(pNode);
    return;
}

void DList::insertAtBeginning(int x) {
    // special case
    if (this->isEmpty()) {
        this->insertIntoEmptyList(x);
        return;
    }

    DNode* cur_pHead = this->getHead();
    DNode* new_pHead = new DNode(x, nullptr, cur_pHead);
    cur_pHead->setPrevNode(new_pHead);
    this->setHead(new_pHead);
    return;
}

void DList::insertAtEnding(int x) {
    // special case
    if (this->isEmpty()) {
        this->insertIntoEmptyList(x);
        return;
    }

    DNode* cur_pTail = this->getTail();
    DNode* new_pTail = new DNode(x, cur_pTail, nullptr);
    cur_pTail->setNextNode(new_pTail);
    this->setTail(new_pTail);
    return;
}

void DList::insertAfterK(int x, int k) {
    DNode* pNode = this->getElementWithX(k);
    this->insertAfterElement(pNode, x);
    return;
}

void DList::insertAfterKthElement(int x, int k) {
    // chia 3 TH
    // TH1: so am -> insertAtBeginning
    // TH2: binh thuong -> chen vo sau K, 
    // nho la set new_pNode->setNextNode(pNode->nextNode()) va sau do la pNode->setNextNode(new_pNode)
    // TH3: vuot qua mang -> chen vo sau Tail
    if (k < 0) {
        this->insertAtBeginning(x);
        return;
    }

    DNode* pNode = this->getKthElement(k);
    if (pNode) {
        this->insertAfterElement(pNode, x);
    } else {
        this->insertAtEnding(x);
    }
    return;
}

void DList::insertAtKthElement(int x, int k) {
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

void DList::insertAfterElement(DNode* pNode, int x) {
    //  handle tail case
    if (pNode == this->getTail()) {
        this->insertAtEnding(x);
    }

    // only insert if it is not nullptr
    if (pNode) {
        DNode* pNext = pNode->nextNode();
        DNode* new_pNode = new DNode(x, pNode, pNext);
        pNode->setNextNode(new_pNode);
        pNext->setPrevNode(new_pNode);
    }
    return;
}

void DList::insertOrderedList(int x) {
    if (this->getHead() == nullptr) {
        this->insertAtBeginning(x);
        return;
    }
    if (this->getHead()->getData() > x) {
        DNode* new_pHead = new DNode(x, nullptr, this->getHead());
        this->getHead()->setPrevNode(new_pHead);
        this->setHead(new_pHead);
        return;
    }
    DNode* cur = this->getHead();
    for (; cur->nextNode(); cur = cur->nextNode()) {
        if (cur->nextNode()->getData() > x) {
            break;
        }
    }
    this->insertAfterElement(cur, x);
    return;
}

void DList::deleteAtBeginning() {
    // if list is empty, do nothing
    if (this->isEmpty()) return;

    DNode* old_pHead = this->getHead();

    // set new head
    this->setHead(old_pHead->nextNode());

    // if list only has 1 element
    // and we have deleted that only element
    // so now the list is empty
    if (this->getHead() == nullptr) {
        this->setTail(nullptr);
    } else {
        // set prev node of new head to nullptr
        this->getHead()->setPrevNode(nullptr);
    }
    delete old_pHead;
    return;
}

void DList::deleteAtEnding() {
    // if list is empty, do nothing
    if (this->isEmpty()) return;

    DNode* old_pTail = this->getTail();

    // set new tail
    this->setTail(old_pTail->prevNode());

    // if list only has 1 element
    // and we have deleted that only element
    // so now the list is empty
    if (this->getTail() == nullptr) {
        this->setHead(nullptr);
    } else {
        // set next node of new head to nullptr
        this->getTail()->setNextNode(nullptr);
    }

    delete old_pTail;
    return;
}

void DList::deleteANode(DNode* pNode) {
    // if pNode is nullptr, do nothing
    if (pNode == nullptr) {
        return;
    }

    if (pNode == this->getHead()) {
        this->deleteAtBeginning();
        return;
    } 

    if (pNode == this->getTail()) {
        this->deleteAtEnding();
        return;
    }

    DNode* pPrev = pNode->prevNode();
    DNode* pNext = pNode->nextNode();

    if (pPrev) {
        pPrev->setNextNode(pNext);
    }

    if (pNext) {
        pNext->setPrevNode(pPrev);
    }

    delete pNode;
    return;
}

void DList::delete1K(int k) {
    // if list is empty, do nothing
    if (this->isEmpty()) return;

    DNode* pNode = this->getHead();
    for (; pNode; pNode = pNode->nextNode()) {
        if (pNode->getData() == k) {
            this->deleteANode(pNode);
            break;
        }
    }
    return;
}

void DList::deleteKthNode(int k) {
    // handle 5 cases:
    // k < 0: noop
    // k > n: noop
    // k == 0: deleteAtBeginning
    // k == position of last element: deleteAtEnding
    // otherwise delete normally
    int n = this->countNode();
    if (k < 0 || k == n) {
        return;
    }

    if (k == 0) {
        this->deleteAtBeginning();
        return;
    }

    if (k == n - 1) {
        this->deleteAtEnding();
        return;
    }

    DNode* cur = this->getHead();
    for (int i = 0; i != k && cur; cur = cur->nextNode(), ++i);
    // if cur is not nullptr
    if (cur) {
        deleteANode(cur);
    }
    return;
}

void DList::deleteAllNode() {
    while(this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const DList& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Doubly Linked List:\n";
    out << "Head: " << list.getHead() << '\n';
    out << "Tail: " << list.getTail() << '\n';
    out << "Length: " << list.countNode() << '\n';
    for (DNode* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    return out;
}

// std::istream& operator>>(std::istream& in, DList& list) {
//     return in;
// }

void DList::inputDLL() {
    int x;
    DNode* cur = nullptr;
    DNode* new_pTail = nullptr;
    std::cout << "Input a Doubly Linked list.\n";
    do {
        std::cout << "Please input the number (-1 to stop): ";
        std::cin >> x;
        if (x != -1) {
            if (this->isEmpty()) {
                DNode* firstNode = new DNode(x);
                this->setHead(firstNode);
                this->setTail(firstNode);
                cur = this->getHead();
            } else {
                new_pTail = new DNode(x, cur, nullptr);
                cur->setNextNode(new_pTail);
                this->setTail(new_pTail);
                cur = cur->nextNode();
            }
        }
    } while (x != -1);
    return;
}

void DList::displayDLL() const {
    std::cout << *this;
    return;
}

int DList::countNode() const {
    int count = 0;
    for (DNode* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

void DLLDemo() {
    using std::cout;
    DList *list = new DList();

    list->inputDLL();
    list->displayDLL();
    // int x;
    // cout << "Please input a number x: ";
    // std::cin >> x;
    // cout << "Ordered linked list after add x: ";
    // list->insertOrderedList(10);
    // list->displayDLL();

    std::cout << "getKthElement(5): " << list->getKthElement(5) << '\n';
    std::cout << "getElementWithX(5): " << list->getElementWithX(5) << '\n';
    std::cout << "insertAtBeginning(100): ";
    list->insertAtBeginning(100);
    list->displayDLL();

    std::cout << "insertAtEnding(0): ";
    list->insertAtEnding(0);
    list->displayDLL();

    std::cout << "insertAfterK(5): ";
    list->insertAfterK(99, 5);
    list->displayDLL();

    cout << "insertAfterKthElement(98, 5): ";
    list->insertAfterKthElement(98, 5);
    list->displayDLL();

    cout << "insertAtKthElement(37, 3): ";
    list->insertAtKthElement(37, 3);
    list->displayDLL();

    // cout << "insertOrderedList(10): ";
    // list->insertOrderedList(10);
    // cout << "insertOrderedList(0): ";
    // list->insertOrderedList(0);
    // cout << "insertOrderedList(5): ";
    // list->insertOrderedList(5);
    // cout << "insertOrderedList(6): \n";
    // list->insertOrderedList(6);
    // list->displayDLL();

    cout << "DeleteAtBeginning(): ";
    list->deleteAtBeginning();
    list->displayDLL();

    cout << "Delete1K(5): ";
    list->delete1K(5);
    list->displayDLL();

    cout << "DeleteKthNode(5): ";
    list->deleteKthNode(5);
    list->displayDLL();

    cout << "DeleteAtEnding(): ";
    list->deleteAtEnding();
    list->displayDLL();

    cout << "DeleteAllNode(): ";
    list->deleteAllNode();
    list->displayDLL();

    delete list;
    return;
}


/*
bool isEmpty() const;
    DNode* getHead() const;
    DNode* getKthElement(int i) const;
    DNode* getElementWithX(int x) const;
    DNode* getTail() const;
    void insertAtBeginning(int x);
    void insertAtEnding(int x);
    void insertAfterK(int x, int k);
    void insertAtKthElement(int x, int k);
    void insertElement(DNode* pNode, int x);
    void insertOrderedNode(int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(int k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputDLL();
*/
