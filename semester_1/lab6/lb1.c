#include <stdio.h>

void makeArray(int a, int b, int array[], int m) {
    for (int i = 0; i < m; i++) {
        array[i] = a + b * (i);
    }
}

void printArray(int *l, int *r) {
    int i = 1;
    int *tmp = l;
    while (tmp <= r) {
        printf("%5d", i++);
        tmp++;
    }
    printf("\n");
    while (l <= r) {
        printf("%5d", *l);
        l++;
    }
    printf("\n");
}

void f(int a[], int b[], int m, int k) {
    for(int i = 0; i < k; i++) {
        int tmp = a[i];
        a[i] = b[m-k+i];
        b[m-k+i] = tmp;
    }
}

int main() {
    int m1[10], m2[12];
    int a1, b1, a2, b2, k;
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    scanf("%d", &k);
    makeArray(a1, b1, m1, 10);
    printArray(m1, &m1[9]);
    printf("\n");
    makeArray(a2, b2, m2, 12);
    printArray(&m2[0], &m2[11]);
    printf("\n");
    f(m1, m2, 12, k);
    f(m2, m1, 10, k);
    f(m2, m2, 12, k);
    printArray(&m1[0], &m1[9]);
    printf("\n");
    printArray(&m2[0], &m2[11]);
    return 0;
}