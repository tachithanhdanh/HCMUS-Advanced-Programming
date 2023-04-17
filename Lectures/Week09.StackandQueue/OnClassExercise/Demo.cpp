#include "Demo.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
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
    return;
}

void demoQueue() {
    std::cout << "Queue demo program.\n";
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
    return;
}

void demoDeque() {
    std::cout << "Deque demo program.\n";
    std::cout << "Init deque: ";
    Deque *deque = new Deque();
    deque->input();
    std::cout << "Deque after input.\n";
    std::cout << *deque << '\n';
    std::cout << "Popping deque element front and back one after another.\n";
    // 0 is front, 1 is back.
    int turn = 0;
    char sTurn[][10] = {"front", "back"};
    while (deque->size()) {
        std::cout << "Current front element: " << deque->front() << '\n';
        std::cout << "Current back element: " << deque->back() << '\n';
        std::cout << "Popping " << sTurn[turn] << "...\n";
        if (turn) deque->pop_back();
        else deque->pop_front();
        std::cout << "Current deque after popping " << sTurn[turn] << " element:\n";
        std::cout << *deque << '\n';
        turn = 1 - turn;
    }
    delete deque;
    return;
}