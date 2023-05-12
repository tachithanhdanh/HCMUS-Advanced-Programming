#include "SinglyLinkedList.hpp"

SLL::SLL(int data_size, Node_ptr head)
    : m_data_size(data_size)
    , m_head(head) {}

SLL::~SLL() {
    std::cout << "Singly Linked List destructor called\n";
    this->deleteAllNode();
}

bool SLL::isEmpty() const {
    return this->getHead() == nullptr;
}

void SLL::setHead(Node_ptr pNode) {
    this->m_head = pNode;
    return;
}

Node_ptr SLL::getHead() const {
    return this->m_head;
}

Node_ptr SLL::getTail() const {
    if (isEmpty()) return nullptr;
    Node_ptr pNode = this->getHead();
    for (; pNode->nextNode(); pNode = pNode->nextNode());
    return pNode;
}

Node_ptr SLL::getKthElement(int k) const {
    Node_ptr pNode = this->getHead();
    for (int i = 0; pNode && i != k; pNode = pNode->nextNode(), ++i);
    return pNode;
}

void SLL::insertAtBeginning(void_ptr data) {
    Node_ptr new_pHead = new Node(data, this->getHead());
    this->setHead(new_pHead);
    return;
}

void SLL::insertAtEnding(void_ptr data) {
    Node_ptr pTail = this->getTail();
    if (pTail == nullptr) {
        this->insertAtBeginning(data);
        return;
    }
    Node_ptr new_pTail = new Node(data);
    pTail->setNextNode(new_pTail);
    return;
}

void SLL::insertAfterElement(Node_ptr pNode, void_ptr data) {
    // only insert if it is not nullptr
    if (pNode) {
        Node_ptr pNext = pNode->nextNode();
        Node_ptr new_pNode = new Node(data, pNext);
        pNode->setNextNode(new_pNode);
    }
    return;
}

void SLL::insertBeforeElement(Node_ptr pNode, void_ptr data) {
    if (pNode) {
        Node_ptr cur = getHead();
        if (pNode == getHead()) {
            insertAtBeginning(data);
        } else {
            for (; cur; cur = cur->nextNode()) {
                if (cur->nextNode() == pNode) {
                    insertAfterElement(cur, data);
                }
            }
        }
    }
}

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
        this->insertAtBeginning(data);
        return;
    }

    // tail case
    if (k == n) {
        this->insertAtEnding(data);
        return;
    }

    // somewhere in the middle case
    this->insertAfterElement(this->getKthElement(k - 1), data);
    return;
}

void SLL::deleteAtBeginning() {
    Node_ptr old_pHead = this->getHead();
    if (this->getHead()) this->setHead(this->getHead()->nextNode());
    delete old_pHead;
    return;
}

void SLL::deleteANode(void_ptr data) {
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

void SLL::deleteAtEnding() {
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

void SLL::deleteAllNode() {
    std::cout << "SLL::deleteAllNode function called.\n";
    while (this->getHead()) {
        this->deleteAtBeginning();
    }
    return;
}

// std::ostream& operator<<(std::ostream& out, const SLL& list) {
//     if (list.getHead() == nullptr) {
//         out << "Empty List!\n";
//         return out;
//     }
//     out << "Singly Linked List (print order from head to tail):\n";
//     for (Node_ptr pNode = list.getHead(); pNode; pNode = pNode->nextNode()) {
//         out << *pNode;
//     }
//     return out;
// }

// std::istream& operator>>(std::istream& in, SLL& list) {
//     return in;
// }

// void SLL::inputSLL() {
//     using std::cout;
//     cout << "Moi thay danh sach cac phan so.\n";
//     cout << "Cac phan so sau khi nhap se duoc xu ly thanh phan so toi gian.\n";
//     cout << "Vi du: thay nhap 100/200 thi em se toi gian lai thanh 1/2\n";
//     cout << "Dinh dang nhap: a/b voi a la tu so, b la tu so.\n";
//     cout << "Vi du: 1/2, 3/4, 4/5, ...\n";
//     cout << "De dung viec nhap danh sach phan so, thay vui long nhap 0/0.\n";
//     Fraction data;
//     Node_ptr cur = nullptr;
//     do {
//         cout << "Moi thay nhap phan so (nhap 0/0 de dung): ";
//         std::cin >> data;
//         if (data != nullFrac) {
//             if (this->isEmpty()) {
//                 this->setHead(new Node(data));
//                 cur = this->getHead();
//             } else {
//                 cur->setNextNode(new Node(data));
//                 if (cur) cur = cur->nextNode();
//             }
//         }
//     } while (data != nullFrac);
//     return;
// }

// void SLL::displaySLL() const {
//     std::cout << *this;
//     return;
// }

int SLL::countNode() const {
    int count = 0;
    for (Node_ptr pNode = this->getHead(); pNode; pNode = pNode->nextNode()) {
        ++count;
    }
    return count;
}