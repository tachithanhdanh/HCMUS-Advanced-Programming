#include <iostream>
#include <limits>
#include <cmath>

struct Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction &frac);
    Fraction &operator=(const Fraction &frac);
    ~Fraction();
    void reduce();
    friend std::istream &operator>>(std::istream &in, Fraction &frac);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);
    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);
};

const Fraction nullFrac(0, 0);

struct Node {
private:
    Fraction m_data;
    Node *m_pNext;

public:
    Node();
    Node(Fraction data, Node *pNext = nullptr);
    ~Node();
    Node(const Node &node);
    Node &operator=(const Node &node);
    Node *nextNode() const;
    const Fraction &getData() const;
    void setNextNode(Node *pNext);
    friend std::ostream &operator<<(std::ostream &out, const Node &node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};

struct SLL {
private:
    Node *m_pHead = nullptr;

public:
    SLL();
    ~SLL();
    SLL(const SLL &list);
    SLL &operator=(const SLL &list);
    void deepCopy(const SLL &source);
    bool isEmpty() const;
    void setHead(Node *pNode);
    Node *getHead() const;
    Node *getKthElement(int k) const;
    Node *getTail() const;
    void insertAtBeginning(const Fraction &frac);
    void insertAtEnding(const Fraction &frac);
    void insertAtKthElement(const Fraction &frac, int k);
    void insertAfterElement(Node *pNode, const Fraction &frac);
    void deleteAtBeginning();
    void deleteAtEnding();
    void deleteANode(const Fraction &_free_locale);
    void deleteKthNode(int k);
    void deleteAllNode();
    void inputSLL();
    void displaySLL() const;
    int countNode() const;
    friend std::ostream &operator<<(std::ostream &out, const SLL &list);
    // friend std::istream& operator>>(std::istream& in, SLL& list);
};

void solve();
int gcd(int a, int b);
void exercise1(SLL *&list);
void exercise2(SLL *&list);
void exercise3(SLL *&list);
void exercise4(SLL *&list);
void exercise5(SLL *&list);
void exercise6(SLL *&list);

int main(void) {
    solve();
    return 0;
}

void solve() {
    std::cout << "Da em chao thay.\n";
    std::cout << "Day la bai lam cua Thanh Danh - MSSV 22120049.\n";

    SLL *list = new SLL();

    exercise1(list);
    exercise2(list);
    exercise3(list);
    exercise4(list);
    exercise5(list);
    exercise6(list);

    std::cout << "Do ban dau em khoi tao ";
    std::cout << "danh sach lien ket don thong qua cap phat bo nho dong ";
    std::cout << "nen em xin giai phong vung nho sau khi su dung xong.\n";
    delete list;
    return;
}

void exercise1(SLL *&list) {
    std::cout << "Yeu cau 1: Xay dung danh sach cac phan so.\n";
    list->inputSLL();
    return;
}

void exercise2(SLL *&list) {
    std::cout << "Yeu cau 2: Xuat danh sach cac phan so sau khi da xay dung.\n";
    std::cout << "Danh sach phan so sau khi da xay dung.\n";
    list->displaySLL();
    return;
}

void exercise3(SLL *&list) {
    std::cout << "Yeu cau 3: Them mot phan so vao cuoi danh sach.\n";
    Fraction frac;
    std::cout << "Moi thay nhap phan so (dinh dang a/b, vi du 1/2): ";
    std::cin >> frac;
    list->insertAtEnding(frac);
    std::cout << "Danh sach phan so sau khi da them phan so moi vao cuoi danh sach.\n";
    list->displaySLL();
    return;
}

void exercise4(SLL *&list) {
    using std::cout;
    using std::cin;
    cout << "Yeu cau 4: Chen mot phan so tai mot vi tri xac dinh trong danh sach.\n";
    cout << "Moi thay nhap phan so (dinh dang a/b, vi du 1/2): ";
    Fraction frac;
    cin >> frac;
    int k;
    cout << "Moi thay nhap vi tri can chen trong danh sach: ";
    cin >> k;
    list->insertAtKthElement(frac, k);
    cout << "Danh sach phan so sau khi da them phan so moi tai vi tri "
        << k << " trong danh sach.\n";
    list->displaySLL();
    return;
}

void exercise5(SLL *&list) {
    using std::cout;
    using std::cin;
    cout << "Yeu cau 5: Xoa mot phan so tai mot vi tri xac dinh trong danh sach.\n";
    cout << "Moi thay nhap vi tri can xoa: ";
    int k;
    cin >> k;
    list->deleteKthNode(k);
    cout << "Danh sach phan so sau khi da xoa phan so tai vi tri "
        << k << " trong danh sach.\n";
    list->displaySLL();
    return;
}

void exercise6(SLL *&list) {
    using std::cout;
    using std::cin;
    cout << "Yeu cau 6: Huy toan bo danh sach phan so.\n";
    list->deleteAllNode();
    cout << "Da huy xong toan bo danh sach phan so.\n";
    cout << "Em xin dung ham in danh sach phan so de cho thay thay danh sach hien gio la rong.\n";
    list->displaySLL();
    return;
}

int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return std::abs(a);
}

