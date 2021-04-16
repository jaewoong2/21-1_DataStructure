//
// Created by 82109 on 2021-04-15.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <cassert>

template <class StackElementType>
class Stack {
public:
    Stack<StackElementType>(): head(nullptr) {};
    void push(const StackElementType &elem);
    StackElementType pop();
    StackElementType top();
    bool isEmpty() { return bool(head == nullptr); };
private:
    struct Node;
    typedef Node* Link;
    struct Node {
        Link next;
        StackElementType elem;
    };
    Link head;
};

template <class StackElementType>
void Stack<StackElementType>::push(const StackElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;
    addedNode->next = head;
    head = addedNode;
}

template <class StackElementType>
StackElementType Stack<StackElementType>::pop() {
    assert(head != nullptr);
    Link delNode = head;
    head = head->next;
    StackElementType returnElem = delNode->elem;
    delete delNode;
    return returnElem;
}

template <class StackElementType>
StackElementType Stack<StackElementType>::top() {
    assert(head != nullptr);
    return head->elem;
}

#endif //STACK_STACK_H
