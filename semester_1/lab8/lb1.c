#include <stdio.h>
#include <stdlib.h>

void input_from_keyboard(int size, int* array);
void input_random(int size, int* array, int a, int b);
void insert(int size, int** array, int a, int k);
void swap(int size, int* array, int i);
void print_array(int size, int* array);

int main(void) {
    int n, a, k, i;
    scanf("%d", &n);

    int* array = calloc(n, sizeof(int));
    input_from_keyboard(n, array);

    scanf("%d %d", &a, &k);
    scanf("%d", &i);



    print_array(n, array);
    printf("\n");


    insert(n, &array, a, k);
    n++;

//    print_array(n, array);


    swap(n, array, i);

    print_array(n, array);



    return 0;
}

void input_from_keyboard(int size, int* array) {
    for(int i = 0; i < size; i++) {
        scanf("%d", (array + i));
    }
}

void print_array(int size, int* array) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%3d", i+1);
        } else {
            printf(" %2d", i+1);
        }
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%3d", *(array + i));
        } else {
            printf(" %2d", *(array + i));
        }
    }
    printf("\n");

}

void insert(int size, int** array, int a, int k) {
    k--;
    *array = (realloc(*array, sizeof(int) * (size + 1)));
    for(int i = size; i >= k; i--) {
        if (i == k) {
            *(*array + i) = a;
        } else {
            *(*array + i) = *(*array + i - 1);
        }
    }
}

void swap(int size, int* array, int i) {
    i--;
     int tmp = *(array + size - 1);
    *(array + size - 1) = *(array + i);
    *(array + i) = tmp;
}