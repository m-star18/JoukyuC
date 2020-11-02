#include <stdio.h>

#define N 7
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))

int main() {
    int i, b;
    int max_b = 0, min_b = 2147483647;

    for (i = 0; i < N; i++) {
        scanf("%d", &b);
        max_b = max(b, max_b);
        min_b = min(b, min_b);
    }
    printf("%d %d\n", max_b, min_b);
}
