//
// Created by 82109 on 2021-04-10.
//

#ifndef LINKEDLIST__ARRAYLIST_H
#define LINKEDLIST__ARRAYLIST_H

typedef int ListElementType;
const ListElementType maxListSize = 100;

class ArrayList {
public:
    ArrayList(): numberOfElements(0), currentPosition(-1) { };
    void insert(const ListElementType &elem);
    bool first(ListElementType &elem);
    bool next(ListElementType &elem);

private:
    ListElementType listArray[maxListSize];
    int numberOfElements;
    int currentPosition;
};


#endif //LINKEDLIST__ARRAYLIST_H
