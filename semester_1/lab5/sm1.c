#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 655359
#define MIN -655359

int q2d(long int input) {
    long int r = 0;
    for(int i = 0;input>0; input/=10) {
        r += (input % 10) * pow(4, i);
        i++;
    }
    return r;
}

int d2q(long int input) {
    long int r = 0;
    int i = 0;
    while (input > 0)
    {
        r += input % 4 * pow(10, i++);
        input /= 4;
    }
    return r;
    
}

int checkD(long int input) {
    if (input > 655359 || input < -655359) return 1;
    return 0;
}

int formula1(long int a, long int b, long int *r) {
    long int c1, c2, c3 = b;
    if ((a > MAX / a) || (a > (MAX / (a * a)))) {
        return 4;
    } else {
        c1 = a * a * b; 
    }

    if (b > MAX + a || b < MIN + a) {
        return 2;
    } else {
        if (labs(b - a) > MAX / labs(b))
        {
            return 3;
            /* code */
        } else {
            c2 = b * (b - a);
        }        
    }

    if (c1 < c2 + MIN || c1 > c2 + MAX)
    {
        return 2;
    } else {
        c1 = c1 - c2;
    }

    if (c1 > c3 + MAX || c1 < c3 + MIN)
    {
        return 1;
    } else {
        c1 += c3;
    }
    (*r) = c1;
    
    return 0;
}

int formula2(long int a, long int b, long int *r) {
    
}

int main() {
    long int r;
    int status = formula1(50, 23, &r);
    printf("%d\n", status);
    printf("%ld\n", r);
    return 0;
}