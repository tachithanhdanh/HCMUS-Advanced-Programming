#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

struct Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1);
    Fraction(const Fraction& frac);
    Fraction& operator=(const Fraction& frac);
    ~Fraction();
    void reduce();
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    static int gcd(int a, int b);
};

using Fraction_ptr = Fraction*;

struct Node;
using Node_ptr = Node*;
using void_ptr = void*;

struct Node {
private:
    void_ptr m_data;
    Node_ptr m_next;

public:
    Node(void_ptr data = nullptr, Node_ptr next = nullptr);
    ~Node();
    Node(const Node& node) = delete;
    Node& operator=(const Node& node) = delete;
    Node_ptr nextNode() const;
    const void_ptr& getData() const;
    void setNextNode(Node_ptr next);
    friend std::ostream& operator<<(std::ostream& out, const Node& node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};

using cmpFcn = bool(void_ptr, void_ptr);
using cmpFcn_ptr = cmpFcn*;

struct SLL {
private:
    int m_data_size;
    Node_ptr m_head = nullptr;

public:

    // constructors and destructors
    SLL(int data_size = 1, Node_ptr head = nullptr);
    ~SLL();

    // deleted methods
    SLL(const SLL& list) = delete;
    SLL& operator=(const SLL& list) = delete;
    void deepCopy(const SLL& source) = delete;

    // basic methods
    bool isEmpty() const;
    void setHead(Node_ptr pNode);
    Node_ptr getHead() const;
    Node_ptr getTail() const;
    Node_ptr getKthElement(int k) const;

    // operation 1
    void inputSLL() = delete;
    void insertAtBeginning(void_ptr data);

    // operation 2
    void displaySLL() const = delete;
    friend std::ostream& operator<<(std::ostream& out, const SLL& list) = delete;

    // operation 3
    void deleteAllNode();

    // operation 4
    void insertAtEnding(void_ptr data);
    
    // operation 5
    void insertAfter(Node_ptr pNode, void_ptr data, bool flag = true);

    // operation 6
    void insertBefore(Node_ptr pNode, void_ptr data);

    // operation 7
    void deleteAtBeginning();

    // operation 8
    void deleteAtEnding();

    // operation 9
    void deleteNodeWithData(void_ptr data);
    void deleteANode(Node_ptr pNode);

    // operation 10
    int countNode() const;

    // operation 11
    void insertBeforeKthElement(void_ptr data, int k);

