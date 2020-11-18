/* 上級CプログラミングB 出題日：2020/11/11
   3I 10番 氏名 伊藤竜聖 提出日：2020/11/18 */
/* ファイル名：ex12.c
   演習 リストの操作
   設問 initialize(), add(), delete(), insert(), search() を作成する
*/
#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

/* 設問 １：リストの基本処理のための関数を作成 */
void initialize()
{
}

void add(int data)
{
}

int delete(int data)
{
}

void insert(int index, int data)
{
}

int search(int data)
{
}

/* displayは変更の必要はない */
void display()
{
    int i;
    struct Element *p;
    for (i=0,p=head; p!=NULL; i++,p=p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main(void)
{
    int mode = 1, id;
    // 線形リストの初期化

    while (mode) {
        printf("list process ?add(1), insert(2), search(3) or delete(0) = "); 
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?data = ");
            scanf("%d", &id);
            // 設問２：ノードの追加を実行

        } else if (mode == 2) {
            int data;
            printf("?index = ");
            scanf("%d", &id);
            printf("?data = ");
            scanf("%d", &data);
            // 設問３：ノードの挿入を実行

        } else if (mode == 3) {
            int index;
            printf("?data = ");
            scanf("%d", &id);
            // 設問４：ノードの探索を実行（index = ??;）

            if (index == -1) {
                printf("data = %d was not found\n", id);
            } else {
                printf("data = %d was found at %d\n", id, index);
            }
        } else if (mode == 0) {
            printf("?data = ");
            scanf("%d", &id);
            if (delete(id) < 0)
                printf("id = %d was not found\n", id);
        }
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/* add(), delete(), insert(), search() の動作確認ができる出力結果を貼る */
