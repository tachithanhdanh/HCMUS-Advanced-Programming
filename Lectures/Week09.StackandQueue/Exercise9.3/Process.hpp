#ifndef EXERCISE93_PROCESS_HPP_
#define EXERCISE93_PROCESS_HPP_

// #include "Stack.hpp"
#include "TemplateStack.hpp"

int precedence(char op);
void process_op(Stack<int>& values, char op);
int evaluate(char* tokens);
void getExpression(char *expression, int max_size);
void printResultOfExpression(char *expression);

#endif