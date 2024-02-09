#include <stdio.h>
#include <limits.h>

int func(int x, int y) {
    int r = 1;
    for(int i = 0; i < y; i++) {
        if (r > LONG_MAX / x) return 0;
        r *= x;
    }
    return r;
}
int main(void) {
    char sgn;
    int k, n = 1, fl = 1;
    long int s = 0, f, mx_s = 0;
    scanf("%d", &k);
    while(1){
        for (int i = 1; i < (2*k - 1) + 1; i+=2) {
            f = func(i, n);
            if (f == 0) {
                printf("%ld\n", mx_s);
                printf("%d\n", n - 1);
                printf("*\n");
                return 0;
            }
            if (s > LONG_MAX - f) {
                printf("%ld\n", mx_s);
                printf("%d\n", n - 1);
                printf("+\n");
                return 0;
            }
            s += f;
        }
        n++;
        mx_s = s;
        s = 0;
        
    }
    return 0;
}