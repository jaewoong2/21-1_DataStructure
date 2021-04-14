//
// Created by 82109 on 2021-04-10.
//

#include "ArrayList.h"
#include <assert.h>
void ArrayList::insert(const ListElementType &elem) {
    assert(numberOfElements < maxListSize);
    listArray[numberOfElements] = elem;
    numberOfElements++;
}

bool ArrayList::first(ListElementType &elem) {
    if (numberOfElements == 0) {
        return false;
    } else {
        currentPosition = 0;
        elem = listArray[currentPosition];
        return true;
    }
}

bool ArrayList::next(ListElementType &elem) {
    assert(currentPosition >= 0);
    if(currentPosition >= numberOfElements - 1) {
        return false;
    } else {
        currentPosition++;
        elem = listArray[currentPosition];
        return true;
    }
}