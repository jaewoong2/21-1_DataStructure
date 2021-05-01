#include "Queue_.h"
#include <iostream>

int main() {
    int c;
    Queue<int> queue;

    std::cin >> c;
    while (c != 0) {
        queue.enqueue(c);
        std::cin >> c;
    }

    while (!queue.isEmpty()) {
        std::cout << "Queue:" << queue.dequeue() << " ";
    }
    std::cout << "\n";

    return 0;
}
