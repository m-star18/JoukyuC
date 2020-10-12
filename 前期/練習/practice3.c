#include <stdio.h>

int exponentiation(int x, int n) {
    int res;

    if (n == 0 || n == 1)
        return x;
    res = x * exponentiation(x, n - 1);
    return res;
}

int main() {
    int n, x;

    scanf("%d %d", &x, &n);
    printf("x^n = %d\n", exponentiation(x, n));
}
