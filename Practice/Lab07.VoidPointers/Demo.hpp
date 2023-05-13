#ifndef DEMO_HPP_
#define DEMO_HPP_

#include "SinglyLinkedList.hpp"
#include "Fraction.hpp"
#include <string>
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
// Node_ptr getRandomNode(SLL& List, int num, const string& s1, const string& s2);

#endif