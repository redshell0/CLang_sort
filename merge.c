#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[10];
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= q) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int a = p ; a <= r ; a++) arr[a] = tmp[a];
}

void mergeSort (int *arr, int p, int r) {
    int q;

    if (p < r) {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p ,q ,r);
    }
}

int main(void) {
    // int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    // int n = 10;
    srand(time(NULL));

    int A[100];
    for (int i = 0 ; i < 100 ; i++) {
        A[i] = rand()%100+1;
    }

    printArray(A);
    mergeSort(A, 0, 99);
    printArray(A);

    return 0;
}