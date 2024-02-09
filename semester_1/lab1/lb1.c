#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d", &a);
    b = (a % 10) * (a / 10 % 10) * (a / 100 % 10) * (a / 1000);
    printf("%d\n", a / b);
    return 0;
}