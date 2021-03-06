#include <iostream>
#include <string>

#include "pharmacy.h"
#include "selection_sort.h"
#include "binary_search.h"
#include "quick_sort.h"


std::string PHARMACIES_NAME[10] = {"Dragon", "Candy", "Intern", "Egg", "Banana", "Fire", "Gorilla", "Apple", "Joker", "Hello"};
int main() {
    Pharmacy *pharmacies = new Pharmacy[10];

    for (int i = 0; i < 10; i++) {
        pharmacies[i].name = PHARMACIES_NAME[i];
        pharmacies[i].numberOfMask = (10 - i) + ((i * i * 3131124 % 9) + 1);
    }
    
    std::cout << "\n";
    std::cout << "Create 10 of Pharmacies and Their name is: " << "\n";
    std::cout << "[" << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << pharmacies[i].name << " ";
    }
    std::cout << "]" << "\n";
    std::cout << "\n";


    std::cout << "After 'Selection-Sort' 10 of Pharmacies and Their name is: " << "\n";
    selectionSort(pharmacies, 10);
    std::cout << "[" << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << pharmacies[i].name << " ";
    }
    std::cout << "]" << "\n";
    std::cout << "\n";

    std::cout << "`With BinarySearch` Find Pharmacy - Banana, its position is (-1 means not here): ";
    std::cout << binary_search(pharmacies, 0, 10, "Banana") << "\n";

    std::cout << "`With BinarySearch` Find Pharmacy - Noname, its position is (-1 means not here): ";
    std::cout << binary_search(pharmacies, 0, 10, "NoName") << "\n";
    std::cout << "\n";


    std::cout << "Before `Quick-Sort` 10 of Pharmacies and Their number of masks: " << "\n";

    std::cout << "[" << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << pharmacies[i].numberOfMask << " ";
    }
    std::cout << "]" << "\n";

    int trial_masks = 0;
    quickSort(pharmacies, 0, 10, trial_masks);
    std::cout << "After `Quick-Sort` 10 of Pharmacies and Their number of masks: " << "\n";

    std::cout << "[" << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << pharmacies[i].numberOfMask << " ";
    }
    std::cout << "]" << "\n";

    std::cout << "\n";

    for (int i = 0; i < 10; i++) {
        pharmacies[i].name = PHARMACIES_NAME[i];
    }

    int trial_name = 0;
    quickSortByName(pharmacies, 0, 10, trial_name);
    std::cout << "After `Quick-Sort` 10 of Pharmacies and Their name is: " << "\n";
    std::cout << "[" << " ";
    for (int i = 0; i < 10; i++) {
        std::cout << pharmacies[i].name << " ";
    }
    std::cout << "]" << "\n";
    std::cout << "\n";


    std::cout << "the count of trial sort by `Number of Mask` with `Quicksort` is: " <<  trial_masks <<"\n";
    std::cout << "the count of trial sort by `Name` with `Quicksort` is: " << trial_name << "\n";
    std::cout << "\n";

    std::cout << "???????????? ????????? ?????? ?????? ????????? ??????, ????????? ???????????? ???????????? ?????? ????????? ??? ?????????." << "\n";
    std::cout << "????????? ???????????? ???????????? ???????????? ????????? ???????????? ????????? ????????? ?????? ??? ?????? ?????? ?????? ?????????, ????????? ????????? ??? ???" << "\n";
    std::cout << "?????? ?????? ?????? ????????? ?????? ??? ??????." << "\n";
    return 0;
}
