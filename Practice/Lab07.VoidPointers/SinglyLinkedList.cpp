#include "SinglyLinkedList.hpp"
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