Fraction::Fraction(int num, int den) : m_numerator(num), m_denominator(den) {
    this->reduce();
}

Fraction::Fraction(const Fraction &frac) : Fraction(frac.m_numerator, frac.m_denominator) {}

Fraction &Fraction::operator=(const Fraction &frac) {
    // self-assignment check
    if (this == &frac) {
        return *this;
    }

    this->m_numerator = frac.m_numerator;
    this->m_denominator = frac.m_denominator;
    this->reduce();
    return *this;
}

Fraction::~Fraction() {}

void Fraction::reduce() {
    int _gcd = gcd(this->m_numerator, this->m_denominator);
    if (_gcd) {
        this->m_numerator /= _gcd;
        this->m_denominator /= _gcd;
    }

    if (this->m_numerator * this->m_denominator >= 0) {
        this->m_numerator = std::abs(this->m_numerator);
    } else {
        this->m_numerator = -std::abs(this->m_numerator);
    }
    this->m_denominator = std::abs(this->m_denominator);
    return;
}

std::istream &operator>>(std::istream &in, Fraction &frac) {
    in >> frac.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> frac.m_denominator;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Fraction &frac) {
    out << frac.m_numerator << '/' << frac.m_denominator;
    return out;
}

bool operator==(const Fraction &f1, const Fraction &f2) {
    return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction &f1, const Fraction &f2) {
    return !(operator==(f1, f2));
}

Node::Node() : m_data(0), m_pNext(nullptr) {}

Node::Node(Fraction data, Node *pNext) : m_data(data), m_pNext(pNext) {}

Node::~Node() {
    std::cout << "Node destructor called for node has data = " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete this->m_pNext;
    // this->m_pNext = nullptr;
}

Node::Node(const Node &node) : m_data(node.m_data), m_pNext(node.m_pNext) {}

Node &Node::operator=(const Node &node) {
    // self-assignment check
    if (this == &node) {
        return *this;
    }

    this->m_data = node.m_data;
    this->m_pNext = node.m_pNext;
    return *this;
}

Node *Node::nextNode() const {
    return this->m_pNext;
}

const Fraction &Node::getData() const {
    return this->m_data;
}

void Node::setNextNode(Node *pNode) {
    this->m_pNext = pNode;
    return;
}

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node;
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

// std::istream& operator>>(std::istream& in, Node& node) {
//     in >> node.m_data;
//     return in;
// }

SLL::SLL() : m_pHead(nullptr) {}

SLL::~SLL() {
    std::cout << "Singly Linked List destructor called\n";
    this->deleteAllNode();
}

SLL::SLL(const SLL &list) {
    this->deepCopy(list);
}

