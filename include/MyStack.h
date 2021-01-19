// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template<class T>
class MyStack{
 private:
    unsigned int size;
    T* value;
    int top;

 public:
    explicit MyStack(unsigned int pur) {
        value = new T[pur];
        top = -1;
        size = pur;
    }
    ~MyStack() {
        delete[] value;
    }
    MyStack(const MyStack& CoSt) {
        size = CoSt.size;
        top = CoSt.top;
        value = CoSt.value;
    }
    bool isEmpty() const {
        return(top == -1);
    }
    bool isFull() const {
        return(top == size);
    }
    T get() const {
        return value[top];
    }
    T pop() {
        return value[--top];
    }
    void push(T elm) {
        if (!isFull()) {
            top++;
            value[top] = elm;
        }
    }
};
#endif  // INCLUDE_MYSTACK_H_
