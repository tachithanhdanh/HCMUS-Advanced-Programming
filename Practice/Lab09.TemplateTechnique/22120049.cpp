#include <iostream>
#include <limits>

void demoSortArray();
void demoSortFractionArray();
void demoSortStringArray();
void demoSortList();
void demoSortFractionList();
void demoSortStringList();

class Fraction {
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
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    static int gcd(int a, int b);
};

const Fraction nullFrac(0, 0);

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

bool operator<(const Fraction& f1, const Fraction& f2) {
    return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    return (operator<(f1, f2) || operator==(f1, f2));
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    return !operator<=(f1, f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    return !operator<(f1, f2);
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

template<typename T>
class Node;

template<typename T>
using Node_ptr = Node<T>*;

template<typename T>
class Node {
private:
    T m_data;
    Node_ptr<T> m_next;

public:
    Node();
    Node(T data, Node_ptr<T> next = nullptr);
    ~Node();
    Node(const Node& node) = delete;
    Node& operator=(const Node& node) = delete;
    Node_ptr<T> nextNode() const;
    const T& getData() const;
    void setNextNode(Node_ptr<T> next);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Node<U>& node);
    // friend std::istream& operator>>(std::istream& in, Node& node);
};

template<typename T>
Node<T>::Node(): m_data{}, m_next{nullptr} {}

template<typename T>
Node<T>::Node(T data, Node_ptr<T> next): m_data(data), m_next(next) {}

template<typename T>
Node<T>::~Node() {}

template<typename T>
Node_ptr<T> Node<T>::nextNode() const {
    return this->m_next;
}

template<typename T>
const T& Node<T>::getData() const {
    return this->m_data;
}

template<typename T>
void Node<T>::setNextNode(Node_ptr<T> next) {
    this->m_next = next;
    return;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << "Current node: data = " << node.getData();
    out << ", address = " << &node;
    out << ", pNext = " << node.nextNode() << '\n';
    return out;
}

template<typename T>
using cmpFcnPtr = bool(*)(const T&, const T&);

template<typename T>
class List {
private:
    Node_ptr<T> m_head = nullptr;
    Node_ptr<T> merge(Node_ptr<T> firstNode, Node_ptr<T> secondNode, cmpFcnPtr<T> cmpFcn);
    Node_ptr<T> merge_sort(Node_ptr<T> head, cmpFcnPtr<T> cmpFcn);

public:
    // constructors and destructors
    List(Node_ptr<T> head = nullptr);
    ~List();

    // deleted methods
    List(const List& list) = delete;
    List& operator=(const List& list) = delete;
    void deepCopy(const List& source) = delete;

    // basic methods
    bool isEmpty() const;
    void setHead(Node_ptr<T> pNode);
    Node_ptr<T> getHead() const;
    Node_ptr<T> getTail() const;
    Node_ptr<T> getKthElement(int k) const;

    void input(std::istream& in, std::ostream& out, const T& nullVal);
    void insertAtBeginning(const T& data);

    void display(std::ostream& out) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const List<U>& list);

    void deleteAllNode();

    void deleteAtBeginning();

    int countNode() const;

    // functions for sorting purposes
    Node_ptr<T> findMiddle(Node_ptr<T> curHead) const;
    void sort(cmpFcnPtr<T> cmpFcn);
};


template<typename T>
List<T>::List(Node_ptr<T> head): m_head(head) {}

template<typename T>
List<T>::~List() {
    // std::cout << "Singly Linked List destructor called.\n";
    this->deleteAllNode();
}

template<typename T>
bool List<T>::isEmpty() const {
    return this->getHead() == nullptr;
}

template<typename T>
void List<T>::setHead(Node_ptr<T> pNode) {
    this->m_head = pNode;
    return;
}

template<typename T>
Node_ptr<T> List<T>::getHead() const {
    return this->m_head;
}

