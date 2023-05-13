#include <iostream>
#include "QueueDynamicArray.hpp"

int main() {
    using std::cout;
    using std::cin;
    QueueDA queue;
    init(queue);
    for (int i = 0; i < 10; ++i) {
        push(queue, i);
    }
    for (int i = queue.front; i <= queue.back; ++i) {
        cout << queue.data[i] << std::endl;
    }
    while(!isEmpty(queue)) {
        pop(queue);
        for (int i = queue.front; i <= queue.back; ++i) {
            cout << queue.data[i] << std::endl;
        }
        cout << std::endl;
    }
}