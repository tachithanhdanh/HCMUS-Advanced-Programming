#include "QueueDynamicArray.hpp"
#include <iostream>
#include <climits>

void init(QueueDA& queue) {
    queue.data = new int[MAX]{};
    queue.front = 0;
    queue.back = -1;
    queue.size = 0;
}

bool isEmpty(const QueueDA& queue) {
    return queue.front > queue.back;
}

bool isFull(const QueueDA& queue) {
    return queue.back == MAX - 1;
}

void push(QueueDA& queue, int x) {
    if (!isFull(queue)) {
        ++queue.back;
        queue.data[queue.back] = x;
    } else {
        std::cout << "Queue is full!\n";
    }
}

int pop(QueueDA& queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue is empty! Nothing to pop!\n";
        queue.front = 0;
        queue.back = -1;
    } else {
        int x = queue.data[queue.front];
        ++queue.front;
        return x;
    }
    return INT_MIN;
}

int peek(QueueDA& queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue is empty! Nothing to peek!\n";
        queue.front = 0;
        queue.back = -1;
    } else {
        return queue.data[queue.front];
    }
    return INT_MIN;
}