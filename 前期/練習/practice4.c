#include <stdio.h>

int ruijo(int x, int n) {
    int ans;

    if (n == 0)
        return 1;
    else ans = x * ruijo(x, n - 1);

    return ans;
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d\n", ruijo(x, n));
}
