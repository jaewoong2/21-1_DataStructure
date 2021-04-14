//
// Created by 82109 on 2021-04-02.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

class Node {
public:
    int getData() const;
    Node* getNext() const;
    void setData(const int data);
    void setNext(Node* node);

    Node(): data(0), next(nullptr) {};
    Node(const int data, Node* node): data(data), next(node) {};
private:
    int data;
    Node *next;
};

class List {
public:
    List(): headNode(nullptr), dataSize(0) { };
    ~List();

    bool empty() const;
    int size() const;
    int front() const;
    void pushFront(const int data);
    int popFront();


    void display() const;

private:
    Node* headNode;
    int dataSize;
};



#endif //LINKEDLIST_LINKEDLIST_H
