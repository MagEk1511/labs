#include <stdio.h>
#include <stdlib.h>


int countP = 0;
int countS = 0;

void getUserInput(int** array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (*array + i));
    }
}

void printArray(int* array, int size) {
    for (int i = 1; i <= size; ++i) {
        if (i == 0) {
            printf("%3d", i);
        } else {
            printf("%3d", i);
        }
    }
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            printf("%3d", array[i]);
        } else {
            printf("%3d", array[i]);
        }
    }
    printf("\n");
}

void swap(int* arr, int a, int b) {
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void Merge(int* arr, int first, int last, int n) {
    int B[n]; /*вспомогательный массив*/
    int k; /*индекс во вспомогательном массиве*/
    int l,r; /*левый и правый счетчики*/
    int m; /*индекс среднего элемента*/
    m=(first+last)/2;
    l=first; r=m+1;
    k=0;
    while (l<=m && r<=last) {
        if (arr[l]<=arr[r]) {
            B[k]=arr[l]; l++; }
        else {
            B[k]=arr[r]; r++; }
        k++;
        countS++;
        countP++;
    }

    while (l<=m) {
        B[k]=arr[l]; l++; k++; countP++;}
    while (r<=last) {
        B[k]=arr[r]; r++; k++; countP++;}
    for (l=0; l<k; l++) {
        arr[first+l]=B[l];
        countP++;
    }
}

void MergeSort(int* arr, int fst, int lst, int n)
{
    int m; /*индекс среднего элемента*/
    if (fst<lst)
        if (lst-fst==1) {
            if (arr[lst]<arr[fst]) {
                swap(arr, fst, lst);
                countP += 3;
                printArray(arr, n);
                printf("\n");
            }
            countS++;
        }
        else {
            m=(fst+lst)/2;
            MergeSort(arr, fst,m, n);
            MergeSort(arr, m+1,lst, n);
            Merge(arr, fst, lst, n);
            printArray(arr, n);
            printf("\n");
        }
}

int main() {
    int size;
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    getUserInput(&arr, size);
    printArray(arr, size);
    printf("\n");
    MergeSort(arr, 0, size - 1,  size);
    printf("%d %d\n", countP, countS);
    return 0;
}