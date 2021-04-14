//
//

#include "List.h"
#include <assert.h>
void List::insert(const ListElementType &elem) {
    assert(numberOfElements < listSize);
    listArray[numberOfElements] = elem;
    numberOfElements++;

    if(numberOfElements == listSize) {
        ListElementType *newListArray = new ListElementType[2 * listSize];
        for (int i = 0; i < listSize; i++) {
            newListArray[i] = listArray[i];
        }
        delete listArray;
        listSize = 2 * listSize;
        listArray = newListArray;
    }
}

bool List::first(ListElementType &elem) {
    if (numberOfElements == 0) {
        return false;
    } else {
        currentPosition = 0;
        elem = listArray[currentPosition];
        return true;
    }
}

bool List::next(ListElementType &elem) {
    assert(currentPosition >= 0);
    if(currentPosition >= numberOfElements - 1) {
        return false;
    } else {
        currentPosition++;
        elem = listArray[currentPosition];
        return true;
    }
}