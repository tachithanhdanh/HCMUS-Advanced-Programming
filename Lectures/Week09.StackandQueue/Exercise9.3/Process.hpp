#ifndef EXERCISE93_PROCESS_HPP_
#define EXERCISE94_PROCESS_HPP_
#include "Stack.hpp"

int precedence(int op);
void process_op(Stack& values, int op);
int evaluate(char* tokens);
void getExpression(char *expression, int max_size);
void printResultOfExpression(char *expression);

#endif