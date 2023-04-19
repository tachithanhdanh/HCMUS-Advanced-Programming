#ifndef TEMPLATE_STACK_HPP_
#define TEMPLATE_STACK_HPP_

#include <cstddef>

// reference:
// https://github.com/jalsol/cs162-visualgo/blob/master/src/core/base_list.hpp
// https://github.com/jalsol/cs162-visualgo/blob/master/src/core/stack.hpp
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
// https://stackoverflow.com/questions/3749099/why-should-the-implementation-and-the-declaration-of-a-template-class-be-in-the

template<typename T>
class Stack {
private:
    struct Node;
    using Node_ptr = Node*;

    struct Node {
        T data{};
        Node_ptr next{};
    };
    
    Node_ptr m_head{nullptr};
    std::size_t m_size{};

public:
    Stack() = default;
    ~Stack();
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& elem);
    void pop();

    T& top() const;
    bool empty() const;
    std::size_t size() const;

};

template<typename T>
Stack<T>::~Stack() {
    while(!empty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T& elem) {
    Node_ptr new_head = new Node{elem, m_head};
    m_head = new_head;
    ++m_size;
    return;
}

template<typename T>
void Stack<T>::pop() {
    if (empty()) return;
    Node_ptr old_head = m_head;
    m_head = old_head->next;
    delete old_head;
    --m_size;
    return;
}

template<typename T>
T& Stack<T>::top() const {
    //if (empty()) return static_cast<T>(-1);
    return m_head->data;
}

template<typename T>
bool Stack<T>::empty() const {
    return m_size == 0;
}

template<typename T>
std::size_t Stack<T>::size() const {
    return m_size;
}

#endif