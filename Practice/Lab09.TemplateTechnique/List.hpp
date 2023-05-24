#ifndef LIST_HPP_
#define LIST_HPP_

#include "Node.hpp"
#include <iostream>

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

    // operation 1
    void input(std::istream& in, std::ostream& out, const T& nullVal);
    void insertAtBeginning(const T& data);

    // operation 2
    void display(std::ostream& out) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const List<U>& list);

    // operation 3
    void deleteAllNode();

    // operation 4
    void insertAtEnding(const T& data);
    
    // operation 5
    void insertAfter(Node_ptr<T> pNode, const T& data, bool flag = true);

    // operation 6
    void insertBefore(Node_ptr<T> pNode, const T& data);

    // operation 7
    void deleteAtBeginning();

    // operation 8
    void deleteAtEnding();

    // operation 9
    void deleteNodeWithData(const T& data);
    void deleteANode(Node_ptr<T> pNode);

    // operation 10
    int countNode() const;

    // operation 11
    void insertBeforeKthElement(const T& data, int k);

    // operation 12
    void deleteKthNode(int k);

    // functions for sorting purposes
    Node_ptr<T> findMiddle(Node_ptr<T> curHead) const;
    void sort(cmpFcnPtr<T> cmpFcn);
};


using std::cout;

// done
template<typename T>
List<T>::List(Node_ptr<T> head): m_head(head) {}

// done
template<typename T>
List<T>::~List() {
    // std::cout << "Singly Linked List destructor called.\n";
    this->deleteAllNode();
}

// done
template<typename T>
bool List<T>::isEmpty() const {
    return this->getHead() == nullptr;
}

// done
template<typename T>
void List<T>::setHead(Node_ptr<T> pNode) {
    this->m_head = pNode;
    return;
}

// done
template<typename T>
Node_ptr<T> List<T>::getHead() const {
    return this->m_head;
}

// done
template<typename T>
Node_ptr<T> List<T>::getTail() const {
    if (isEmpty()) return nullptr;
    Node_ptr<T> pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

// done
template<typename T>
Node_ptr<T> List<T>::getKthElement(int k) const {
    Node_ptr<T> pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

// operation 1: done
template<typename T>
void List<T>::insertAtBeginning(const T& data) {
    cout << "Thao tac 0: them phan tu vao dau danh sach.\n";
    Node_ptr<T> new_pHead = new Node<T>(data, this->getHead());
    this->setHead(new_pHead);
    return;
}

// operation 3: done
template<typename T>
void List<T>::deleteAllNode() {
    if (countNode() == 0) return;
    // std::cout << "Thao tac 3: Thao tac huy toan bo danh sach lien ket don.\n";
    // std::cout << "List<T>::deleteAllNode function called.\n";
    // cout << "Ban dau danh sach lien ket co " << countNode() << " phan tu.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
        // cout << "Danh sach lien ket con " << countNode() << " phan tu.\n";
    }
    return;
}

// operation 4: done
template<typename T>
void List<T>::insertAtEnding(const T& data) {
    cout << "Thao tac 4: them phan tu vao cuoi danh sach.\n";
    Node_ptr<T> pTail = this->getTail();
    if (pTail == nullptr) {
        cout << "Danh sach lien ket hien tai dang rong nen";
        cout << " thao tac 4 se goi thao tac 0 den them phan tu moi";
        cout << " vao dau danh sach.\n";
        this->insertAtBeginning(data);
        return;
    }
    Node_ptr<T> new_pTail = new Node<T>(data);
    pTail->setNextNode(new_pTail);
    return;
}

// operation 5: done
template<typename T>
void List<T>::insertAfter(Node_ptr<T> pNode, const T& data, bool flag) {
    if (flag) {
        cout << "Thao tac 5: them phan tu vao sau mot phan tu nao do trong danh sach.\n";
    }
    // only insert if it is not nullptr
    if (pNode) {
        Node_ptr<T> pNext = pNode->nextNode();
        Node_ptr<T> new_pNode = new Node<T>(data, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

// operation 6: done
template<typename T>
void List<T>::insertBefore(Node_ptr<T> pNode, const T& data) {
    cout << "Thao tac 6: Them phan tu vao truoc phan tu nao do trong danh sach.\n";
    if (pNode) {
        Node_ptr<T> cur = getHead();
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
template<typename T>
void List<T>::deleteAtBeginning() {
    // cout << "Thao tac 7: Xoa phan tu dau danh sach lien ket.\n";
    Node_ptr<T> old_pHead = this->getHead();
    // cout << "Phan tu bi xoa co dia chi " << old_pHead << "\n";
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

// operation 8: done
template<typename T>
void List<T>::deleteAtEnding() {
    cout << "Thao tac 8: Xoa phan tu cuoi danh sach lien ket.\n";
    Node_ptr<T> pNode = this->getHead();

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
template<typename T>
void List<T>::deleteNodeWithData(const T& data) {
    Node_ptr<T> prev = nullptr;
    Node_ptr<T> cur = this->getHead();
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

template<typename T>
void List<T>::deleteANode(Node_ptr<T> pNode) {
    cout << "Thao tac 9: Xoa phan tu giua trong danh sach lien ket.\n";
    Node_ptr<T> prev = nullptr;
    Node_ptr<T> cur = this->getHead();
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
template<typename T>
int List<T>::countNode() const {
    int count = 0;
    for (Node_ptr<T> pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

// operation 11: done
template<typename T>
void List<T>::insertBeforeKthElement(const T& data, int k) {
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
template<typename T>
void List<T>::deleteKthNode(int k) {
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
    Node_ptr<T> prev = nullptr;
    Node_ptr<T> cur = this->getHead();

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
    Node_ptr<T> cur;
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


#endif