#include <stdio.h>
#include <math.h>

int main(void) {
    double n = 0;
    double res = 0, f;
    double t = 11.0 / 18.0;

    do {
        n++;
        f = 1.0 / (n * (n + 3.0));
        res += f;
    } while (fabs(t - res) > 1e-8);

    printf("%.8lf\n%.8lf\n%.8f\n%d\n", t, res, 1e-8, (int) n);
    return 0;
}