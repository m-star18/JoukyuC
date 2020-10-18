/* 上級CプログラミングB 出題日：2020/10/12
3I 10番 氏名 伊藤竜聖 提出日：2020/10/19 */
/* 演習3 バブルソートのデータ構造を静的配列から動的配列に変更する
    ファイル名 ex3.c */

#include <stdio.h>
#include <stdlib.h>  // 設問１：必要なヘッダファイルのインクルード

#define N 100000

/* プロトタイプ宣言 */
void bsort(int[], int); /* バブルソート */
void set_random(int[], int); /* 配列にランダムな数字をセット */

int main() {
    /* 設問２：一次元配列に相当する一連鎖のポインタ a を宣言する */
    int a[N], *p;

    int n, i; /* n は要素数 */
    /* 設問３：要素数の取得 */
    printf("要素数を入力：");
    scanf("%d", &n);

    /* 設問４：要素数を変数で指定して領域を動的に確保する */
    p = malloc(sizeof(int) * n);

    /* エラー処理 */
    if (p == NULL) {
        printf("cannot allocate!\n");
        exit(1);
    }

    set_random(a, n); /* 配列を初期化 */
    printf("ソート前\n");
    // 設問５：配列の中身を出力（for文で）
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    /* 設問６：バブルソートを行う関数を呼び出して，a をソート */
    bsort(a, n);

    printf("ソート後\n");
    // 再度出力（設問５と同じ）
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    /* 設問７：配列の利用が終わったら，領域を解放する */
    free(p);
}

/* 以下，関数定義．変更の必要はない */
void bsort(int a[], int n) {
    int i, j;
    int tmp;

    for (i = 0; i<n-1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void set_random(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % n;
}
