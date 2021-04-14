#include <iostream>
#include "StackArray.h"

int main() {
    int elem;
    StackArray<int> stack = StackArray<int>();

    std::cout << "push the data in stack \n";
    std::cin >> elem;
    while (elem != 0) {
        stack.push(elem);
        std::cout << "push the data in stack \n";
        std::cin >> elem;
    }

    bool isEmpty = stack.isEmpty();
    std::cout << "here are the data in Stack \n";
    while (!isEmpty) {
        std::cout << stack.pop() << " ";
        isEmpty = stack.isEmpty();
    }

    return 0;
}
