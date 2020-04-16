#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapify(int* arr, int size, int mid){
    int parent_node = mid;
    int left_node = parent_node*2+1; 
    int right_node = parent_node*2+2;
    int largest_node = parent_node;
    int temp;
    
    
    if(left_node < size && arr[left_node] > arr[largest_node]){
        largest_node = left_node;    
    }
    
    if(right_node < size && arr[right_node] > arr[largest_node]){
        largest_node = right_node;    
    }
    
    if(parent_node != largest_node){
        temp = arr[largest_node];
        arr[largest_node] = arr[parent_node];
        arr[parent_node] = temp;
        
        heapify(arr, size, largest_node);
    }


}

void buildMaxHeap(int* arr, int size)
{ 
    for(int mid = size/2-1 ; mid>=0; mid--){
        heapify(arr, size, mid);
    }
}

void heapSort(int* arr, int size)
{
    buildMaxHeap(arr, size);
    
    int temp;
    while(size > 1){
        temp = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = temp;
        
        size--;
        heapify(arr, size, 0);
    }

}

int main(void) {
    srand(time(NULL));
    int A[10] = {1, 10, 3, 41, 23, 4, 24, 11, 0, 32};
    int n = 10;

    printArray(A);
    heapSort(A, 10);
    printArray(A);

    return 0;
}