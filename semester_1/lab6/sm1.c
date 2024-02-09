#include <stdio.h>
#include <stdlib.h>

void make_empty(int a[], int size);
void fill_keyboard(int a[], int size);
void fill_random(int from, int to, int a[], int size);
void print_array(int a[], int size);
int sum_array(int a[], int size);
float average_array(int *from, int *to);


int main() {
    int a[5], b[6], c[8], count = 0;

    fill_keyboard(a, 5);
    fill_keyboard(b, 6);
    fill_keyboard(c, 8);

    int from_n, to_n;
    scanf("%d %d", &from_n, &to_n);

    // print_array(a, 5);
    // print_array(b, 6);
    // print_array(c, 8);

    printf("%d %d %d\n", sum_array(a, 5), sum_array(b, 6), sum_array(c, 8));

    printf("%.1f\n", average_array(&c[from_n - 1], &c[to_n]));

    int elements[6];

    make_empty(elements, 6);

    for (int i = 0; i < 5; i++) {
        elements[a[i]-10] = 1;
    }
    for (int i = 0; i < 6; i++) {
        if (elements[b[i]-10] == 1) {
            elements[b[i]-10] = 2;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (elements[c[i]-10] == 2) {
            elements[c[i]-10] = 3;
            count++;
        }
    }
    int flag = 0;
    for (int k = 0; k < 6; k++){
        if ((elements[k] == 3) && (flag == 0)){
            printf("%d", (10+k));
            flag++;
        }
        else if (elements[k] == 3){
            printf(" %d", (10+k));
        }
    }
    printf("\n");
    return 0;
}

void make_empty(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = 0;
    }
}

void fill_keyboard(int a[], int size) {
    for(int i = 0; i < size; i++) {
        scanf("%d", &(a[i]));
    }
}

void fill_random(int from, int to, int a[], int size) {
    from++;
    for (int i =0; i < size; i++) {
        a[i] = rand() % (to - from) + from;
    }
}

void print_array(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", a[i]);
        if (i != size - 1) printf(" ");
    }
    printf("\n");
}

int sum_array(int a[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
       sum += a[i];
    }
    return sum;
}

float average_array(int *from, int *to) {
    int c = 0, sum = 0;
    for (;from < to; from++) {
        c++;
        sum += *from;
    }
    return (float) sum / c;
}