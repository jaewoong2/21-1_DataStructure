#include <iostream>
#include "selction_sort.h"
#include "bubble_sort.h"
#include "binary_search_re.h"

using namespace std;

int main() {
    int arr[6] = {0, 3, 5, 1, 2, 4};
    int len = 6;

    cout << binarySearch(arr, 0, 6, 2) << "\n";

//
//    for(int i=0; i<len; i++){
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
////    selectionSort(arr, len); //선택정렬 호출
//    bubbleSort(arr, len);
//
//    for(int i=0; i<len; i++){
//        cout << arr[i] << " ";
//    }

    return 0;
}
 