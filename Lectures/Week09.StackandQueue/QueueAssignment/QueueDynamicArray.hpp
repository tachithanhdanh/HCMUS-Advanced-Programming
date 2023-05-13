#ifndef QUEUE_DYNAMIC_ARRAY_HPP_
#define QUEUE_DYNAMIC_ARRAY_HPP_

const int MAX = static_cast<int>(2E5 + 10);

struct QueueDA {
    int *data;
    int front;
    int back;
    int size;
};

void init(QueueDA& queue);
bool isEmpty(const QueueDA& queue);
bool isFull(const QueueDA& queue);
void push(QueueDA& queue, int x);
int pop(QueueDA& queue);
int peek(QueueDA& queue);

#endif