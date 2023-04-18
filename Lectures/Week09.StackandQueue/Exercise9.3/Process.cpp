#include "Process.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// returns the priority of op
// the higher the priority, the bigger the number
int priority(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '+' || op == '-') {
        return 1;
    }

    return 0;
}

void process_op(Stack& values, char op) {
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
        // 
    }
}