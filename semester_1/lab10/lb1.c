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


void quickSort(int *arr, int first, int last,  int length) {
    int pivot;
    int l, r;
    l = first;
    r = last;
    pivot = arr[(l + r) / 2];
    countP += 1;

    while (l <= r) {
        countS += 1;
        while (arr[l] < pivot) {
            l++;
            countS += 1;
        }

        countS += 1;
        while (arr[r] > pivot) {
            r--;
            countS += 1;
        }

        if (l <= r) {
            swap(arr, l, r);
            if (l != r) {
                printArray(arr, length);
                printf("\n");
            }
            countP += 3;
            l++;
            r--;
        }
    }
    if (first < r) {
        quickSort(arr, first, r, length);
    }
    if (l < last) {
        quickSort(arr, l, last, length);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    getUserInput(&arr, size);
    printArray(arr, size);
    printf("\n");
    quickSort(arr, 0, size - 1,  size);
    printf("%d %d\n", countP, countS);
    return 0;
}