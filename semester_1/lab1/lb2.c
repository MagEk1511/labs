#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c) {
        printf("%d=%d=%d\n", a, b, c);
    } else if (a != b && a != c && b != c) {
        if ((a > b && a < c) || (a < b && a > c)) {
            printf("%d\n", a);
        }
        if ((b > c && b < a) || (b < c && b > a)) {
            printf("%d\n", b);
        }
        if ((c > b && c < a) || (c < b && c > a)) {
            printf("%d\n", c);
        }
    } else {
        if (a == b) {
            printf("%d=%d", a, b);
            if (c > a) {
                printf("<%d\n", c);
            } else {
                printf(">%d\n", c);
            }
        }
        if (a == c) {
            printf("%d=%d", a, c);
            if (b > a) {
                printf("<%d\n", b);
            } else {
                printf(">%d\n", b);
            }
        }
        if (c == b) {
            printf("%d=%d", c, b);
            if (a > c) {
                printf("<%d\n", a);
            } else {
                printf(">%d\n", a);
            }
        }
    }
    return 0;
}