#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include "SinglyLinkedList.hpp"
#include <string>
using std::string;

void greeting(const string& dataType);
void outputGreeting(const string& dataType);
void demoFractionSLL();
void inputFractionSLL(SLL& FractionList);
void outputFractionSLL(const SLL& FractionList);
void demoStringSLL();
void inputStringSLL(SLL& StringList);
void outputStringSLL(const SLL& StringList);
void outputEmptyList();

#endif