SLL &SLL::operator=(const SLL &list) {
    // self-assigment check
    if (this == &list) {
        return *this;
    }

    // delete all nodes before deep copying
    this->deleteAllNode();
    this->deepCopy(list);

    return *this;
}

void SLL::deepCopy(const SLL &list) {
    // this->deleteAllNode();
    this->setHead(nullptr);
    Node *pNode = list.getHead();
    Node *cur = nullptr;
    for (; pNode; pNode = pNode->nextNode()) {
        if (this->getHead() == nullptr) {
            this->setHead(new Node(pNode->getData()));
            cur = this->getHead();
        } else {
            cur->setNextNode(new Node(pNode->getData()));
            if (cur) cur = cur->nextNode();
        }
    }
    return;
}

bool SLL::isEmpty() const {
    return this->getHead() == nullptr;
}

void SLL::setHead(Node *pNode) {
    this->m_pHead = pNode;
    return;
}

Node *SLL::getHead() const {
    return this->m_pHead;
}

Node *SLL::getKthElement(int k) const {
    Node *pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

Node *SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node *pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SLL::insertAtBeginning(const Fraction &frac) {
    Node *new_pHead = new Node(frac, this->getHead());
    this->setHead(new_pHead);
    return;
}

void SLL::insertAtEnding(const Fraction &frac) {
    Node *pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(frac);
        return;
    }
    Node *new_pTail = new Node(frac);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAtKthElement(const Fraction &frac, int k) {
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
        this->insertAtBeginning(frac);
        return;
    }

    // tail case
    if (k == n) {
        this->insertAtEnding(frac);
        return;
    }

    // somewhere in the middle case
    this->insertAfterElement(this->getKthElement(k - 1), frac);
    return;
}

void SLL::insertAfterElement(Node *pNode, const Fraction &frac) {
    // only insert if it is not nullptr
    if (pNode) {
        Node *pNext = pNode->nextNode();
        Node *new_pNode = new Node(frac, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SLL::deleteAtBeginning() {
    Node *old_pHead = this->getHead();
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

void SLL::deleteANode(const Fraction &frac) {
    Node *prev = nullptr;
    Node *cur = this->getHead();
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur->getData() == frac) {
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
    int n = this->countNode();
    if (k < 0 || k >= n) {
        std::cout << "Invalid index to delete element in linked list!\n";
        return;
    }

    if (k == 0) {
        this->deleteAtBeginning();
        return;
    }
    Node *prev = nullptr;
    Node *cur = this->getHead();

    // find k-th node
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
    Node *pNode = this->getHead();

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
    std::cout << "SLL::deleteAllNode function called.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

std::ostream &operator<<(std::ostream &out, const SLL &list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List (print order from head to tail):\n";
    for (Node *pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    return out;
}

// std::istream& operator>>(std::istream& in, SLL& list) {
//     return in;
// }

void SLL::inputSLL() {
    using std::cout;
    cout << "Moi thay danh sach cac phan so.\n";
    cout << "Cac phan so sau khi nhap se duoc xu ly thanh phan so toi gian.\n";
    cout << "Vi du: thay nhap 100/200 thi em se toi gian lai thanh 1/2\n";
    cout << "Dinh dang nhap: a/b voi a la tu so, b la tu so.\n";
    cout << "Vi du: 1/2, 3/4, 4/5, ...\n";
    cout << "De dung viec nhap danh sach phan so, thay vui long nhap 0/0.\n";
    Fraction frac;
    Node *cur = nullptr;
    do {
        cout << "Moi thay nhap phan so (nhap 0/0 de dung): ";
        std::cin >> frac;
        if (frac != nullFrac) {
            if (this->isEmpty()) {
                this->setHead(new Node(frac));
                cur = this->getHead();
            } else {
                cur->setNextNode(new Node(frac));
                if(cur) cur = cur->nextNode();
            }
        }
    } while (frac != nullFrac);
    return;
}

void SLL::displaySLL() const {
    std::cout << *this;
    return;
}

int SLL::countNode() const {
    int count = 0;
    for (Node *pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}