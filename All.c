#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// print Array
void printArray(int *arr) {
    for (int i = 0 ; i < 10 ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// # bubble sort start
void bubbleSort(int *arr, int n) {
    int temp;
    for (int i = n ; i > 2 ; i--) {
        for (int j = 0 ; j < i - 1 ; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
// # /bubble sort end

// # selection sort start
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
// # /selection sort end

// # insertion sort start
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

// # insertion sort end
void merge(int *arr, int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[100000];
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
// # /insertion sort end

// # quick sort, pivot is a last index
int partition(int *arr, int p, int r) {
    int pivot = arr[r];
    int i = p - 1;

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
// # /quick sort, pivot is a last index

// # quick sort, pivot is a middle value
int partition2(int *arr, int p, int r) {
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

void quickSort2(int *arr, int p, int r) {
    if (p < r) {
        int q = partition2(arr, p ,r);
        quickSort2(arr, p, q-1);
        quickSort2(arr, q+1, r);
    }
}
// # /quick sort, pivot is a middle value

// # quick sort, pivot is a random value
int partition3(int *arr, int p, int r) {
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

void quickSort3(int *arr, int p, int r) {
    if (p < r) {
        int q = partition3(arr, p ,r);
        quickSort3(arr, p, q-1);
        quickSort3(arr, q+1, r);
    }
}
// # /quick sort, pivot is a random value

// # heap sort start
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
// # /heap sort end

// # C Library Quick sort Compare Func
int compare (const void *first, const void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}
// # / C


int main (void) {
    srand(time(NULL));

    clock_t start, end;

    int Random1[1000];
    int Reverse1[1000];
    int test1[1000];
    int test_Reverse1[1000];

    int Random2[10000];
    int Reverse2[10000];
    int test2[10000];
    int test_Reverse2[10000];

    int Random3[100000];
    int Reverse3[100000];
    int test3[100000];
    int test_Reverse3[100000];
    
    for (int i = 0 ; i < 1000 ; i++) {
        Random1[i] = rand()&1000 + 1;
        Reverse1[i] = 1000 - i;
    }
    for (int i = 0 ; i < 10000 ; i++) {
        Random2[i] = rand()%10000 + 1;
        Reverse2[i] = 10000 - i;
    }
    for (int i = 0 ; i < 100000 ; i++) {
        Random3[i] = rand()%100000 + 1;
        Reverse3[i] = 1000000 - i;
    }

    printf("            Random1   Reverse1   Random2   Reverse2   Random3   Reverse3\n");

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));
    

    // Bubble sort start
    printf("Bubble        ");

    start = clock();
    bubbleSort(test1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    bubbleSort(test_Reverse1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    bubbleSort(test2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    bubbleSort(test_Reverse2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    bubbleSort(test3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    bubbleSort(test_Reverse3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    printf("\n");
    // /Bubble sort end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Selection sort start
    printf("Selection     ");

    start = clock();
    selectionSort(test1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    selectionSort(test_Reverse1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    selectionSort(test2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    selectionSort(test_Reverse2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    selectionSort(test3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    selectionSort(test_Reverse3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    printf("\n");
    // # /Selection sort end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Insertion sort start
    printf("Insertion     ");

    start = clock();
    insertionSort(test1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    insertionSort(test_Reverse1, 1000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    insertionSort(test2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    insertionSort(test_Reverse2, 10000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    insertionSort(test3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    start = clock();
    insertionSort(test_Reverse3, 100000);
    end = clock();
    printf("%5.3f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("      ");

    printf("\n");
    // # /Insertion sort end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Merge sort start
    printf("Merge     ");

    start = clock();
    mergeSort(test1, 0, 999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    mergeSort(test_Reverse1, 0, 999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    mergeSort(test2, 0, 9999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    mergeSort(test_Reverse2, 0, 9999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    mergeSort(test3, 0, 99999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    mergeSort(test_Reverse3, 0, 99999);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    printf("\n");
    // # /Merge sort end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Qucik, pivot is a last index
    printf("Quick1     ");

    start = clock();
    quickSort(test1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort(test_Reverse1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort(test2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort(test_Reverse2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort(test3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort(test_Reverse3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    printf("\n");
    // # /Qucik, pivot is a last index

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Quick, middle pivot
    printf("Quick2     ");

    start = clock();
    quickSort2(test1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort2(test_Reverse1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort2(test2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort2(test_Reverse2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort2(test3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort2(test_Reverse3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    printf("\n");
    // # /Quick, middle pivot end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Quick, random pivot
    printf("Quick3     ");

    start = clock();
    quickSort3(test1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort3(test_Reverse1, 0, 1000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort3(test2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort3(test_Reverse2, 0, 10000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort3(test3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    quickSort3(test_Reverse3, 0, 100000-1);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    printf("\n");
    // # Quick, random pivot end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    // # Heap sort start
    printf("Heap       ");

    start = clock();
    heapSort(test1, 1000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    heapSort(test_Reverse1, 1000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    heapSort(test2, 10000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    heapSort(test_Reverse2, 10000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    heapSort(test3, 100000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    start = clock();
    heapSort(test_Reverse3, 100000);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);

    printf("   ");

    printf("\n");
    // # /Heap sort end

    // Reset test Array
    memcpy(test1, Random1, sizeof(test1));
    memcpy(test_Reverse1, Reverse1, sizeof(test_Reverse1));
    memcpy(test2, Random2, sizeof(test2));
    memcpy(test_Reverse2, Reverse2, sizeof(test_Reverse2));
    memcpy(test3, Random3, sizeof(test3));
    memcpy(test_Reverse3, Reverse3, sizeof(test_Reverse3));

    printf("C Lib       ");

    start = clock();
    qsort(test1, sizeof(test1)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    start = clock();
    qsort(test_Reverse1, sizeof(test_Reverse1)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    start = clock();
    qsort(test2, sizeof(test2)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    start = clock();
    qsort(test_Reverse2, sizeof(test_Reverse2)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    start = clock();
    qsort(test3, sizeof(test3)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    start = clock();
    qsort(test_Reverse3, sizeof(test_Reverse3)/sizeof(int), sizeof(int), compare);
    end = clock();
    printf("%f", (double)(end - start)/CLOCKS_PER_SEC);
    printf("   ");

    printf("\n");

    return 0;
}