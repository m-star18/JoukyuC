#include <stdio.h>

#define N 10

int data[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void show() {
    for (int i = 0; i < N; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void down_heap(int n, int p) {
    for (int s = 2 * p; s <= n; p = s, s = 2 * p) {
        if (s < n && data[s + 1] > data[s])
            s++;
        if (data[p] >= data[s])
            break;
        swap(&data[p], &data[s]);
    }
}

void heap_sort() {
    int n = N - 1;
    for (int i = n / 2; i >= 1; i--)
        down_heap(n, i);
    while (n > 0) {
        swap(&data[0], &data[n]);
        n--;
        down_heap(n, 0);
        show();
    }
}

int main() {
    show();
    heap_sort();
    show();
}
