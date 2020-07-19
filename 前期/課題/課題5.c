#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binary_search(const int data[], int check) {
    int low = 0;
    int high = N - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] == check)
            return mid;

        else if (data[mid] > check)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int data[N], ans;
    int sort_time, search_time;
    int m, k;

    scanf("%d %d", &m, &k);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++)
        data[i] = rand() % m;

    sort_time = clock();
    qsort(data, N, sizeof(int), compare_int);
    sort_time -= clock();

    search_time = clock();
    ans = binary_search(data, k);
    search_time -= clock();

    printf("２分探索　結果: %d\n", ans);
    printf("計測時間 ソート: %f[ms]\n", -(double)sort_time / CLOCKS_PER_SEC);
    printf("計測時間 ２分探索: %f[ms]\n", -(double)search_time / CLOCKS_PER_SEC);
}
