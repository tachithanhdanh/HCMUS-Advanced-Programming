#include <iostream>
#include <limits>

using std::cout;
using std::cin;

struct Fraction {
private:
    int m_denominator;

public:
    int m_numerator;
    Fraction(int num = 0, int den = 1): m_numerator(num), m_denominator(den) {}
    ~Fraction();
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
};

const Fraction nullFrac(0, 0);

struct Node {
private:
    Fraction m_data;
    Node* m_pNext;

public:
    Node();
    Node(Fraction data, Node* pNext = nullptr);
    ~Node();
    Node(const Node& node);
    Node& operator=(const Node& node);
    Node* nextNode() const;
    Fraction getData() const;
    void setNextNode(Node* pNext);
    friend std::ostream& operator<<(std::ostream& out, const Node& node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};

struct SLL {
private:
    Node* m_pHead = nullptr;

public:
    SLL();
    ~SLL();
    SLL(const SLL& list);
    SLL& operator=(const SLL& list);
    void deepCopy(const SLL& source);
    bool isEmpty() const;
    void setHead(Node* pNode);
    Node* getHead() const;
    Node* getKthElement(int k) const;
    Node* getTail() const;
    void insertAtBeginning(Fraction x);
    void insertAtEnding(Fraction x);
    void insertAtKthElement(Fraction x, int k);
    void insertElement(Node* pNode, int x);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(Fraction k);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
    void displaySLL() const;
    int countNode() const;
    friend std::ostream& operator<<(std::ostream& out, const SLL& list);
    // friend std::istream& operator>>(std::istream& in, SLL& list);
};

void SLLDemo();
SLL* reversedSLL(const SLL& list);
void solve();

int main(void) {

    return 0;
}

void solve() {
}

Fraction::Fraction(int num, int den): m_numerator(num), m_denominator(den) {}

Fraction::~Fraction() {}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    in >> frac.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> frac.m_denominator;
    return in;
}

Node::Node(): m_data(0), m_pNext(nullptr) {}

Node::Node(Fraction data, Node* pNext): m_data(data), m_pNext(pNext) {}

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

Fraction Node::getData() const {
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
    this->deepCopy(list);
}

SLL& SLL::operator=(const SLL& list) {
    // self-assigment check
    if (this == &list) {
        return *this;
    }

    // delete all nodes before deep copying
    this->deleteAllNode();
    this->deepCopy(list);

    return *this;
}

void SLL::deepCopy(const SLL& list) {
    // this->deleteAllNode();
    this->setHead(nullptr);
    Node* pNode = list.getHead();
    Node* cur;
    for (; pNode; pNode = pNode->nextNode()) {
        if (this->getHead() == nullptr) {
            this->setHead(new Node(pNode->getData()));
            cur = this->getHead();
        } else {
            cur->setNextNode(new Node(pNode->getData()));
            cur = cur->nextNode();
        }
    }
    return;
}

bool SLL::isEmpty() const {
    return this->getHead() == nullptr;
}

void SLL::setHead(Node* pNode) {
    this->m_pHead = pNode;
    return;
}

Node* SLL::getHead() const {
    return this->m_pHead;
}

Node* SLL::getKthElement(int k) const {
    Node* pNode = this->getHead();
    for(int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

Node* SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node* pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SLL::insertAtBeginning(Fraction x) {
    Node* new_pHead = new Node(x, this->getHead());
    this->setHead(new_pHead);
    return;
}

void SLL::insertAtEnding(Fraction x) {
    Node* pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(x);
        return;
    } 
    Node* new_pTail = new Node(x);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAtKthElement(Fraction x, int k) {
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

void SLL::insertElement(Node* pNode, Fraction x) {
    // only insert if it is not nullptr
    if (pNode) {
        Node* pNext = pNode->nextNode();
        Node* new_pNode = new Node(x, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SLL::deleteAtBeginning() {
    Node* old_pHead = this->getHead();
    if(this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

void SLL::deleteANode(Fraction k) {
    Node* prev = nullptr;
    Node* cur = this->getHead();
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
    Node* cur = this->getHead();
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
    Node* pNode = this->getHead();

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
    while(this->getHead()) {
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
    int num, den;
    cout << "Moi thay danh sach cac phan so.\n";
    cout << "Dinh dang nhap: a/b voi a la tu so, b la tu so.\n";
    cout << "Vi du: 1/2, 3/4, 4/5, ...\n";
    cout << "De dung viec nhap danh sach phan so, thay vui long nhap 0/0.";
    Fraction x;
    Node* cur;
    do {
        cout << "Moi thay nhap phan so (nhap 0/0 de dung): ";
        std::cin >> x;
        if (x != -1) {
            if (this->isEmpty()) {
                this->setHead(new Node(x));
                cur = this->getHead();
            } else {
                cur->setNextNode(new Node(x));
                cur = cur->nextNode();
            }
        }
    } while (x != -1);
    return;
}

void SLL::displaySLL() const {
    std::cout << *this;
    return;
}

int SLL::countNode() const {
    int count = 0;
    for (Node* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

void SLLDemo() {
    using std::cout;
    SLL *list = new SLL();
    list->inputSLL();
    list->displaySLL();
    cout << "countNode(): " << list->countNode() << '\n';
    std::cout << "Reverse linked list: ";
    SLL *rList = reversedSLL(*list);
    rList->displaySLL();
    int x;
    cout << "Please input a number x: ";
    std::cin >> x;
    cout << "Ordered linked list after add x: ";
    list->displaySLL();
    // std::cout << "Head: " << list->getHead() << '\n';
    // std::cout << "getKthElement(5): " << list->getKthElement(5) << '\n';
    // std::cout << "getElementWithX(5): " << list->getElementWithX(5) << '\n';
    // std::cout << "getTail(): " << list->getTail() << '\n';
    // std::cout << "insertAtBeginning(100): ";
    // list->insertAtBeginning(100);
    // list->displaySLL();
    // std::cout << "insertAtEnding(0): ";
    // list->insertAtEnding(0);
    // list->displaySLL();
    // std::cout << "insertAfterK(5): ";
    // list->insertAfterK(99, 5);
    // list->displaySLL();
    // cout << "insertAtKthElement(5): ";
    // list->insertAtKthElement(98, 5);
    // list->displaySLL();
    // cout << "insertOrderedList(10): ";
    // list->insertOrderedList(10);
    // cout << "insertOrderedList(0): ";
    // list->insertOrderedList(0);
    // cout << "insertOrderedList(5): ";
    // list->insertOrderedList(5);
    // cout << "insertOrderedList(6): ";
    // list->insertOrderedList(6);
    // list->displaySLL();
    // cout << "DeleteAtBeginning(): ";
    // list->deleteAtBeginning();
    // list->displaySLL();
    // cout << "DeleteANode(5): ";
    // list->deleteANode(5);
    // list->displaySLL();
    // cout << "DeleteKthNode(5): ";
    // list->deleteKthNode(5);
    // list->displaySLL();
    // cout << "DeleteAllNode(): ";
    // list->deleteAllNode();
    // list->displaySLL();
    delete list;
    delete rList;
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
