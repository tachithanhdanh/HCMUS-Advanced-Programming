#include "Process.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

// https://www.geeksforgeeks.org/expression-evaluation/
// https://cp-algorithms.com/string/expression_parsing.html
// https://www.geeksforgeeks.org/evaluation-of-postfix-expression/
// https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/

// returns the precedence (priority) of op
// the higher the precedence, the bigger the number
int precedence(int op) {
    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '+' || op == '-') {
        return 1;
    }

    return 0;
}

void process_op(Stack& values, int op) {
    int r = values.top(); values.pop();
    int l = values.top(); values.pop();
    switch (op) {
        case '+': values.push(l + r); break;
        case '-': values.push(l - r); break;
        case '*': values.push(l * r); break;
        case '/': values.push(l / r); break;
        default: break;
    }
    return;
}

int evaluate(char* tokens) {
    int len = static_cast<int>(std::strlen(tokens));
    Stack values;
    Stack ops;
    for (int i = 0; i < len; ++i) {
        // Current token is not a paranthesis or a digit or an operator,
        // skip it.
        if (std::isspace(tokens[i])) {
            continue;
        }

        // Current token is an opening parenthesis,
        // push it into ops stack.
        if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

        // Current token is a digit 
        else if (std::isdigit(tokens[i])) {
            int val = 0;
            while (std::isdigit(tokens[i]) && i < len) {
                val = val * 10 + (tokens[i++] - '0');
            }
            values.push(val);
            --i;
        }

        // Current token is a closing parenthesis
        // calculate the value in entire brace
        else if (tokens[i] == ')') {
            while (ops.top() != '(') {
                process_op(values, ops.top());
                ops.pop();
            }

            // pop opening brace
            ops.pop();
        }

        // Current token is an arithmetic operator (+, -, *, /)
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                process_op(values, ops.top());
                ops.pop();
            }
            ops.push(tokens[i]);
        }

    }
    while (!ops.empty()) {
        process_op(values, ops.top());
        ops.pop();
    }
    return values.top();
}

void getExpression(char *expression, int max_size) {
    std::cout << "Please input expression: ";
    std::cin.getline(expression, max_size);
    return;
}

void printResultOfExpression(char *expression) {
    std::cout << "Result of corresponding expression:\n";
    std::cout << expression << " = " << evaluate(expression) << '\n';
    return;
}