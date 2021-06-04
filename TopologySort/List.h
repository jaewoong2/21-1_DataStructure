//
// Created by 82109 on 2021-06-01.
//

#ifndef TOPOLOGYSORT_LIST_H
#define TOPOLOGYSORT_LIST_H

#include <cassert>

template <class ListElementType>
class ListIter;

template <class ListElementType>
class List {
public:
    List(): head(nullptr) {}
    virtual void insert(const ListElementType &elem);
    friend class ListIter<ListElementType>;
protected:
    struct Node;
    typedef Node* Link;
    struct Node {
        ListElementType elem;
        Link next;
    };
    Link head;
};

template <class ListElementType>
class ListIter {
public:
    ListIter(const List<ListElementType> &List_, ListElementType endFlag)
            : myList(List_), myEndFlag(endFlag), iterPtr(nullptr) {}
    virtual ListElementType operator++();

protected:
    const List<ListElementType> &myList;
    typename List<ListElementType>::Link iterPtr;
    ListElementType myEndFlag;
};

template <class ListElementType>
ListElementType ListIter<ListElementType>::operator++() {
    if(iterPtr == nullptr) {
        iterPtr = myList.head;
    } else {
        iterPtr = iterPtr->next;
    }
    if(iterPtr != nullptr) return iterPtr->elem;
    return myEndFlag;
}

template <class ListElementType>
void List<ListElementType>::insert(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;
    addedNode->next = head;
    head = addedNode;
}



#endif //TOPOLOGYSORT_LIST_H
