#include <math.h>
#include <stdio.h>

double f(double x) {
    return x * x - 7 * x + 8;
}

int main(void) {
    double a = 0, b = 3, c, res;
    do {
        c = (a + b) / 2;
        res = f(c);
        if (f(a) < f(b)) {
            if (res > 0) {
                b = c;
            } else {
                a = c;
            }
        } else {
            if (res > 0) {
                a = c;
            } else {
                b = c;
            }
        }
    }
    while (fabs(res) > 1e-10);
    printf("%.10lf\n", c);
    return 0;
}