template<typename T>
Node_ptr<T> List<T>::getTail() const {
    if (isEmpty()) return nullptr;
    Node_ptr<T> pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

template<typename T>
void List<T>::insertAtBeginning(const T& data) {
    Node_ptr<T> new_pHead = new Node<T>(data, this->getHead());
    this->setHead(new_pHead);
    return;
}

template<typename T>
void List<T>::deleteAllNode() {
    if (countNode() == 0) return;
    while (this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

template<typename T>
void List<T>::deleteAtBeginning() {
    Node_ptr<T> old_pHead = this->getHead();
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}


template<typename T>
int List<T>::countNode() const {
    int count = 0;
    for (Node_ptr<T> pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

template<typename T>
void List<T>::display(std::ostream& out) const {
    out << *this;
    return;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List (print order from head to tail):\n";
    for (Node_ptr<T> pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    out.put('\n');
    return out;
}

template<typename T>
void List<T>::input(std::istream& in, std::ostream& out, const T& nullVal) {
    // T nullVal{};
    T val;
    Node_ptr<T> cur = nullptr;
    out << "Input a Singly Linked list.\n";
    do {
        out << "Please input current element: ";
        in >> val;
        if (val != nullVal) {
            if (this->isEmpty()) {
                this->setHead(new Node(val));
                cur = this->getHead();
            } else {
                cur->setNextNode(new Node(val));
                cur = cur->nextNode();
            }
        }
    } while (val != nullVal);
    return;
}

template<typename T>
void List<T>::sort(cmpFcnPtr<T> cmpFcn) {
    this->setHead(this->merge_sort(this->getHead(), cmpFcn));
}

template<typename T>
Node_ptr<T> List<T>::merge_sort(Node_ptr<T> head, cmpFcnPtr<T> cmpFcn) {
    if (head == nullptr || head->nextNode() == nullptr) {
        return head;
    }
    Node_ptr<T> mid = this->findMiddle(head);
    Node_ptr<T> head2 = mid->nextNode();
    mid->setNextNode(nullptr);

    Node_ptr<T> finalHead = merge(merge_sort(head, cmpFcn), merge_sort(head2, cmpFcn), cmpFcn);
    return finalHead;
}

template<typename T>
Node_ptr<T> List<T>::merge(Node_ptr<T> firstNode, Node_ptr<T> secondNode, cmpFcnPtr<T> cmpFcn) {
    Node_ptr<T> res;
    Node_ptr<T> temp = new Node<T>();
    res = temp;

    while (firstNode && secondNode) {
        if (cmpFcn(firstNode->getData(), secondNode->getData())) {
            temp->setNextNode(firstNode);
            firstNode = firstNode->nextNode();
        } else {
            temp->setNextNode(secondNode);
            secondNode = secondNode->nextNode();
        }
        temp = temp->nextNode();
    }
    
    while (firstNode) {
        temp->setNextNode(firstNode);
        firstNode = firstNode->nextNode();
        temp = temp->nextNode();
    }
    
    while (secondNode) {
        temp->setNextNode(secondNode);
        secondNode = secondNode->nextNode();
        temp = temp->nextNode();
    }

    temp = res;
    res = res->nextNode();
    delete temp;

    return res;
}

template<typename T>
Node_ptr<T> List<T>::findMiddle(Node_ptr<T> curHead) const {
    Node_ptr<T> slowNode = curHead;
    Node_ptr<T> fastNode = curHead->nextNode();
    while (fastNode && fastNode->nextNode()) {
        slowNode = slowNode->nextNode();
        fastNode = fastNode->nextNode()->nextNode();
    }
    return slowNode;
}

template<typename T>
using cmpFcnPtr = bool(*)(const T&, const T&);

template<typename T>
bool less(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

template<typename T>
bool greater(const T& lhs, const T& rhs) {
    return lhs > rhs;
}

template<typename T>
void merge(T* arr, int left, int mid, int right, cmpFcnPtr<T> cmpFcn) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    T* leftArr = new T[sizeLeft]{};
    T* rightArr = new T[sizeRight]{};

    for (int index = 0; index < sizeLeft; ++index) {
        leftArr[index] = arr[index + left];
    }

    for (int index = 0; index < sizeRight; ++index) {
        rightArr[index] = arr[index + mid + 1];
    }

    int indexLeft = 0;
    int indexRight = 0;
    int indexArr = left;

    while (indexLeft < sizeLeft && indexRight < sizeRight) {
        if (cmpFcn(leftArr[indexLeft], rightArr[indexRight])) {
            arr[indexArr++] = leftArr[indexLeft++];
        } else {
            arr[indexArr++] = rightArr[indexRight++];
        }
    }

    while (indexLeft < sizeLeft) {
        arr[indexArr++] = leftArr[indexLeft++];
    }

    while (indexRight < sizeRight) {
        arr[indexArr++] = rightArr[indexRight++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

template<typename T>
void merge_sort(T* arr, int left, int right, cmpFcnPtr<T> cmpFcn) {
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, cmpFcn);
    merge_sort(arr, mid + 1, right, cmpFcn);
    merge(arr, left, mid, right, cmpFcn);
}

template<typename T>
void sort(T* arr, int n, cmpFcnPtr<T> cmpFcn) {
    merge_sort(arr, 0, n - 1, cmpFcn);
}

template<typename T>
struct Array {
private:
    int m_size = 0;
    T* m_arr = nullptr;

public:
    Array(int size = 0);
    Array(const Array& srcArr);
    Array& operator=(const Array& srcArr);
    ~Array();
    void deepCopy(const Array& srcArr);
    void read(std::istream& in, std::ostream& out);
    void print(std::ostream& out) const;

    T& operator[](int index);
    const T& operator[](int index) const;

    // hack nao
    // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Array<U>& arr); 
    friend std::istream& operator>>(std::istream& in, Array& arr) = delete;
    void sort(cmpFcnPtr<T> cmpFcn);
};

template<typename T>
Array<T>::Array(int size): m_size(size) {
    if (size <= 0) {
        m_arr = nullptr;
    } else {
        m_arr = new T[size];
    }
}

template<typename T>
Array<T>::Array(const Array<T>& srcArr) {
    deepCopy(srcArr);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& source) {
    // self-reference check
    if (this == &source) {
        return this;
    }

    deepCopy(source);
}

template<typename T>
Array<T>::~Array() {
    delete[] m_arr;
}

template<typename T>
void Array<T>::deepCopy(const Array<T>& source) {
    delete[] m_arr;

    this->m_size = source.m_size;
    
    if (source.m_arr) {
        this->m_arr = new T[this->m_size];
        for (int i = 0; i < this->m_size; ++i) {
            this->m_arr[i] = source.m_arr[i];
        }
    } else {
        this->m_arr = nullptr;
    }
}

template<typename T>
void Array<T>::read(std::istream& in, std::ostream& out) {
    out << "Input current array:\n";
    out << "Please input the size of array: ";
    in >> this->m_size;
    if (this->m_size > 0) {
        this->m_arr = new T[this->m_size];
    } else {
        this->m_size = 0;
    }
    if (this->m_size) {
        out << "Please input the elements of current array:\n";
        for (int i = 0; i < m_size; ++i) {
            out << "Input a[" << i << "] = ";
            in >> m_arr[i];
        }
    }
}

template<typename T>
void Array<T>::print(std::ostream& out) const {
    out << *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    out << "Current array:\n";
    out << "size = " << arr.m_size << '\n';
    out << "List of element in array:\n";
    for (int i = 0; i < arr.m_size; ++i) {
        out << "arr[" << i << "] = " << arr[i] << '\n';
    }
    out.put('\n');
    return out;
}

template<typename T>
void Array<T>::sort(cmpFcnPtr<T> cmpFcn) {
    ::sort(m_arr, m_size, cmpFcn);
}

template<typename T>
T& Array<T>::operator[](int index) {
    return m_arr[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    return m_arr[index];
}

int main() {
    demoSortArray();
    demoSortList();
    return 0;
}

void demoSortArray() {
    using std::cout;
    cout << "Da em chao thay,";
    cout << "em la Ta Chi Thanh Danh, ";
    cout << "MSSV 22120049.\n";
    cout << "Hom nay em xin demo ham sap xep mang cho hai kieu du lieu";
    cout << " Fraction va std::string.\n";
    cout << "Voi moi kieu du lieu, em se demo mang";
    cout << " duoc sap xep tang dan va sau do la sap xep giam dan.\n";
    demoSortFractionArray();
    demoSortStringArray();
}

void demoSortFractionArray() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep mang chua kieu du lieu Fraction.\n";
    cout << "De nhap phan so, thay vui long nhap theo dinh dang a/b (vi du: 1/2 3/5 7/9).\n";
    Array<Fraction> FractionArray;

    FractionArray.read(std::cin, std::cout);

    cout << "Mang Fraction truoc khi duoc sap xep:\n";
    FractionArray.print(std::cout);

    cout << "Mang Fraction sau khi duoc sap xep theo thu tu tang dan:\n";
    FractionArray.sort(less<Fraction>);
    FractionArray.print(std::cout);

    cout << "Mang Fraction sau khi duoc sap xep theo thu tu giam dan:\n";
    FractionArray.sort(greater<Fraction>);
    FractionArray.print(std::cout);

    cout.put('\n');
}

void demoSortStringArray() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep mang chua kieu du lieu std::string.\n";
    cout << "Mang std::string chi nhan cac ky tu lien nhau.\n";
    Array<std::string> StringArray;

    StringArray.read(std::cin, std::cout);

     cout << "Mang std::string truoc khi duoc sap xep:\n";
    StringArray.print(std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu tang dan:\n";
    StringArray.sort(less<std::string>);
    StringArray.print(std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu giam dan:\n";
    StringArray.sort(greater<std::string>);
    StringArray.print(std::cout);

    cout.put('\n');
}

void demoSortList() {
    using std::cout;
    cout << "Em xin demo ham sap xep danh sach lien ket don";
    cout << " cho hai kieu du lieu Fraction va std::string.\n";
    cout << "Voi moi kieu du lieu, em se demo danh sach lien ket";
    cout << " duoc sap xep tang dan va sau do la sap xep giam dan.\n";\
    demoSortFractionList();
    demoSortStringList();
}

void demoSortFractionList() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep danh sach lien ket don";
    cout << " chua kieu du lieu Fraction.\n";
    cout << "De nhap phan so, thay vui long nhap theo dinh dang a/b (vi du: 1/2 3/5 7/9).\n";
    cout << "De dung viec nhap phan so, thay vui long nhap 0/0.\n";
    List<Fraction> FractionList;
    FractionList.input(std::cin, std::cout, nullFrac);

    cout << "Danh sach Fraction truoc khi duoc sap xep:\n";
    FractionList.display(std::cout);

    cout << "Danh sach Fraction sau khi duoc sap xep theo thu tu tang dan:\n";
    FractionList.sort(less<Fraction>);
    FractionList.display(std::cout);

    cout << "Danh sach Fraction sau khi duoc sap xep theo thu tu giam dan:\n";
    FractionList.sort(greater<Fraction>);
    FractionList.display(std::cout);
}

void demoSortStringList() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep danh sach lien ket don";
    cout << " chua kieu du lieu std::string.\n";
    cout << "De nhap chuoi, thay vui long nhap chuoi";
    cout << " khong co dau cach, ket thuc boi dau xuong dong.\n";
    cout << "De dung viec nhap chuoi, thay vui long nhap STOP.\n";
    List<std::string> StringList;
    StringList.input(std::cin, std::cout, "STOP");

    cout << "Danh sach std::string truoc khi duoc sap xep:\n";
    StringList.display(std::cout);

    cout << "Danh sach std::string sau khi duoc sap xep theo thu tu tang dan:\n";
    StringList.sort(less<std::string>);
    StringList.display(std::cout);

    cout << "Danh sach std::string sau khi duoc sap xep theo thu tu giam dan:\n";
    StringList.sort(greater<std::string>);
    StringList.display(std::cout);
}