    // operation 12
    void deleteKthNode(int k);
};

using std::string;
using string_ptr = string*;

void greeting(const string& dataType);
void outputGreeting(const string& dataType);
Node_ptr getRandomNode(const SLL& List, const string& op, const string& type);
void printListSize(const SLL& List);
void demoOperation12(SLL& List);
void demoFractionSLL();
Fraction_ptr getFraction(bool flag = true);
void inputFractionSLL(SLL& FractionList);
void outputFractionSLL(const SLL& FractionList);
void demoStringSLL();
string_ptr getString(bool flag = true);
void inputStringSLL(SLL& StringList);
void outputStringSLL(const SLL& StringList);
void outputEmptyList();
void complete(int num);
void printFractionListAfterOperation(const SLL& FractionList);
void printStringListAfterOperation(const SLL& StringList);
void ignoreLine();

const Fraction nullFrac(0, 0);

int main() {
    std::ios_base::sync_with_stdio(false);
    demoFractionSLL();
    demoStringSLL();
    return 0;
}

Fraction::Fraction(int num, int den) : m_numerator(num), m_denominator(den) {
    this->reduce();
}

Fraction::Fraction(const Fraction& frac) : Fraction(frac.m_numerator, frac.m_denominator) {}

Fraction& Fraction::operator=(const Fraction& frac) {
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

std::istream& operator>>(std::istream& in, Fraction& frac) {
    in >> frac.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> frac.m_denominator;
    frac.reduce();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.m_numerator << '/' << frac.m_denominator;
    return out;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(operator==(f1, f2));
}

// https://stackoverflow.com/questions/5373107/how-to-implement-static-class-member-functions-in-cpp-file
int Fraction::gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return std::abs(a);
}

Node::Node(void_ptr data, Node_ptr next): m_data(data), m_next(next) {}

Node::~Node() {
    std::cout << "Node destructor called for node has data address = " << this->getData();
    std::cout << " at address " << this << '\n';
    // delete m_data;
}

Node* Node::nextNode() const {
    return this->m_next;
}

const void_ptr& Node::getData() const {
    return this->m_data;
}

void Node::setNextNode(Node_ptr next) {
    this->m_next = next;
    return;
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
    out << "Current node:";
    // out << " address of data = " << node.getData();
    // out << ", address = " << &node;
    // out << ", pNext = " << node.nextNode();
    return out;
}

// std::istream& operator>>(std::istream& in, Node& node) {
//     in >> node.m_data;
//     return in;
// }

using std::cout;

// done
SLL::SLL(int data_size, Node_ptr head)
    : m_data_size(data_size)
    , m_head(head) {}

// done
SLL::~SLL() {
    std::cout << "Singly Linked List destructor called.\n";
    this->deleteAllNode();
}

// done
bool SLL::isEmpty() const {
    return this->getHead() == nullptr;
}

// done
void SLL::setHead(Node_ptr pNode) {
    this->m_head = pNode;
    return;
}

// done
Node_ptr SLL::getHead() const {
    return this->m_head;
}

// done
Node_ptr SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node_ptr pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

// done
Node_ptr SLL::getKthElement(int k) const {
    Node_ptr pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

// operation 1: done
void SLL::insertAtBeginning(void_ptr data) {
    cout << "Thao tac 0: them phan tu vao dau danh sach.\n";
    Node_ptr new_pHead = new Node(data, this->getHead());
    this->setHead(new_pHead);
    return;
}

// operation 3: done
void SLL::deleteAllNode() {
    if (countNode() == 0) return;
    std::cout << "Thao tac 3: Thao tac huy toan bo danh sach lien ket don.\n";
    std::cout << "SLL::deleteAllNode function called.\n";
    cout << "Ban dau danh sach lien ket co " << countNode() << " phan tu.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
        cout << "Danh sach lien ket con " << countNode() << " phan tu.\n";
    }
    return;
}

// operation 4: done
void SLL::insertAtEnding(void_ptr data) {
    cout << "Thao tac 4: them phan tu vao cuoi danh sach.\n";
    Node_ptr pTail = this->getTail();
    if (pTail == nullptr) {
        cout << "Danh sach lien ket hien tai dang rong nen";
        cout << " thao tac 4 se goi thao tac 0 den them phan tu moi";
        cout << " vao dau danh sach.\n";
        this->insertAtBeginning(data);
        return;
    }
    Node_ptr new_pTail = new Node(data);
    pTail->setNextNode(new_pTail);
    return;
}

// operation 5: done
void SLL::insertAfter(Node_ptr pNode, void_ptr data, bool flag) {
    if (flag) {
        cout << "Thao tac 5: them phan tu vao sau mot phan tu nao do trong danh sach.\n";
    }
    // only insert if it is not nullptr
    if (pNode) {
        Node_ptr pNext = pNode->nextNode();
        Node_ptr new_pNode = new Node(data, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

// operation 6: done
void SLL::insertBefore(Node_ptr pNode, void_ptr data) {
    cout << "Thao tac 6: Them phan tu vao truoc phan tu nao do trong danh sach.\n";
    if (pNode) {
        Node_ptr cur = getHead();
        if (pNode == getHead()) {
            insertAtBeginning(data);
        } else {
            for (; cur; cur = cur->nextNode()) {
                if (cur->nextNode() == pNode) {
                    insertAfter(cur, data, false);
                    break;
                }
            }
        }
    }
}

// operation 7: done
void SLL::deleteAtBeginning() {
    cout << "Thao tac 7: Xoa phan tu dau danh sach lien ket.\n";
    Node_ptr old_pHead = this->getHead();
    cout << "Phan tu bi xoa co dia chi " << old_pHead << "\n";
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

// operation 8: done
void SLL::deleteAtEnding() {
    cout << "Thao tac 8: Xoa phan tu cuoi danh sach lien ket.\n";
    Node_ptr pNode = this->getHead();

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


// operation 9: done
void SLL::deleteNodeWithData(void_ptr data) {
    Node_ptr prev = nullptr;
    Node_ptr cur = this->getHead();
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur->getData() == data) {
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

void SLL::deleteANode(Node_ptr pNode) {
    cout << "Thao tac 9: Xoa phan tu giua trong danh sach lien ket.\n";
    Node_ptr prev = nullptr;
    Node_ptr cur = this->getHead();
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur == pNode) {
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
}

// operation 10: done
int SLL::countNode() const {
    int count = 0;
    for (Node_ptr pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

// operation 11: done
void SLL::insertBeforeKthElement(void_ptr data, int k) {
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
        cout << "Vi tri thay vua nhap nam o dau danh sach lien ket";
        cout << " nen ta goi thao tac 0.\n";
        this->insertAtBeginning(data);
        return;
    }

    // tail case
    if (k == n) {
        cout << "Vi tri thay vua nhap nam o cuoi danh sach lien ket";
        cout << " nen ta goi thao tac 4.\n";
        this->insertAtEnding(data);
        return;
    }

    // somewhere in the middle case
    cout << "Vi tri thay vua nhap nam o giua danh sach lien ket";
    cout << " nen ta goi thao tac 6.\n";
    this->insertBefore(this->getKthElement(k), data);
    return;
}

// operation 12: done
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
    Node_ptr prev = nullptr;
    Node_ptr cur = this->getHead();

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

using std::cout;

void greeting(const string& dataType) {
    cout << "Da em chao thay,";
    cout << " sau day em xin demo danh sach lien ket";
    cout << " dung cho kieu du lieu";
    cout << " " << dataType << "\n";
    cout << "Trong qua trinh demo cac thao tac,";
    cout << " se co mot so thao tac duoc su dung lai nhieu lan";
    cout << " do dac thu cua chuong trinh.\n";
    cout << "Vi thao tac thu 3 la";
    cout << " thao tac xoa toan bo danh sach lien ket";
    cout << " nen em xin phep demo cuoi cung.\n";
}

void outputGreeting(const string& dataType) {
    cout << "Thao tac so 2: In danh sach lien ket.\n";
    cout << "Danh sach lien ket chua kieu du lieu " << dataType << ".\n";
    cout << "Danh sach lien ket duoc in theo thu tu tu head den tail.\n";
}

Node_ptr getRandomNode(const SLL& List, const string& op, const string& type) {
    int randomPos{};
    Node_ptr randomNode = nullptr;
    randomPos = rand() % List.countNode();
    do {
        randomPos = rand() %List.countNode();
    } while (randomPos == 0 || randomPos + 1 == List.countNode());
    randomNode = List.getKthElement(randomPos);
    cout << "Node duoc " << op << " co dia chi la ";
    cout << randomNode;
    cout << " chua du lieu la " << type << " ";
    return randomNode;
}

void printListSize(const SLL& List) {
    cout << "Thao tac so 10: Dem so phan tu cua danh sach lien ket.\n";
    cout << "So phan tu cua danh sach lien ket hien tai: ";
    cout << List.countNode() << "\n";
}

void demoOperation12(SLL& List) {
    cout << "Thao tac so 12: Xoa phan tu tai vi tri xac dinh trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can xoa: ";
    int pos;
    std::cin >> pos;
    List.deleteKthNode(pos);
}

void demoFractionSLL() {
    // https://stackoverflow.com/questions/9246536/warning-c4244-argument-conversion-from-time-t-to-unsigned-int-possible
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // int randomPos{};
    Node_ptr randomNode = nullptr;

    greeting("Fraction");
    SLL FractionList(sizeof(Fraction));

    // 1
    inputFractionSLL(FractionList);
    cout.put('\n');

    // 2
    outputFractionSLL(FractionList);
    cout.put('\n');

    // 4
    FractionList.insertAtEnding(getFraction());
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 5
    cout << "Bay gio em se demo thao tac so 5";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen phan so moi vao sau no.\n";
    randomNode = getRandomNode(FractionList, "insertAfter", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.insertAfter(randomNode, getFraction(false));
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 6
    cout << "Bay gio em se demo thao tac so 6";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen phan so moi vao truoc no.\n";
    getRandomNode(FractionList, "insertBefore", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.insertBefore(randomNode, getFraction(false));
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 7
    FractionList.deleteAtBeginning();
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 8
    FractionList.deleteAtEnding();
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 9
    cout << "Bay gio em se demo thao tac so 9";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de xoa.\n";
    randomNode = getRandomNode(FractionList, "deleteMiddle", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.deleteANode(randomNode);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 10
    printListSize(FractionList);
    cout.put('\n');

    // 11
    cout << "Thao tac 11: Chen phan tu vao vi tri xac dinh";
    cout << " trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can chen: ";
    int pos;
    std::cin >> pos;
    FractionList.insertBeforeKthElement(getFraction(false), pos);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 12
    demoOperation12(FractionList);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 3
    FractionList.deleteAllNode();
    cout << "Da huy xong toan bo danh sach phan so.\n";
    cout << "Em xin dung ham in danh sach phan so de cho thay thay danh sach hien gio la rong.\n";
    printFractionListAfterOperation(FractionList);
    cout.put('\n');
}

void printFractionListAfterOperation(const SLL& FractionList) {
    cout << "Danh sach sau khi da hoan thanh xong thao tac vua roi.\n";
    outputFractionSLL(FractionList);
}

Fraction_ptr getFraction(bool flag) {
    if (flag) {
        cout << "Moi thay nhap phan so de phuc vu cho thao tac tiep theo.\n";
    }
    cout << "Moi thay nhap phan so: ";
    Fraction_ptr pFrac = new Fraction(0, 0);
    std::cin >> *pFrac;
    return pFrac;
}

void inputFractionSLL(SLL& FractionList) {
    cout << "Thao tac 1: Xay dung danh sach lien ket ";
    cout << " dung kieu du lieu Fraction.\n";
    cout << "Moi thay nhap danh sach cac phan so.\n";
    cout << "Cac phan so sau khi nhap se duoc xu ly thanh phan so toi gian.\n";
    cout << "Vi du: thay nhap 100/200 thi em se toi gian lai thanh 1/2\n";
    cout << "Dinh dang nhap: a/b voi a la tu so, b la tu so.\n";
    cout << "Vi du: 1/2, 3/4, 4/5, ...\n";
    cout << "De dung viec nhap danh sach phan so, thay vui long nhap 0/0.\n";
    Fraction_ptr pFrac = nullptr;
    do {
        pFrac = getFraction(false);
        if (*pFrac != nullFrac) {
            FractionList.insertAtEnding(pFrac);
        }
    } while (*pFrac != nullFrac);
    delete pFrac;
    complete(1);
}

void outputFractionSLL(const SLL& FractionList) {
    outputGreeting("Fraction");
    if (FractionList.getHead() == nullptr) {
        outputEmptyList();
    } else {
        for (Node_ptr cur = FractionList.getHead(); cur; cur = cur->nextNode()) {
            cout << *cur;
            cout << " data = " << *reinterpret_cast<Fraction_ptr>(cur->getData());
            cout << "\n";
        }
    }
    // complete(2);
}

void demoStringSLL() {
    cout << "\n\n";
    greeting("std::string");
    SLL StringList(sizeof(string));
    Node_ptr randomNode = nullptr;

    // 1
    ignoreLine();
    inputStringSLL(StringList);
    cout.put('\n');

    // 2
    outputStringSLL(StringList);
    cout.put('\n');

    // 4
    StringList.insertAtEnding(getString());
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 5
    cout << "Bay gio em se demo thao tac so 5";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen string moi vao sau no.\n";
    randomNode = getRandomNode(StringList, "insertAfter", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.insertAfter(randomNode, getString(false));
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 6
    cout << "Bay gio em se demo thao tac so 6";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen string moi vao truoc no.\n";
    getRandomNode(StringList, "insertBefore", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.insertBefore(randomNode, getString(false));
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 7
    StringList.deleteAtBeginning();
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 8
    StringList.deleteAtEnding();
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 9
    cout << "Bay gio em se demo thao tac so 9";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de xoa.\n";
    randomNode = getRandomNode(StringList, "deleteMiddle", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.deleteANode(randomNode);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 10
    printListSize(StringList);
    cout.put('\n');

    // 11
    cout << "Thao tac 11: Chen phan tu vao vi tri xac dinh";
    cout << " trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can chen: ";
    int pos;
    std::cin >> pos;
    ignoreLine();
    StringList.insertBeforeKthElement(getString(false), pos);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 12
    demoOperation12(StringList);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 3
    StringList.deleteAllNode();
    cout << "Da huy xong toan bo danh sach phan so.\n";
    cout << "Em xin dung ham in danh sach phan so de cho thay thay danh sach hien gio la rong.\n";
    printStringListAfterOperation(StringList);
}

void printStringListAfterOperation(const SLL& StringList) {
    cout << "Danh sach sau khi da hoan thanh xong thao tac vua roi.";
    outputStringSLL(StringList);
}

string_ptr getString(bool flag) {
    if (flag) {
        cout << "Moi thay nhap chuoi de phuc vu cho thao tac tiep theo.\n";
    }
    cout << "Moi thay nhap chuoi: ";
    string_ptr pString = new string();
    std::getline(std::cin, *pString);
    return pString;
}

void inputStringSLL(SLL& StringList) {
    cout << "Thao tac 1: Xay dung danh sach lien ket ";
    cout << " dung kieu du lieu std::string.\n";
    cout << "Moi thay nhap danh sach cac chuoi ky tu.\n";
    cout << "Dinh dang nhap nhu binh thuong, ket thuc boi dau xuong dong.\n";
    cout << "Vi du: Em chao thay Thinh.\n";
    cout << "De dung viec nhap danh sach string, thay vui long nhap xau rong roi enter.\n";
    string_ptr pString = nullptr;
    do {
        pString = getString(false);
        if (!pString->empty()) {
            StringList.insertAtEnding(pString);
        }
    } while (!pString->empty());
    delete pString;
    complete(1);
}

void outputStringSLL(const SLL& StringList) {
    outputGreeting("std::string");
    if (StringList.getHead() == nullptr) {
        outputEmptyList();
    } else {
        for (Node_ptr cur = StringList.getHead(); cur; cur = cur->nextNode()) {
            cout << *cur;
            cout << ", data = " << *reinterpret_cast<string_ptr>(cur->getData());
            cout << "\n";
        }
    }
    complete(2);
}

void outputEmptyList() {
    cout << "Empty list!\n";
}

void complete(int num) {
    cout << "Da thuc hien xong thao tac " << num << ".\n";
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
