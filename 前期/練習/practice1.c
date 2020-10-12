#include <stdio.h>

int rec(int n) {
    if (n > 0) {
        printf("%d\n", n);
        rec(n - 1);
    } else
        printf("\n終了\n");

    return 0;
}

int main() {
    int n = 3;
    rec(n);
}
