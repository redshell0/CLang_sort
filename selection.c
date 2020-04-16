#include <stdio.h>

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int *arr, int n) {
    int max = 0;
    int temp;
    for (int last = n ; last > 1 ; last--) {
        for (int i = 0 ; i < last ; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        temp = arr[max];
        arr[max] = arr[last - 1];
        arr[last - 1] = temp;
        max = 0;
    }
}


int main(void) {
    int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    int n = 10;

    printArray(A);
    selectionSort(A, n);
    printArray(A);

    return 0;
}