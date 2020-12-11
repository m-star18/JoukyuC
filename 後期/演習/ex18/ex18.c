/* 上級CプログラミングB 出題日：2020/12/09
   3I 10番 氏名 伊藤竜聖 提出日： 2020/12/11 忘れずに記入！！ */
/* ファイル名：ex19.c
   演習 木の静的な作成．縦型探索用 の printTree 関数を作成
*/

#include <stdio.h>

#define NODE_SIZE 10

// 設問. ノード用の構造体（struct Node）の定義
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// 設問. 根を指すポインタ root の宣言，初期化
struct Node *root;
struct Node tree[NODE_SIZE];

int count;

void initialize() {
    root = NULL;
    for (int i = 0; i < NODE_SIZE; i++) {
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
}

// 行きがけ順
void preorder(struct Node *p) {
    if (p != NULL) {
        printf("number: %d, data: %d\n", count++, p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

// 通りがけ順
void inorder(struct Node *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("number: %d, data: %d\n", count++, p->data);
        inorder(p->right);
    }
}

// 帰りがけ順
void postorder(struct Node *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("number: %d, data: %d\n", count++, p->data);
    }
}

void PrintTree() {
    // 行きがけ順
    printf("行きがけ順\n");
    count = 1;
    preorder(root);

    // 通りがけ順
    printf("\n通りがけ順\n");
    count = 1;
    inorder(root);

    // 帰りがけ順
    printf("\n帰りがけ順\n");
    count = 1;
    postorder(root);
}

int main() {
    // 設問．構造体配列(要素数10)を宣言し，木を静的に作成
    int Data[NODE_SIZE] = {21, 15, 10, 49, 35, 77, 92, 86, 83, 93};

    // data部に値を代入し，left, right を正しく接続
    for (int i = 0; i < NODE_SIZE; i++)
        tree[i].data = Data[i];
    initialize();

    // 木の設定
    tree[0].left = &tree[1];
    tree[0].right = &tree[3];

    tree[1].left = &tree[2];

    tree[3].left = &tree[4];
    tree[3].right = &tree[5];

    tree[5].right = &tree[6];

    tree[6].left = &tree[7];
    tree[6].right = &tree[9];

    tree[7].left = &tree[8];

    root = &tree[0];

    // 設問．根の設定
    PrintTree();
}

// 行きがけ順，通りがけ順，帰りがけ順のそれぞれの出力結果を貼り付ける

/*
行きがけ順
number: 1, data: 21
number: 2, data: 15
number: 3, data: 10
number: 4, data: 49
number: 5, data: 35
number: 6, data: 77
number: 7, data: 92
number: 8, data: 86
number: 9, data: 83
number: 10, data: 93

通りがけ順
number: 1, data: 10
number: 2, data: 15
number: 3, data: 21
number: 4, data: 35
number: 5, data: 49
number: 6, data: 77
number: 7, data: 83
number: 8, data: 86
number: 9, data: 92
number: 10, data: 93

帰りがけ順
number: 1, data: 10
number: 2, data: 15
number: 3, data: 35
number: 4, data: 83
number: 5, data: 86
number: 6, data: 93
number: 7, data: 92
number: 8, data: 77
number: 9, data: 49
number: 10, data: 21
*/
