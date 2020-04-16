#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int p, int r) {
    int pivot_index = p+rand()%(r-p+1);
    int i = p - 1;

    if (pivot_index != r) {
        int temp = arr[r];
        arr[r] = arr[pivot_index];
        arr[pivot_index] = temp;
    }

    int pivot = arr[r];

    for (int j = p ; j < r ; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;

    return (i+1);
    
}

void quickSort(int *arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p ,r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int main(void) {
    srand(time(NULL));
    int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    int n = 10;

    printArray(A);
    quickSort(A, 0, 9);
    printArray(A);

    return 0;
}