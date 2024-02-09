#include <stdio.h>
#include <stdlib.h>

struct sortInfo {
    int countP;
    int countS;
};

void getUserInput(int** array, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (*array + i));
    }
}

void copyArray(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[i];
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

void selectionSort(int* arr, int size) {
    struct sortInfo info;
    info.countP = 0;
    info.countS = 0;
    for (int i = 0; i < size - 1; i++) {
        if (i != 0) {
            printf("\n");
        }
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
            (info.countS)++;
        }
        swap(arr, i, min_index);
        (info.countP) += 3;

        printArray(arr, size);
    }
    printf("%d %d", info.countP, info.countS);
    printf("\n");
}

void bubbleSort(int* arr, int size) {
    int i, j;
    struct sortInfo info;
    info.countP = 0;
    info.countS = 0;
    for (i = size - 1; i > 0; i--) {
        printf("\n");
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j + 1, j);
                info.countP += 3;
            }
            info.countS++;
        }
        printArray(arr, size);
    }
    printf("%d %d\n", info.countP, info.countS);
}

int main() {
    int size;
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    getUserInput(&arr, size);
    int* arr2 = malloc(size * sizeof(int));
    copyArray(arr, arr2, size);
    printArray(arr, size);
    printf("\n");
    selectionSort(arr, size);
    bubbleSort(arr2, size);
    return 0;
}