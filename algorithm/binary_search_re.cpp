//
// Created by 82109 on 2021-03-26.
//

#include "binary_search_re.h"


int binarySearch(int *arr, const int& start, const int& end, const int& target) {
    int mid = (start + end) / 2;

    if (start > end) {
        return -1;
    }

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] > target) {
        return binarySearch(arr, start, mid - 1, target);
    }

    if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, end, target);
    }
}


