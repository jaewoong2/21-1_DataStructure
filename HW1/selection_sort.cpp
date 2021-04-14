//
// Created by 82109 on 2021-03-28.
//

#include "selection_sort.h"
#include "pharmacy.h"
#include <string>
using std::string;

void selectionSort(Pharmacy arr[], const int& len) {
    for (int i = 0; i < len; i++) {
        int min_idx = find_min_idx(arr, i, len);
        swap(arr[min_idx], arr[i]);
    }
}

void swap(Pharmacy& left, Pharmacy& right) {
    Pharmacy temp = Pharmacy(left);
    left = right;
    right = temp;
}

int find_min_idx(Pharmacy arr[], const int& start, const int& len) {
    int min_idx = start;
    for (int i = start + 1; i < len; i++) {
        if (arr[min_idx].name.compare(arr[i].name) > 0) {
            min_idx = i;
        }
    }
    return min_idx;
}