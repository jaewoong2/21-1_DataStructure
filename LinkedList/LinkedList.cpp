//
// Created by 82109 on 2021-04-02.
//
#include <iostream>
#include "LinkedList.h"

inline void error(const char* message) {
    puts(message);
    exit(EXIT_FAILURE);
}
int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

void Node::setData(const int data_) {
    data = data_;
}

void Node::setNext(Node *node) {
    next = node;
}

List::~List() {
    while (!empty()) popFront();
}

bool List::empty() const {
    return dataSize == 0;
}

int List::size() const {
    return dataSize;
}

int List::front() const {
    if(empty()) {
        error("List is Empty");
    }
    return (*headNode).getData();
}

void List::pushFront(const int data) {
    Node* node = new Node(data, headNode);
    headNode = node;
    dataSize++;
}

int List::popFront() {
    int frontData = front();
    Node* node = headNode;
    headNode = (*headNode).getNext();
    delete node;
    dataSize--;

    return frontData;
};


void List::display() const {
    puts("====================================================================================================");
    if (empty()) {
        puts("List is empty!");
        puts("====================================================================================================");
        return;
    }
    printf("%-5s : %d\n", "size", size());
    printf("%-5s : %d\n", "front", front());
    printf("(HEAD) ");
    for (auto i=headNode; i!=nullptr; i=i->getNext()) {
        printf("[%d] ", i->getData());
    }
    puts("");
    puts("====================================================================================================");
}