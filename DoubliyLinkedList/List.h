//
// Created by 82109 on 2021-04-13.
//
#include <assert.h>

#ifndef DOUBLIYLINKEDLIST_LIST_H
#define DOUBLIYLINKEDLIST_LIST_H

typedef int ListElementType;

struct Node;
typedef Node* Link;
struct Node {
    ListElementType elem;
    Link next;
    Link prev;
};

class List {
public:
    List(): head(nullptr), current(nullptr), tail(nullptr) {};
    ~List();
    void insert(const ListElementType &elem);
    bool first(ListElementType &elem);
    bool last(ListElementType &elem);
    bool next(ListElementType &elem);
    bool previous(ListElementType &elem);
private:
    Link head;
    Link current;
    Link tail;
};



#endif //DOUBLIYLINKEDLIST_LIST_H
