//
// Created by 82109 on 2021-04-08.
//

#ifndef LINKEDLIST__INORDERLIST_H
#define LINKEDLIST__INORDERLIST_H

typedef int ListElementType;
struct Node;
typedef Node* Link;
struct Node {
    ListElementType elem;
    Link next;
};

class InorderList {
public:
    InorderList();
    ~InorderList();
    void insert(const ListElementType &elem);
    void remove(const ListElementType &target);
    bool first(ListElementType &elem);
    bool next(ListElementType &elem);


private:
    Link head;
    Link current;
};

#endif //LINKEDLIST__INORDERLIST_H
