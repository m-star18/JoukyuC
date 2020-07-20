#include <stdio.h>

#define N 7
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))

int main() {
    int i, b, maximum, minimum;

    for (i = 0; i < N; i++) {
        scanf("%d", &b);
        maximum = max(b, maximum);
        minimum = min(b, minimum);
    }
    printf("%d %d\n", maximum, minimum);
}
