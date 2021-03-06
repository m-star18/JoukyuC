#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define X 1000
#define Y 100
#define max(p, q) ((p) > (q) ? (p) : (q))

int is_prime(int n) {
    if (n == 2)
        return 1;

    if ((n % 2 == 0) || (n == 1))
        return 0;

    for (int i = 3; i < sqrt(n); i = i + 2)
        if (n % i == 0) return 0;

    return 1;
}

int main() {
    int data[Y], prime[Y];
    int idx = 0, ans = 0;

    srand((unsigned int) time(NULL));
    for (int i = 0; i < Y; i++) {
        data[i] = rand() % X;
        if (1 == is_prime(data[i])) {
            prime[idx] = data[i];
            ans = max(ans, prime[idx]);
            idx++;
        }
    }
    printf("%d\n", ans);
}
