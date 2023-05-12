#include "Process.hpp"
#include "Fraction.hpp"
#include "SinglyLinkedList.hpp"
#include <string>
#include <iostream>
using std::cout;

void greeting(const string& dataType) {
    cout << "Da em chao thay,";
    cout << " sau day em xin demo danh sach lien ket";
    cout << " dung cho kieu du lieu";
    cout << " " << dataType << "\n";
}

void demoFractionSLL() {
    greeting("Fraction");
    SLL FractionList(sizeof(Fraction));
    inputFractionSLL(FractionList);
    outputFractionSLL(FractionList);
    cout << "Vi thao tac thu 3 la \
        thao tac xoa toan bo danh sach lien ket \
        nen em xin phep demo cuoi cung.\n";
}

void inputFractionSLL(SLL& FractionList) {
    
}

void outputFractionSLL(const SLL& FractionList) {
    if (FractionList.getHead() == nullptr) {
        outputEmptyList();
        return;
    }
    cout << "Danh sach lien ket don chua kieu du lieu Fraction.";
}

void demoFractionSLL() {
    greeting("std::string");
    SLL StringList(sizeof(string));
    inputStringSLL(StringList);
    outputFractionSLL(StringList);
    cout << "Vi thao tac thu 3 la \
        thao tac xoa toan bo danh sach lien ket \
        nen em xin phep demo cuoi cung.\n";
}

void inputStringSLL(SLL& StringList) {

}

void outputStringSLL(const SLL& StringList) {

}

void outputEmptyList() {
    cout << "Empty list!\n";
}
