#ifndef LINKEDLIST_QUEUE_QUEUE__H
#define LINKEDLIST_QUEUE_QUEUE__H
#include <cassert>

template <class queueElementType>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(const queueElementType &elem);
    queueElementType dequeue();
    queueElementType front() const;
    bool isEmpty() const;
private:
    struct Node {
        queueElementType data;
        Node* next;
    };
    Node* front_;
    Node* rear_;
};

template <class queueElementType>
Queue<queueElementType>::Queue(): front_(nullptr), rear_(nullptr) {};

template <class queueElementType>
Queue<queueElementType>::~Queue() {
    while (!isEmpty()) {
        assert(front_);
        Node* deleteNode = front_;

        front_ = front_->next;
        delete deleteNode;
        if(front_ == nullptr) {
            rear_ = nullptr;
        }
    }
}

template <class queueElementType>
void Queue<queueElementType>::enqueue(const queueElementType &elem) {
    Node* nextNode = new Node;
    assert(nextNode);

    nextNode->data = elem;
    nextNode->next = nullptr;
    if(front_ == nullptr) {
        front_ = nextNode;
    } else {
        rear_->next = nextNode;
    }
    rear_ = nextNode;
}

template <class queueElementType>
queueElementType Queue<queueElementType>::dequeue() {
    assert(front_);
    Node* deleteNode = front_;
    queueElementType returnElement = deleteNode->data;

    front_ = front_->next;
    delete deleteNode;
    if(front_ == nullptr) {
        rear_ = nullptr;
    }

    return returnElement;
}

template <class queueElementType>
queueElementType Queue<queueElementType>::front() const {
    assert(front_);
    return front_->data;
}

template <class queueElementType>
bool Queue<queueElementType>::isEmpty() const {
    return bool (front_ == nullptr);
}

#endif //LINKEDLIST_QUEUE_QUEUE__H