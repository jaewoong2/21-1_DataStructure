//
// Created by 82109 on 2021-03-28.
//

#ifndef HW1_QUICK_SORT_H
#define HW1_QUICK_SORT_H
#include "pharmacy.h"


/*
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함. 서로 바꿀 위치 left 와 right 를 받아온다.
 * PostCondition: Pharmacy 객체의 start 의 위치에 있는 값 (멤버변수들) 과 right 의 위치에 있는 값 (멤버변수들) 이 서로 바뀐다.
 * Quick Sort 시 연산 횟수를 알기 위해서 swap 실행시 마다 trial 변수의 값이 1증가 된다.
 * Returns: None
 */
void swap(Pharmacy *arr, int& left, int& right, int& trial);

/*
 * 마스크의 남은 수량이 많은 순서대로 정렬하기 위해서 pivot 의 위치를 맞추는 함수
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함.
 * PostCondition: first 의 위치에 있는 값을 pivot 으로 하여 그 위치를 그보다 큰 값들의 위치 다음으로, 그리고 작은 값들의 위치 이전으로 first 값을 바꾼다
 * 즉, 배열에서 pivot 값보다 큰 것들을 왼쪽으로, 작은 것들을 오른쪽으로 정렬하고 pivot(first) 의 위치를 정렬하여 바꾼다.
 * Quick Sort 시 연산 횟수를 알기 위해서 swap 실행시 마다 trial 변수의 값이 1증가 된다.
 * Returns: 바뀐 first 의 위치 (큰 값과 작은 값의 중간의 위치로)
 */
int partition(Pharmacy *arr, int first, int last, int& trial);


/*
 * 마스크의 남은 수량이 많은 순서대로 정렬하는 함수
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함.
 * PostCondition: partition 의 반환으로 받은 위치를 기준으로 quick sort 2개를 재귀호출한다.
 * 하나는 `처음 ~ partition 으로 받은 위치 -1` 까지 정렬
 * 나머지 하나는 `partition 으로 받은 위치 + 1 ~ 마지막` 까지 정렬
 * first ~ last 까지 Pharmacy 객체가 10개가 들어 있는 배열이 마스크 남은 수량이 많은 것을 기준으로 정렬된다.
 * Quick Sort 시 연산 횟수를 알기 위해서 함수 실행시 마다 trial 변수의 값이 1증가 된다.
 * Returns: None
 */
void quickSort(Pharmacy *arr, const int& first, const int& last, int& trial);


/*
 * 이름의 사전적 순서대로 정렬하는 함수.
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함.
 * PostCondition: partition 의 반환으로 받은 위치를 기준으로 quick sort 2개를 재귀호출한다.
 * 하나는 `처음 ~ partition 으로 받은 위치 -1` 까지 정렬
 * 나머지 하나는 `partition 으로 받은 위치 + 1 ~ 마지막` 까지 정렬
 * first ~ last 까지 Pharmacy 객체가 10개가 들어 있는 배열이 이름의 사전적으로 앞에 있는 것을 기준으로 정렬된다.
 * Quick Sort 시 연산 횟수를 알기 위해서 함수 실행시 마다 trial 변수의 값이 1증가 된다.
 * Returns: None
 */
void quickSortByName(Pharmacy *arr, const int& first, const int& last, int& trial);

/*
 *  * 이름의 사전적 순서대로 정렬하기 위해서 pivot 의 위치를 맞추는 함수.
 * Precondition: Pharmacy 객체 10개가 들어있는 배열 이 선언되어 있어야 함.
 * PostCondition: first 의 위치에 있는 값을 pivot 으로 하여 그 위치를 그보다 작은 값들의 위치 다음으로, 그리고 큰 값들의 위치 이전으로 first 값을 바꾼다
 * 즉, 배열에서 pivot 값보다 작은 것들을 왼쪽으로, 큰 것들을 오른쪽으로 정렬하고 pivot(first) 의 위치를 정렬하여 바꾼다.
 * Quick Sort 시 연산 횟수를 알기 위해서 함수 실행시 마다 trial 변수의 값이 1증가 된다.
 * Returns: 바뀐 first 의 위치 (큰 값과 작은 값의 중간의 위치로)
 */
int partitionByName(Pharmacy *arr, int first, int last, int& trial);



#endif //HW1_QUICK_SORT_H
