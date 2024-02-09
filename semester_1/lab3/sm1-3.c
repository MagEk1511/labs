#include <stdio.h>
#include <math.h>

int main(void) {
    double n = 0;
    long double res = 0;
    double t = 11.0 / 18.0;
    do {
        n++;
        res += 1.0 / (n * (n + 3.0));
        // if (n % 1000000 == 0) {
        //     printf("%Lf %lf\n", res, t);
        // }
    } while (fabs(t - res) > 1e-8);
    printf("%.8f\n%.8Lf\n%.8lf\n%d\n", t, res, fabs(res - t), (int) n);
}