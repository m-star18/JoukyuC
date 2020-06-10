a
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define T !0

int prime[N];

void make_prime(n) {
    prime[0] = T;
    prime[1] = T;
    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = T;
        }
    }
}

int main() {
    int value;
    make_prime(N);
    srand((unsigned int)time(NULL));
    for (int i = 0; i <= N; i++) {
        value = rand() % N;
        if (!prime[value])
            printf("%d\n", value);
    }
}
