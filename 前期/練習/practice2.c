#include <stdio.h>

int factorial(int n) {
    int res;

    if (n == 0 || n == 1)
        return 1;
    res = n * factorial(n - 1);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("n! = %d\n", factorial(n));
}
