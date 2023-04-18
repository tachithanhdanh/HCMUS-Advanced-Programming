#ifndef EXERCISE93_PROCESS_HPP_
#define EXERCISE94_PROCESS_HPP_
#include "Stack.hpp"

bool is_op(char c);
int priority(char c);
void process_op(Stack& values, char op);
int evaluate(char* tokens);

#endif