#include <math.h>
#include <stdio.h>

double f(double x) {
    return sqrt((1 + sqrt(x) + 3 * pow(x, 3)) / (3 + pow(cos(x), 2) + sqrt(x) + pow(x, 3)));
}



int main(void) {
    double s = 0.0;
    double s_cor = 0.0;
    double b_s = 0.0;
    double f_cor;
    double cor = 0.0;
    double slag;
    for(int i = 1; i <= 200000000; i ++) {
        slag = f(i);
        f_cor = slag - cor;
        s_cor = b_s + f_cor;
        cor = (s_cor - b_s) - f_cor;
        b_s = s_cor;
        s += slag;
        if (i % 20000000 == 0) {
            if (s - b_s < 0) {
                printf("%9d   %15.4lf   %15.4lf   %1.4lf\n", i, s, b_s, s - b_s);
            } else {
                printf("%9d   %15.4lf   %15.4lf    %1.4lf\n", i, s, b_s, s - b_s);
            }
        }
    }
    return 0;
}
