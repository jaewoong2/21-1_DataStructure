// hw2 자료구조 20160569 임재웅
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "List.h"

int main() {
    std::cout << "20160569 임재웅 HW2 All Classes 사용 과제 제출 \n\n";
    List singlyLinkedList;
    Stack<int> stack;
    Queue<int> queue;

    std::cout << "--------- Singly Linked List >> \n";
    std::cout << "insert the data in List \n";

    int listInputNumber;
    std::cin >> listInputNumber;

    while (listInputNumber != -1) {
        singlyLinkedList.insert(listInputNumber);
        std::cin >> listInputNumber;
    }

    std::cout << "Here are the items in the list. \n";
    int listElem;

    bool notEmpty = singlyLinkedList.first(listElem);
    while (notEmpty) {
        std::cout << listElem << " ";
        notEmpty = singlyLinkedList.next(listElem);
    }
    std::cout << "\n\n";

    std::cout << "--------- Stack >> \n";
    std::cout << "push the data in stack \n";
    int stackInputNumber;
    std::cin >> stackInputNumber;

    while (stackInputNumber != -1) {
        stack.push(stackInputNumber);
        std::cin >> stackInputNumber;
    }

    bool isEmpty = stack.isEmpty();
    std::cout << "here are the data in Stack \n";
    while (!isEmpty) {
        std::cout << stack.pop() << " ";
        isEmpty = stack.isEmpty();
    }

    std::cout << "\n\n";

    std::cout << "--------- Queue >> \n";
    std::cout << "enQueue the data in Queue \n";
    int queueInputNumber;
    std::cin >> queueInputNumber;

    while (queueInputNumber != -1) {
        queue.enqueue(queueInputNumber);
        std::cin >> queueInputNumber;
    }

    bool queueIsEmpty = queue.isEmpty();
    std::cout << "here are the data in Queue \n";
    while (!queueIsEmpty) {
        std::cout << queue.dequeue() << " ";
        queueIsEmpty = queue.isEmpty();
    }
    std::cout << "\n\n";

    return 0;
}
