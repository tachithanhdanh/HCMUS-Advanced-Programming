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
    SLL FractionList;
    inputFractionSLL(FractionList);
    outputFractionSLL(FractionList);
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
    SLL StringList;
    inputStringSLL(StringList);
    outputFractionSLL(StringList);
}

void inputStringSLL(SLL& StringList) {

}

void outputStringSLL(const SLL& StringList) {

}

void outputEmptyList() {
    cout << "Empty list!\n";
}
