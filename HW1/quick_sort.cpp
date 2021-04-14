//
// Created by 82109 on 2021-03-28.
//

#include "quick_sort.h"

void quickSort(Pharmacy *arr, const int& first, const int& last, int& trial) {
    if (first >= last) {
        return;
    }

    int split = partition(arr, first, last, trial);
    trial += 1;
    quickSort(arr, first, split, trial);
    quickSort(arr, split + 1, last, trial);
}

void swap(Pharmacy *arr, int& left, int& right, int& trial) {
    Pharmacy temp = Pharmacy(arr[left]);
    trial += 1;
    arr[left] = arr[right];
    arr[right] = temp;
};

int partition(Pharmacy *arr, int first, int last, int& trial) {
    int small = first;
    trial += 1;
    for (int i = first + 1; i < last; i++) {
        if (arr[i].numberOfMask >= arr[first].numberOfMask) {
            small++;
            swap(arr, small, i, trial);
        }
    }
    swap(arr, first, small, trial);

    return small;
}

void quickSortByName(Pharmacy *arr, const int& first, const int& last, int& trial) {
    if (first >= last) {
        return;
    }

    int split = partitionByName(arr, first, last, trial);
    trial += 1;
    quickSortByName(arr, first, split, trial);
    quickSortByName(arr, split + 1, last, trial);
}


int partitionByName(Pharmacy *arr, int first, int last, int& trial) {
    int small = first;
    trial += 1;
    for (int i = first + 1; i < last; i++) {
        if (arr[first].name.compare(arr[i].name) > 0) {
            small++;
            swap(arr, small, i, trial);
        }
    }
    swap(arr, first, small, trial);

    return small;
};