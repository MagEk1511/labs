#include <stdio.h>

int f(int x, int y) {
    if (((x * x + y * y < 90000) && y > 0 && !(x < 150 && x > -150 && y < 150 && y > 0)) || (y < -x && y < x && y < -150 && x * x + y * y < 90000)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    // for(int i = 0; i > -300; i--){
    //     for(int j = 0; j < 200; j++){
    //         printf("%d", f(j, i));
    //     }
    //     printf("\n");
    // }
    if (f(x, y)) {
        printf("inside\n");
    } else {
        printf("outside\n");
    }
    return 0;
}