#ifndef SINGLY_LINKED_LIST_HPP_
#define SINGLY_LINKED_LIST_HPP_

#include "SNode.hpp"
#include <iostream>

template<typename T>
using cmpFcn = bool(T, T);

template<typename T>
using cmpFcn_ptr = cmpFcn<T>*;

template<typename T>
struct SLL {
private:
    Node_ptr<T> m_head = nullptr;

public:

    // constructors and destructors
    SLL(Node_ptr<T> head = nullptr);
    ~SLL();

    // deleted methods
    SLL(const SLL& list) = delete;
    SLL& operator=(const SLL& list) = delete;
    void deepCopy(const SLL& source) = delete;

    // basic methods
    bool isEmpty() const;
    void setHead(Node_ptr<T> pNode);
    Node_ptr<T> getHead() const;
    Node_ptr<T> getTail() const;
    Node_ptr<T> getKthElement(int k) const;

    // operation 1
    void inputSLL() = delete;
    void insertAtBeginning(const T& data);

    // operation 2
    void displaySLL() const;
    friend std::ostream& operator<<(std::ostream& out, const SLL<T>& list);

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
};


using std::cout;

// done
template<typename T>
SLL<T>::SLL(Node_ptr<T> head): m_head(head) {}

// done
template<typename T>
SLL<T>::~SLL() {
    std::cout << "Singly Linked List destructor called.\n";
    this->deleteAllNode();
}

// done
template<typename T>
bool SLL<T>::isEmpty() const {
    return this->getHead() == nullptr;
}

// done
template<typename T>
void SLL<T>::setHead(Node_ptr<T> pNode) {
    this->m_head = pNode;
    return;
}

// done
template<typename T>
Node_ptr<T> SLL<T>::getHead() const {
    return this->m_head;
}

// done
template<typename T>
Node_ptr<T> SLL<T>::getTail() const {
    if (isEmpty()) return nullptr;
    Node_ptr<T> pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

// done
template<typename T>
Node_ptr<T> SLL<T>::getKthElement(int k) const {
    Node_ptr<T> pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

// operation 1: done
template<typename T>
void SLL<T>::insertAtBeginning(const T& data) {
    cout << "Thao tac 0: them phan tu vao dau danh sach.\n";
    Node_ptr<T> new_pHead = new Node<T>(data, this->getHead());
    this->setHead(new_pHead);
    return;
}

// operation 3: done
template<typename T>
void SLL<T>::deleteAllNode() {
    if (countNode() == 0) return;
    std::cout << "Thao tac 3: Thao tac huy toan bo danh sach lien ket don.\n";
    std::cout << "SLL<T>::deleteAllNode function called.\n";
    cout << "Ban dau danh sach lien ket co " << countNode() << " phan tu.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
        cout << "Danh sach lien ket con " << countNode() << " phan tu.\n";
    }
    return;
}

// operation 4: done
template<typename T>
void SLL<T>::insertAtEnding(const T& data) {
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
void SLL<T>::insertAfter(Node_ptr<T> pNode, const T& data, bool flag) {
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
void SLL<T>::insertBefore(Node_ptr<T> pNode, const T& data) {
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
void SLL<T>::deleteAtBeginning() {
    cout << "Thao tac 7: Xoa phan tu dau danh sach lien ket.\n";
    Node_ptr<T> old_pHead = this->getHead();
    cout << "Phan tu bi xoa co dia chi " << old_pHead << "\n";
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

// operation 8: done
template<typename T>
void SLL<T>::deleteAtEnding() {
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
void SLL<T>::deleteNodeWithData(const T& data) {
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
void SLL<T>::deleteANode(Node_ptr<T> pNode) {
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
int SLL<T>::countNode() const {
    int count = 0;
    for (Node_ptr<T> pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}

// operation 11: done
template<typename T>
void SLL<T>::insertBeforeKthElement(const T& data, int k) {
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
void SLL<T>::deleteKthNode(int k) {
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
void SLL<T>::displaySLL() const {
    std::cout << *this;
    return;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const SLL<T>& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List (print order from head to tail):\n";
    for (Node_ptr<T> pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
        out << *pNode;
    }
    return out;
}

#endif