//
// Created by 82109 on 2021-04-07.
//

#include <assert.h>
#include "List.h"

List::~List() {
    while (head) {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}

void List::insertHead(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;

    if(head == nullptr) {
        tail = addedNode;
    }

    addedNode->next = head;
    head = addedNode;
}

void List::insert(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);

    (*addedNode).elem = elem;

    if(head == nullptr) {
        head = addedNode;
    } else {
        (*tail).next = addedNode;
    }

    tail = addedNode;
    addedNode->next = nullptr;
}

bool List::first(ListElementType &elem) {
    if (head == nullptr) {
        return false;
    }
    elem = (*head).elem;
    current = head;
    return true;
}

bool List::next(ListElementType &elem) {
    assert(current);

    if (current->next == nullptr) {
        return false;
    }
    current = current->next;
    elem = current->elem;
    return true;
}
