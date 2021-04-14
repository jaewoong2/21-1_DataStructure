//
// Created by 82109 on 2021-04-13.
//

#ifndef DYNAMICARRAYLINKEDLIST_LINK_H
#define DYNAMICARRAYLINKEDLIST_LINK_H

typedef int ListElementType;

class List {
    List(const int& size): numberOfElements(0), currentPosition(-1), listSize(size) { listArray = new ListElementType[size]; };
    void insert(const ListElementType &elem);
    bool first(ListElementType &elem);
    bool next(ListElementType &elem);
    int size() { return listSize; };
private:
    ListElementType *listArray;
    int numberOfElements;
    int listSize;
    int currentPosition;
};


#endif //DYNAMICARRAYLINKEDLIST_LINK_H
