//
// Created by 82109 on 2021-04-08.
//

#include "InorderList.h"
#include <assert.h>


// dummy head 생성
InorderList::InorderList() {
    head = new Node;
    assert(head);
    head->next = nullptr;
    current = 0;
}

InorderList::~InorderList() {
    while (!head) {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}

void InorderList::insert(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);

    (*addedNode).elem = elem;

    Link pred = head;

    while ((*pred).next != nullptr && (*pred).next->elem <= (*addedNode).elem) {
        pred = pred->next;
    }

    // pred 의 next 의 값이 추가 될 값보다 클 때, pred 의 값이 추가 될 값보다 작을 때,
    addedNode->next = pred->next;
    pred->next = addedNode;
}

void InorderList::remove(const ListElementType &target) {
    assert(head);
    Link pred(head), delNode;


    // for(pred = head; pred->next != nullptr && pred->next->elem < target; pred = pred-> next);
    while ((*pred).next != nullptr && (*pred).next->elem < target) {
        pred = pred->next;
    }

    if(pred && pred->next && pred->next->elem == target) {
        delNode = pred->next;
        pred->next = delNode->next;
        delete delNode;
    }
}

bool InorderList::first(ListElementType &elem) {
    if (head->next == nullptr) {
        return false;
    }
    current = head->next;
    elem = current->elem;
    return true;
}

bool InorderList::next(ListElementType &elem) {
    assert(current);
    if (current->next == nullptr) {
        return false;
    }
    current = current->next;
    elem = current->elem;
    return true;
}