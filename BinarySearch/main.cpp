#include <iostream>


/** target(key) 값이 arr 에 있으면 해당 인덱스를 반환, 없으면 -1 을 반환하는함수.  */
int BinarySearch(const int *arr, const int& len, const int& key);
// 전제 조건: arr 이 정의 되어 있어야하고, 정렬되어 있어야함.
// return 값으로 인덱스, 존재하지 않으면 -1 을 반환.


int main() {
    int *arr = new int();
    int n;
    std::cout << "how much values in arr?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        std::cout << "arr[" << i << "]: ?" << std::endl;
        std::cin >> value;
        arr[i] = value;
    }

    int target;
    std::cout << "is target in arr?" << std::endl;
    std::cin >> target;
    std::cout << BinarySearch(arr, n, target) << std::endl;

    return 0;
}

int BinarySearch(const int *arr, const int& len, const int& key) {
    int start = 0;
    int end = len - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}