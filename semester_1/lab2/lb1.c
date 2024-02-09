#include <stdio.h>

int main(void) {
    int k = 1, s = 7, m;
    scanf("%d", &m);
    while(s <= m) {
        s *= 7;
        k++;
    }
    printf("%d\n", k);
}