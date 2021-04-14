//
// Created by 82109 on 2021-04-13.
//

#include "List.h"

List::~List() {
    while (head != nullptr) {
        Link delNode = head;
        head = delNode->next;
        head->prev = nullptr;
        delete delNode;
    }
}

void List::insert(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);
    addedNode->elem = elem;
    addedNode->next = head;

    if(head != nullptr) {
        head->prev = addedNode;
    }
    if(tail == nullptr) {
        tail = addedNode;
    }
    addedNode->prev = nullptr;
    head = addedNode;
}

bool List::previous(ListElementType &elem) {
    assert(current);
    if(current->prev == nullptr) {
        return false;
    }
    current = current->prev;
    elem = current->elem;
    return true;
}


bool List::first(ListElementType &elem) {
    if (head == nullptr) {
        return false;
    }
    elem = (*head).elem;
    current = head;
    return true;
}

bool List::last(ListElementType &elem) {
    if (tail == nullptr) {
        return false;
    }
    elem = tail->elem;
    current = tail;
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
