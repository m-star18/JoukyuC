#include <stdio.h>
#include <stdlib.h>

# define xy 11
# define calc(flag, a, b) ((flag) == 1 ? ((a) * (b)) : ((a) + (b)))

int main() {
    int **hyakumasu, flag;
    int i, j;

    /* 問題1 */
    hyakumasu = (int **) malloc(sizeof(int *) * xy);
    for (i = 0; i < xy; i++)
        hyakumasu[i] = (int *) malloc(sizeof(int) * xy);

    /* 問題2 */
    hyakumasu[0][0] = 0;
    for (i = 1; i < xy; i++) {
        hyakumasu[0][i] = (xy - i) * (xy - i);
        hyakumasu[i][0] = 2 * i + 1;
    }

    /* 問題3, 4 */
    printf("掛け算: 1\n足し算: 2\n");
    scanf("%d", &flag);

    /* 計算 */
    for (i = 1; i < xy; i++) {
        for (j = 1; j < xy; j++)
            hyakumasu[i][j] = calc(flag, hyakumasu[i][0], hyakumasu[0][j]);
    }

    /* 表示 */
    for (i = 0; i < xy; i++) {
        printf("%5d|", hyakumasu[i][0]);
        for (j = 1; j < xy; j++)
            printf("%5d", hyakumasu[i][j]);
        printf("\n");
        if (i == 0) {
            printf("-----+");
            for (j = 1; j < xy; j++)
                printf("-----");
            printf("\n");
        }
    }

    /* 開放 */
    for (i = 0; i < xy; i++)
        free(hyakumasu[i]);
    free(hyakumasu);
}
