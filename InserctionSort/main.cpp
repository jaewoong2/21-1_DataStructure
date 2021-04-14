#include <iostream>
const int ARRAY_SIZE = 10;
void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

int main() {
    int size = ARRAY_SIZE;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = rand() % size + 10;

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void insertionSort(int *a, int size) {
    int i;
    for (i = 1; i < size; i++) {
        insertNextItem(a, i);
    }
}

void insertNextItem(int *a, int i) {
    int newItem = a[i];
    // int newItem(a[i]
    int insertPos = i;
    // int insertPos(i)

    while (insertPos && newItem < a[insertPos - 1]) {
        a[insertPos] = a[insertPos - 1];
        insertPos = insertPos - 1;
    }
    a[insertPos] = newItem;
}