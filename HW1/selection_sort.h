//
// Created by 82109 on 2021-03-28.
//

#ifndef HW1_SELECTION_SORT_H
#define HW1_SELECTION_SORT_H
#include "pharmacy.h"
#include <string>
using std::string;

/*
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함, 그에 길이를 매개변수로 받는다.
 * PostCondition: Pharmacy class 객체의 `name` 멤버 변수가 사전순서에 맞게(A, B, C, ...) 정렬됨 (선택정렬)
 * Returns: None
 */
void selectionSort(Pharmacy arr[], const int& len);

/*
 * Precondition: left 객체의 `name` 값이 right 의 `name` 값 보다 사전적으로 뒤에 있음
 * PostCondition: left 객체의 멤버 변수의 값과, right 객채의 멤버변수의 값이 서로 바뀐다
 * Returns: None
 */
void swap(Pharmacy& left, Pharmacy& right);

/*
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함, `start 값 부터 len 으로 받은 위치까지 탐색해야함`
 * PostCondition: start 값으로 부터 len 으로 받은 위치까지 탐색후, 이름의 사전적으로 가장 앞에 있는 값의 위치를 받아온다. // 바뀌는 건 없음
 * 그 값의 위치와 start 의 위치를 서로 swap 한다. //(swap 함수를 통해)
 * Returns: start + 1 ~ len 중에서 가장 사전적으로 앞에 있는 값의 위치를 반환
 */
int find_min_idx(Pharmacy arr[], const int& start, const int& len);

#endif //HW1_SELECTION_SORT_H
