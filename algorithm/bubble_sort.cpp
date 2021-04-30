//
// Created by 82109 on 2021-03-25.
//
#include "bubble_sort.h"
#include "selction_sort.h"


// O(n^2)

void bubbleSort(int *arr, const int &len) {
    for (int i = len - 1; i > 0; i--) {
        find_max_swap(arr, i);
    }
}

void find_max_swap(int *arr, const int &end) {
    for (int i = 0; i < end; i++) {
        if (arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}
