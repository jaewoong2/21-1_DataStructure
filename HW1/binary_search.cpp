//
// Created by 82109 on 2021-03-28.
//
#include "binary_search.h"
#include <iostream>
int binary_search(const Pharmacy *arr, const int& start, const int& len, const string& target) {
    int first = start;
    int last = len - 1;

    while (first <= last) {
        int mid = (first + last) / 2;
        if (arr[mid].name.compare(target) == 0) {
            return mid;
        }
        if (arr[mid].name.compare(target) < 0) {
            first = mid + 1;
        }
        if (arr[mid].name.compare(target) > 0) {
            last = mid - 1;
        }
    }
    return -1;
}
