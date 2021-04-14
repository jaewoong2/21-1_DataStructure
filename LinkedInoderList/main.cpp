/* * 20160569 임재웅
 * 자료구조 InoderList 실습과제 제출 (2021-04-11)
 * */

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

    std::cout << "Here are the item for eliminate. \n";
    ListElementType target;
    std::cin >> target;
    I.remove(target);

    std::cout << "Here are the items in the list. \n";
    ListElementType elemTwo;

    bool notEmptyTwo = I.first(elemTwo);

    while (notEmptyTwo) {
        std::cout << elemTwo << "\n";
        notEmptyTwo = I.next(elemTwo);
    }

    return 0;
}
