#include <iostream>
#include "List.h"
//#include "InorderList.h"


//typedef InorderList List;

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

//    InOrderList 할 때 주석 풀기
//    std::cout << "Here are the item for eliminate. \n";
//    ListElementType target;
//    std::cin >> target;
//    I.remove(target);
//
//    std::cout << "Here are the items in the list. \n";
//
//    ListElementType elems;
//
//    bool notEmptys = I.first(elems);
//
//    while (notEmptys) {
//        std::cout << elems << "\n";
//        notEmptys = I.next(elems);
//    }

    return 0;
}
