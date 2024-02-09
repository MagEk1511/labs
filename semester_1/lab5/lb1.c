#include <stdio.h>
#include <math.h>

int solveEquation(int a, int b, int c, float *root1, float *root2) {
    float A = c;
    float B = c * b - 1;
    float C = -a;

    float D = B * B - 4 * A * C;

    if (a == 0 && b == 1 && c == 1) {
        *root1 = 0;
        return 1;
    }
    

    if (c == 0) {
        if (a - b == 0) {
            return -2;
        }
        *root1 = -a;
        return 1;
    }

    if (a == b) {
        if ((float) 1 / c != -1 * a) {
            *root1 = (float) 1 / c;
            return 1;
        } else {
            return -2;
        }
    }


    if (A == 0) {
        if (b*c == 1) {
            return -1;
        }
        *root1 = a / b*c - 2;
        return 1;
    }

    if (D > 0) {
        if ((-B + sqrt(D)) / (2 * A) == -b) {
            *root1 = (-B - sqrt(D)) / (2 * A);
            return 1;
        } else if ((-B - sqrt(D)) / (2 * A) == -b) {
            *root1 = (-B + sqrt(D)) / (2 * A);
            return 1;
        } else {
            if ((-B + sqrt(D)) / (2 * A) < (-B - sqrt(D)) / (2 * A)) {
                *root1 = (-B + sqrt(D)) / (2 * A);
                *root2 = (-B - sqrt(D)) / (2 * A);
            } else {
                *root2 = (-B + sqrt(D)) / (2 * A);
                *root1 = (-B - sqrt(D)) / (2 * A);
            }
            
            return 0;
        }
    } else if (D == 0) {
        if ((-B - sqrt(D)) / (2 * A) == -b) {
            *root1 = 0;
            return -2;
        } else {
            *root1 = -B / (2 * A);
            *root2 = -B / (2 * A);
            return 1;
        }
    } else {
        return -1;
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    float root1, root2;
    int result = solveEquation(a, b, c, &root1, &root2);

    if (result == 0) {
        printf("0\n%.6f\n%.6f\n", root1, root2);
    } else if (result == 1) {
        printf("1\n%.6f\n", root1);
    } else if (result == -2) {
        printf("3\n");
    } else {
        printf("2\n");
    }
    return 0;
}