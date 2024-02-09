#include <stdio.h>
#include <stdlib.h>

int main() {
    // int n, m;
    int array[40];
    int s = 0, a, avg_c = 0;
    int c = 0, mn_c = 1, mn = RAND_MAX;
    // scanf("%d %d", &n, &m);
    for(int i = 0; i < 40; i++) {
        // array[i] = rand() % (m - n + 1) + n;
        scanf("%d", &array[i]);
    }
    scanf("%d", &a);
    // printf("a: %d\n\n", a);
    for(int i = 0; i < 40; i++) {
        // printf("%d: %d\n", i, array[i]);
        if (array[i] < a) {
            s += array[i];
            avg_c++;
        }
    }
    
    float avg = (float) s / (float) avg_c;
    // printf("Avg_c: %d, Sum_avg: %d, avg: %f \n", avg_c, s, avg);
    for (int i = 0; i < 40; i++) {
        if (array[i] > avg) {
            if (array[i] < mn){
                mn = array[i];
                mn_c = 1;
            } else if (array[i] == mn) {
                mn_c++;
            }
            c++;
        }

    }
    printf("%.4f\n%d\n%d %d\n", avg, c, mn, mn_c);
    
    return 0;
}