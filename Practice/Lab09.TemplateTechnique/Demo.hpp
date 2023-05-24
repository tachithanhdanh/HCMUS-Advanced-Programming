#ifndef DEMO_HPP_
#define DEMO_HPP_

#include "SinglyLinkedList.hpp"

using std::string;
using string_ptr = string*;

void demoSortArray();
void demoSortFractionArray();
void demoSortStringArray();
void demoSLL();
void demoFractionSLL();
void demoStringSLL();

template<typename T>
bool less(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

template<typename T>
bool greater(const T& lhs, const T& rhs) {
    return lhs > rhs;
}

template<typename T>
Node_ptr<T> getRandomNode(const SLL<T>& List, const string& op, const string& type) {
    int randomPos{};
    Node_ptr<T> randomNode = nullptr;
    randomPos = rand() % List.countNode();
    do {
        randomPos = rand() % List.countNode();
    } while (randomPos == 0 || randomPos + 1 == List.countNode());
    randomNode = List.getKthElement(randomPos);
    cout << "Node duoc " << op << " co dia chi la ";
    cout << randomNode;
    cout << " chua du lieu la " << type << " ";
    return randomNode;
}

template<typename T>
void printListSize(const SLL<T>& List) {
    cout << "Thao tac so 10: Dem so phan tu cua danh sach lien ket.\n";
    cout << "So phan tu cua danh sach lien ket hien tai: ";
    cout << List.countNode() << "\n";
}

template<typename T>
void demoOperation12(SLL<T>& List) {
    cout << "Thao tac so 12: Xoa phan tu tai vi tri xac dinh trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can xoa: ";
    int pos;
    std::cin >> pos;
    List.deleteKthNode(pos);
}

#endif
