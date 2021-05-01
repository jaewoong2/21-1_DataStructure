//
// Created by 82109 on 2021-04-30.
//

#ifndef QUEUE_CIRCLEARRAY_Q__H
#define QUEUE_CIRCLEARRAY_Q__H
#include <cassert>

const int maxQueue = 200;

template <typename queueElementType>
class Queue {
public:
    Queue();
    ~Queue() { };
    void enqueue(const queueElementType &elem);
    queueElementType dequeue();
    queueElementType front() const;
    bool isEmpty() const;
    bool isFull() const;

private:
    int numberOfElement_;
    int front_;
    int last_;
    queueElementType elements[maxQueue];
};


int nextPosition(int p){
    if (p == maxQueue - 1) return 0;
    return p + 1;
}

template <typename queueElementType>
Queue<queueElementType>::Queue() {
    front_ = 0;
    last_ = 0;
    numberOfElement_ = 0;
}

template <typename queueElementType>
void Queue<queueElementType>::enqueue(const queueElementType &elem) {
    assert(!isFull());
    last_ = nextPosition(last_);
    numberOfElement_ += 1;
    elements[last_] = elem;
}

template <typename queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(!isEmpty());
    front_ = nextPosition(front_);
    numberOfElement_ -= 1;
    return elements[front_];
}

template <typename queueElementType>
queueElementType Queue<queueElementType>::front() const {
    assert(!isEmpty());
    return elements[nextPosition(front_)];
}

template <typename queueElementType>
bool Queue<queueElementType>::isEmpty() const {
    return bool(numberOfElement_ == 0);
//    return bool(front_ == last_);
}

template <typename queueElementType>
bool Queue<queueElementType>::isFull() const {
    return bool(numberOfElement_ == maxQueue);
    return bool (nextPosition(last_) == front_);
}


#endif //QUEUE_CIRCLEARRAY_Q__H
