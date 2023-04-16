#include "Process.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>

void demoStack() {
    std::cout << "Stack demo program.\n";
    std::cout << "Init stack: ";
    Stack *stack = new Stack();
    stack->input();
    std::cout << "Stack after input.\n";
    std::cout << *stack << '\n';
    std::cout << "Popping stack element one by one.\n";
    while (stack->size()) {
        std::cout << "Current top element: " << stack->top() << '\n';
        std::cout << "Popping...\n";
        stack->pop();
        std::cout << "Current stack after popping top element:\n";
        std::cout << *stack << '\n';
    }
    delete stack;
}

void demoQueue() {
    std::cout << "Stack demo program.\n";
    std::cout << "Init queue: ";
    Queue *queue = new Queue();
    queue->input();
    std::cout << "Queue after input.\n";
    std::cout << *queue << '\n';
    std::cout << "Popping queue element one by one.\n";
    while (queue->size()) {
        std::cout << "Current front element: " << queue->front() << '\n';
        std::cout << "Current back element: " << queue->back() << '\n';
        std::cout << "Popping...\n";
        queue->pop();\
        std::cout << "Current queue after popping front element:\n";
        std::cout << *queue << '\n';
    }
    delete queue;
}