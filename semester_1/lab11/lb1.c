#include <stdio.h>
#include <stdlib.h>

void getUserInput(int** array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (*array + i));
    }
}
void makePointerArr(int **pArr, int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        pArr[i] = &arr[i];
    }
}

void printArray(int **array, int size) {
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
            printf("%3d", *(array[i]));
        } else {
            printf("%3d", *array[i]);
        }
    }
    printf("\n");
}

void swap(int** arr, int a, int b) {
    int* c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void merge(int **arr1, int **arr2, int size1, int size2) {
    for (int i = 1; i <= size1 + size2; ++i) {
        if (i == 0) {
            printf("%3d", i);
        } else {
            printf("%3d", i);
        }
    }

    printf("\n");

    int i = 0, j = 0;
    while (i + j < size1 + size2 - 1) {
        if (*arr1[i] >= *arr2[j]) {
            printf("%3d", *arr1[i++]);
        } else {
            printf("%3d", *arr2[j++]);
        }
    }

    if (i != size1) {
        printf("%3d", *arr1[i]);
    } else {
        printf("%3d", *arr2[j]);
    }

    printf("\n\n");
}


void pQuickSort(int **arr, int first, int last,  int length) {
    int pivot;
    int l, r;
    l = first;
    r = last;
    pivot = *arr[(l + r) / 2];

    while (l <= r) {
        while (*arr[l] > pivot) {
            l++;
        }

        while (*arr[r] < pivot) {
            r--;
        }

        if (l <= r) {
            swap(arr, l, r);
//            if (l != r) {
//                printArray(arr, length);
//                printf("\n");
//            }
            l++;
            r--;
        }
    }
    if (first < r) {
        pQuickSort(arr, first, r, length);
    }
    if (l < last) {
        pQuickSort(arr, l, last, length);
    }
}

int main() {
    int size1, size2;
    scanf("%d", &size1);
    int* arr1 = malloc(size1 * sizeof(int));
    int **pArr1 = malloc(size1 * sizeof(&size1));
    getUserInput(&arr1, size1);
    makePointerArr(pArr1, arr1, size1);
    scanf("%d", &size2);
    int* arr2 = malloc(size2 * sizeof(int));
    int **pArr2 = malloc(size2 * sizeof(&size2));
    getUserInput(&arr2, size2);
    makePointerArr(pArr2, arr2, size1);
    printArray(pArr1, size1);
    printf("\n");
    printArray(pArr2, size2);
    printf("\n");
    pQuickSort(pArr1, 0, size1 - 1,  size1);
    pQuickSort(pArr2, 0, size2 - 1,  size2);

    merge(pArr1, pArr2, size1, size2);
    return 0;
}