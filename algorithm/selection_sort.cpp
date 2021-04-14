//
// Created by 82109 on 2021-03-24.
//
#include "selction_sort.h"

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int find_min_idx(int arr[], int start, int len) {
    int min_idx = start;

    for (int i = start + 1; i < len; i++) {
        if(arr[min_idx] > arr[i]) {
            min_idx = i;
        }
    }

    return min_idx;
}


void selectionSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min_idx = find_min_idx(arr, i, len);
        swap(arr[i], arr[min_idx]);
    };
}
