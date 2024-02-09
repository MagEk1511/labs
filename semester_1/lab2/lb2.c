#include <stdio.h>
#include <limits.h>

int main(void) {
    int k, first = 1, second = 1, tmp=0, third, i;
    scanf("%d", &k);
    for(i = 0; i < k; i++) {
        if (i < 9){
            printf("  %d  %d\n", i + 1, first);
        } else {
            printf(" %d  %d\n", i + 1, first);
        }
        tmp = first;
        first = second;
        second = tmp + first;
    }
    first = 1, second = 1, tmp=0, third=0;
    for(i = 0;;i++) {
        // if (i < 9){
        //     printf("  %d  %d\n", i + 1, first);
        // } else {
        //     printf(" %d  %d\n", i + 1, first);
        // }
        if (second > INT_MAX - first) {
            break;
        } else {
            tmp = first;
            first = second;
            second = tmp + first;
        }
        
    }
    printf("\n%3d  %d\n", i, tmp);
    printf("%3d  %d\n", i+1, first);
    printf("%3d  %d\n", i+2, second);
    return 0;
}