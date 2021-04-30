#include <iostream>
const int ARRAY_SIZE = 10;
void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

int main() {
    int size = ARRAY_SIZE;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size + 10;
    }

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int *a, int size) {
    for (int i = 1; i < size; i++) {
        insertNextItem(a, i);
    }
}

void insertNextItem(int *a, int i) {
    // int newItem(a[i])
    // 역할 => temp
    int newItem = a[i];

    // int insertPos(i)
    int insertPos = i;

    // ex. arr[1] 이 arr[0] 보다 작으면 서로 swap 한다.
    while (insertPos > 0 && newItem < a[insertPos - 1]) {
        a[insertPos] = a[insertPos - 1];
        insertPos = insertPos - 1;
    }
    a[insertPos] = newItem;
}