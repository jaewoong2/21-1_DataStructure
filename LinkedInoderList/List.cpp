#include "List.h"
#include <assert.h>


// dummy head 생성
// dummy head 의 next 부터 값이 들어간다.
List::List() {
    head = new Node;
    assert(head);
    head->next = nullptr;
    current = 0;
}

// 함수가 종료 하면 실행
List::~List() {
    while (!head) {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }
}

void List::insert(const ListElementType &elem) {
    Link addedNode = new Node;
    assert(addedNode);

    (*addedNode).elem = elem;

    Link pred = head;

    // addedNode 의 값이 pred.next 의 값 보다 작을때까지 반복한다.
    while ((*pred).next != nullptr && (*pred).next->elem <= (*addedNode).elem) {
        pred = pred->next;
    }

    // pred 의 next 의 값이 추가 될 값보다 클 때, pred 의 값이 추가 될 값보다 작을 때,
    // addedNode 의 next 에는 pred.next 를 연결 해주고,
    // pred.next 에는 addedNode 를 연결 해준다.
    addedNode->next = pred->next;
    pred->next = addedNode;
}

void List::remove(const ListElementType &target) {
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

bool List::first(ListElementType &elem) {
    if (head->next == nullptr) {
        return false;
    }
    current = head->next;
    elem = current->elem;
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