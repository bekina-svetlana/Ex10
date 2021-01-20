// Copyright 2021 Bekina Svetlana
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <typename T>
class MyStack {
 public:
    explicit MyStack(const int new_size) {
        size = new_size;
        stack = new T[size];
    }
    MyStack(const MyStack& new_st) {
        size = new_st.size;
        stack = new T[size];
        top_index = 0;
        for (int i = 0; i < new_st.top_index; i++) {
            push(new_st.stack[i]);
        }
    }
    ~MyStack() {
        delete[] stack;
    }
    T get() const {
        if (!isEmpty()) {
            return stack[top_index - 1];
        }
        return 0;
    }
    T pop() {
        if (!isEmpty()) {
            top_index--;
            T top = stack[top_index];
            stack[top_index] = 0;
            return top;
        }
        std::cout << "Stack is empty\n";
        return 0;
    }
    void push(const T value) {
        if (!isFull()) {
            stack[top_index] = value;
            top_index++;
        }
        else {
            std::cout << "Stack is full\n";
        }
    }
    bool isFull() const {
        return top_index == size;
    }
    bool isEmpty() const {
        return top_index == 0;
    }

 private:
    int size = 10;
    T* stack = NULL;
    int top_index = 0;
};

#endif  // INCLUDE_MYSTACK_H_
