//
// Created by 82109 on 2021-03-28.
//

#ifndef HW1_BINARY_SEARCH_H
#define HW1_BINARY_SEARCH_H

#include "pharmacy.h"

/*
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함.
 * PostCondition: start ~ len 까지 이진탐색으로 target 의 위치를 찾는다. // 바뀌는 건 없음
 * Returns: target 의 위치를 반환한다.
 */
int binary_search(const Pharmacy *arr, const int& start, const int& len, const string& target);

#endif //HW1_BINARY_SEARCH_H
