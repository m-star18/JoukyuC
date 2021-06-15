#include <stdio.h>

#define N 5

int data[N] = {4, 5, 2, 3, 1};

void show() {
    for (int i = 0; i < N; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void quick_sort(int left, int right) {
    int i, j, s, t;
    if (left < right) {
        s = data[(left + right) / 2];
        i = left;
        j = right;
        while (1) {
            while (data[i] < s)
                i++;
            while (data[j] > s)
                j--;
            if (i >= j)
                break;
            t = data[i];
            data[i] = data[j];
            data[j] = t;
            show();
            i++;
            j--;
        }
        quick_sort(left, i - 1);
        quick_sort(j + 1, right);
    }
}

int main() {
    show();
    quick_sort(0, 4);
    show();
}
