#include "SinglyLinkedList.hpp"

SLL::SLL() : m_head(nullptr) {}

SLL::~SLL() {
    std::cout << "Singly Linked List destructor called\n";
    this->deleteAllNode();
}

// SLL::SLL(const SLL& list) {
//     this->deepCopy(list);
// }

// SLL& SLL::operator=(const SLL& list) {
//     // self-assigment check
//     if (this == &list) {
//         return *this;
//     }

//     // delete all nodes before deep copying
//     this->deleteAllNode();
//     this->deepCopy(list);

//     return *this;
// }

// void SLL::deepCopy(const SLL& list) {
//     // this->deleteAllNode();
//     this->setHead(nullptr);
//     Node* pNode = list.getHead();
//     Node* cur = nullptr;
//     for (; pNode; pNode = pNode->nextNode()) {
//         if (this->getHead() == nullptr) {
//             this->setHead(new Node(pNode->getData()));
//             cur = this->getHead();
//         } else {
//             cur->setNextNode(new Node(pNode->getData()));
//             if (cur) cur = cur->nextNode();
//         }
//     }
//     return;
// }

bool SLL::isEmpty() const {
    return this->getHead() == nullptr;
}

void SLL::setHead(Node* pNode) {
    this->m_head = pNode;
    return;
}

Node* SLL::getHead() const {
    return this->m_head;
}

Node* SLL::getKthElement(int k) const {
    Node* pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

Node* SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node* pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

void SLL::insertAtBeginning(const Fraction& frac) {
    Node* new_pHead = new Node(frac, this->getHead());
    this->setHead(new_pHead);
    return;
}

void SLL::insertAtEnding(const Fraction& frac) {
    Node* pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(frac);
        return;
    }
    Node* new_pTail = new Node(frac);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAtKthElement(const Fraction& frac, int k) {
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

void SLL::insertAfterElement(Node* pNode, const Fraction& frac) {
    // only insert if it is not nullptr
    if (pNode) {
        Node* pNext = pNode->nextNode();
        Node* new_pNode = new Node(frac, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SLL::deleteAtBeginning() {
    Node* old_pHead = this->getHead();
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

void SLL::deleteANode(const Fraction& frac) {
    Node* prev = nullptr;
    Node* cur = this->getHead();
    for (; cur; prev = cur, cur = cur->nextNode()) {
        if (cur->getData() == frac) {
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
    Node* prev = nullptr;
    Node* cur = this->getHead();

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
    std::cout << "SLL::deleteAllNode function called.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

std::ostream& operator<<(std::ostream& out, const SLL& list) {
    if (list.getHead() == nullptr) {
        out << "Empty List!\n";
        return out;
    }
    out << "Singly Linked List (print order from head to tail):\n";
    for (Node* pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
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
    Node* cur = nullptr;
    do {
        cout << "Moi thay nhap phan so (nhap 0/0 de dung): ";
        std::cin >> frac;
        if (frac != nullFrac) {
            if (this->isEmpty()) {
                this->setHead(new Node(frac));
                cur = this->getHead();
            } else {
                cur->setNextNode(new Node(frac));
                if (cur) cur = cur->nextNode();
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
    for (Node* pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}