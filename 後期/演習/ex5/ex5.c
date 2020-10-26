#include <stdio.h>
#include <stdlib.h> /* 設問１：必要なヘッダファイルのインクルード */

#define N1 10      /* 10人 */
#define N2 5       /* 5科目 */

int main(void) {
    int i, j;     /* i:行，j:列 の走査用 */
    /* 設問２：2次元配列に対応する2連鎖ポインタを宣言する */
    int **a;
    /* 設問３：2次元配列を動的に確保 */
    a = (int **) malloc(sizeof(int *) * N1);
    for (i = 0; i < N1; i++)
        a[i] = (int *) malloc(sizeof(int) * N2);
    /* 設問４：input.txt からのデータ入力 */
    FILE *fp; // ファイルポインタを宣言
    fp = fopen("input.txt", "r"); // ファイルオープン
    for (i = 0; i < N1; i++) {
        for (j = 0; j < N2; j++) {
            // データの読み込み
            fscanf(fp, "%d", &a[i][j]);
            printf("a[%d][%d]:%d\n",i, j, a[i][j]);  // 読み込みと同時に確認のため出力
        }
    }
    fclose(fp);

    /* 設問５：データを output.csv に出力 */
    fp = fopen("output.csv", "w"); // ファイルオープン
    for (i = 0; i < N1; i++) {
        int total = 0; // 合計点
        for (j = 0; j < N2; j++) {
            // データの書き込み
            fprintf(fp, "%d ", a[i][j]);
            total += a[i][j]; // 合計点の計算
        }
        fprintf(fp, "%d\n", total); // 合計点の書き込み
    }
    fclose(fp);

    /* 設問６：二次元配列領域の解放(freeする順番に注意) */
    for (i = 0; i < N2; i++)
        free(a[i]);

    free(a);
}
