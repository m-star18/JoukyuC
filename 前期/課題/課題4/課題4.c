#include <stdio.h>

#define N_MAX 12

int factorial(int n) {
    int res;
    if (n > N_MAX) return 0;
    if (n == 0 || n == 1) {
        printf("1\n");
        return 1;
    }
    res = n * factorial(n - 1);
    printf("%d\n", res);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("n! = %d\n", factorial(n));
}
