#include <stdio.h>

#define N 10

/* 設問１：ノードを表現するための構造体を定義する */
typedef struct Node {
    int data;
    struct Node *next;
} Element;

int main() {
    int i;
    /* 設問２：ノード用の構造体配列 node[N] を宣言する */
    Element node[N];
    /* 設問３：各ノードを正しくリンクする
       data に代入する値は i とする
    */
    for (i = 0; i < N - 1; i++) {
        node[i].data = i * i;
        node[i].next = &node[i + 1];
    }

    /* 設問４：末端ノードを正しくリンクする */
    node[i].data = i * i;
    node[i].next = NULL;

    /* 設問５：線形リスト用のfor文(ポインタ p を用いる)によって出力する
       出力する値は，現在のノードのアドレス，現在のノードの値，次のノードのアドレス
    */
    Element *p;
    Element *head = &node[0];  // 線形リストの先頭
    printf("address, data, next\n");
    for (p = head; p != NULL; p = p->next)
        printf("%p, %d, %p\n", p, p->data, p->next);
}
