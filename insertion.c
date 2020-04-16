#include <stdio.h>

void insertionSort(int *arr, int n) {
    int temp;
    int i, j;

    for (i = 1 ; i < n ; i++) {
        temp = arr[i];
        for (j = i - 1 ; j >= 0 ; j--) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    int n = 10;

    printArray(A);
    insertionSort(A, n);
    printArray(A);

    return 0;
}