#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int c = 0;

unsigned long int f(unsigned long int n, unsigned long int m) {
    c++;
    if (n > ULONG_MAX - m || c > 1000) {
        printf("endless\n");
        exit(0);
    }
    if ((n + m) % 2 == 0) {
        return (n < m) ? n : m;
    } else {
        return f((n+m+1)/2, m) + f(n, (n+m+1)/2);
    }

    
}

int main() {
    unsigned long int n, m;
    scanf("%lu %lu", &n, &m);
    unsigned long int r = f(n, m);
    printf("%lu\n", r);
    return 0;
}