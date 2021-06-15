#include <stdio.h>

#define N 5

int data[N] = {4, 5, 3, 2, 1};

void show() {
    for (int i = 0; i < N; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void shell_sort() {
    int tmp, j;

    for (int hop = N / 2; hop > 0; hop /= 2) {
        for (int k = 0; k < hop; k++) {
            show();
            for (int i = k + hop; i < N; i += hop) {
                tmp = data[i];
                j = i - hop;
                while (j >= k && data[j] > tmp) {
                    data[j + hop] = data[j];
                    j -= hop;
                }
                data[j + hop] = tmp;
            }
        }
    }
}

int main() {
    shell_sort();
    show();
}
