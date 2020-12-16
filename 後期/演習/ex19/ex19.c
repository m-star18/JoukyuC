#include <stdio.h>
#include <stdlib.h>

#define SEARCH_DATA1 35
#define SEARCH_DATA2 34

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *nodeAdd(struct Node *p, int data) {
    // 設問：挿入用関数の作成
    if (p == NULL) {
        p = (struct Node *) malloc(sizeof(struct Node));
        p->data = data;

    } else {
        if (p->data == data) {
            printf("挿入失敗しました\n");
        } else if (p->data > data) {
            p->left = nodeAdd(p->left, data);
        } else {
            p->right = nodeAdd(p->right, data);
        }
    }
    return p;
}

void nodeSearch(struct Node *p, int data) {
    // 設問：探索用関数の作成
    if (p == NULL) {
        printf("探索失敗しました\n");
    } else {
        if (p->data == data)
            printf("成功しました\n");
        else if (p->data > data)
            nodeSearch(p->left, data);
        else
            nodeSearch(p->right, data);
    }
}

void PrintTree(struct Node *p) {
    if (p != NULL) {
        PrintTree(p->left);
        printf("%d\n", p->data);
        PrintTree(p->right);
    }
}

int main() {
    int i;
    int a[10] = {21, 49, 35, 15, 77, 92, 93, 86, 83, 10};

    // 設問：順に挿入
    for (i = 0; i < 10; i++)
        root = nodeAdd(root, a[i]);
    // 設問：通りがけ順で出力
    PrintTree(root);
    // 設問：35 を探索
    nodeSearch(root, SEARCH_DATA1);
    // 設問：34 を探索
    nodeSearch(root, SEARCH_DATA2);
}

/* 出力結果の貼り付け */
/*
10
15
21
35
49
77
83
86
92
93
成功しました
探索失敗しました
*/
