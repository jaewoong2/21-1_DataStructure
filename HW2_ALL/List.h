#include <assert.h>

#ifndef LINKEDLIST__LIST_H
#define LINKEDLIST__LIST_H

typedef int ListElementType;

struct Node;
typedef Node* Link;
struct Node {
    ListElementType elem;
    Link next;
};

class List {
public:
    List(): head(nullptr), tail(nullptr), current(nullptr) { };
    ~List();
    void insert(const ListElementType &elem);
    void insertHead(const ListElementType &elem);
    bool first(ListElementType &elem);
    bool next(ListElementType &elem);

private:
    Link head;
    Link tail;
    Link current;
};

#endif //LINKEDLIST__LIST_H