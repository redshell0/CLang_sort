#include <stdio.h>

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int p, int r) {
    int n1 = arr[p];
    int n2 = arr[r];
    int n3 = arr[(p+r)/2];

    int i = p - 1;

    int middle_index = n1 > n2 ? (n1 > n3 ? (n2 > n3 ? r : (p+r)/2) : p) : (n2 > n3 ? (n1 > n3 ? p : (p+r)/2) : r);
    
    if (middle_index != r) {
        int temp = arr[r];
        arr[r] = arr[middle_index];
        arr[middle_index] = temp;
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
    int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    int n = 10;

    printArray(A);
    quickSort(A, 0, 9);
    printArray(A);

    return 0;
}