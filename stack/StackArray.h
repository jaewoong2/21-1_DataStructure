//
// Created by 82109 on 2021-04-15.
//

#ifndef STACK_STACKARRAY_H
#define STACK_STACKARRAY_H
const int MAXSIZE = 1000;

#include <cassert>
template <class StackElementType>
class StackArray {
public:
    StackArray<StackElementType>(): topIndex(-1) {};
    void push(const StackElementType &elem);
    StackElementType pop();
    StackElementType top();
    bool isEmpty() { return topIndex == -1; };
    bool isFull() { return topIndex + 1 == MAXSIZE; };
private:
    StackElementType stackArr[MAXSIZE];
    int topIndex;
};

template <class StackElementType>
void StackArray<StackElementType>::push(const StackElementType &elem) {
    assert(!isFull());
    topIndex = topIndex + 1;
    stackArr[topIndex] = elem;
}

template <class StackElementType>
StackElementType StackArray<StackElementType>::pop() {
    assert(topIndex > -1);
    int returnIndex = topIndex;
    topIndex = topIndex - 1;
    return stackArr[returnIndex];
}

template <class StackElementType>
StackElementType StackArray<StackElementType>::top() {
    assert(topIndex > -1);
    return stackArr[topIndex];
}

#endif //STACK_STACKARRAY_H
