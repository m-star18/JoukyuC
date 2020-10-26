#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 問題1 */
typedef struct kadai {
    int number;
    char name[20];
    int intermediate_score;
    int final_score;
} KADAI;

int main() {
    int n, i;
    double *score;
    int max_i = 0, min_i = 0;
    char name[20];
    KADAI *kadai_p;

    /* 問題2 */
    printf("人数を入力してください.");
    scanf("%d", &n);
    kadai_p = (struct kadai*) malloc(sizeof(struct kadai) * n);

    /* エラー処理 */
    if (kadai_p == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("番号, 名前, 中間スコア, 期末スコア\n");
        scanf("%d %s %d %d", &kadai_p[i].number, name, &kadai_p[i].intermediate_score, &kadai_p[i].final_score);
        strcpy(kadai_p[i].name, name);
    }

    for (i = 0; i < n; i++)
        printf("%d %s %d %d\n", kadai_p[i].number, kadai_p[i].name, kadai_p[i].intermediate_score, kadai_p[i].final_score);

    /* 問題3 */
    score = (double *) malloc(sizeof(double) * n);

    /* エラー処理 */
    if (score == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        score[i] = kadai_p[i].intermediate_score * 0.3 + kadai_p[i].final_score * 0.7;
        /* 最大値の場合 */
        if (score[i] > score[max_i])
            max_i = i;
        /* 最小値の場合 */
        if (score[i] < score[min_i])
            min_i = i;
    }

    printf("最大値: 名前%sさん %.2f点\n", kadai_p[max_i].name, score[max_i]);
    printf("最小値: 名前%sさん %.2f点\n", kadai_p[min_i].name, score[min_i]);

    free(kadai_p);
    free(score);
}
