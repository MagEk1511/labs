#include <stdio.h>

int main(void) {
    int c, s, mn = 1000000000, mn_num, mx = 0, mx_num;
    for(int i = 180; i <= 210; i++) {
        printf("%d  ", i);
        c = 0;
        s = 0;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                if(c != 0) {
                    printf(",");
                }
                s += j;
                if (c % 4 == 0 && c != 0) {
                    printf("\n     ");
                }
                printf("%3d", j);
                c += 1;
            }
        }
        if ((mn >= s) && (c != 0)) {
            mn = s;
            mn_num = i;
        }
        if (c == 0) {
            printf("                  %3d\n", s);
        } else {
            c %= 4;
            if (c == 0) {
                printf(" %5d\n", s);
            } else {
                for(int i = 0; i < 4 - c; i++) {
                    printf("    ");
                }
                printf(" %5d\n", s);
            }
        }
    }
    printf("\n%d\n", mn_num);
    return 0;
}