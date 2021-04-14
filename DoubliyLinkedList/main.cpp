#include <iostream>
#include "List.h"

int main() {
    List I;
    ListElementType i;
    std::cout << "Enter items to add to list, add 0 to stop: ";
    std::cin >> i;

    while (i != 0) {
        I.insert(i);
        std::cin >> i;
    }

    std::cout << "Here are the items in the list. \n";
    ListElementType elem;

    bool notEmpty = I.first(elem);
    while (notEmpty) {
        std::cout << elem << "\n";
        notEmpty = I.next(elem);
    }


    std::cout << "Here are the items in the list reverse. \n";

    ListElementType elem_;
    bool notEmpty_ = I.last(elem_);
    while (notEmpty_) {
        std::cout << elem_ << "\n";
        notEmpty_ = I.previous(elem_);
    }
};