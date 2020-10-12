#include <stdio.h>

int main() {
    /* 通常のポインタ変数 */
    {
        int a;
        a = 5;
        int *p;
        p = &a;  /* 同時に書くと int *p=&a; */
        printf("&a : %p, a : %d\n", &a, a);
        /* 設問１：pが指す変数のアドレス，pが指す変数の値をpを用いて出力 */
        printf("%p %d\n", p, *p);
    }

    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p1, *p2;
        p1 = &a[2];
        p2 = &a[4];
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        printf("&a[4] : %p, a[4] : %d\n", &a[4], a[4]);
        /* 設問２：
        p1が指す変数のアドレス，p1が指す変数の値をp1を用いて出力

        p2が指す変数のアドレス，p2が指す変数の値をp2を用いて出力
        */
        printf("%p %d\n", p1, *p1);
        printf("%p %d\n", p2, *p2);
    }

    /* 配列としてのポインタ */
    {
        int a[5] = {1, 2, 3, 4, 5};
        int *p;
        p = a;   /* p = &a[0]; も同じ意味 */
        printf("&a[0] : %p, a[0] : %d\n", &a[0], a[0]);
        printf("&a[2] : %p, a[2] : %d\n", &a[2], a[2]);
        /* 設問３：pが指す変数（配列）のアドレス，pが指す配列の先頭の値をpを用いて出力する */
        printf("%p %d\n", p, p[0]);
        /* 設問４：a[2]のアドレス，値をpを用いて出力 */
        printf("%p %d\n", p + 2, p[2]);
        /* 設問５：a[2]のアドレス，値をpを用いて出力（配列風の記述で） */
        printf("%p %d\n", &p[2], p[2]);
        /* 設問６：a[2]のアドレス，値をaを用いて出力（ポインタ風の記述で） */
        printf("%p %d\n", p + 2, *(p + 2));
    }

    /* 関数ポインタ */
    {
        int func(int); /* プロトタイプ宣言 */
        int (*p_func)(int);
        p_func = func;
        printf("funcのアドレス : %p, func(5) : %d\n", func, func(5));
        /* 設問７：関数ポインタ p_func が指すアドレス，p_funcが指す関数を呼び出し */
        printf("%p %d\n", func, func(5));
    }

    {
        /* 設問８：正しくプロトタイプ宣言する */
        void swap(int *a, int *b);
        int a[2] = {5, 3};
        printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
        /* 設問９：正しく swap関数呼び出し，a[0]とa[1]の値を交換する */
        /* 表示して確認 */
        printf("swap後\n");
        swap(&a[0], &a[1]);
        printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);
    }
}

/* 関数ポインタで管理する関数．変更の必要なし */
int func(int i) {
    return i;
}

/* 設問１０：swap関数を作成する */
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
