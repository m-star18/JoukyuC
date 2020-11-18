/* 上級CプログラミングB 出題日：2020/11/16
   3I ○番 氏名 提出日：忘れずに記入！！ */
/* ファイル名：ex13.c
   演習 線形リストによるスタック，キューの実現
   設問：pop(), push(), enterq(), removeq() の作成
*/

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head, *tail;

void initialize()
{
    head = tail = NULL;
}

/* 設問 １：スタックの入出力関数 push, pop を作成 */
void push(int data)
{
    struct Element *p;
    p = ;
    p->data =;
    p->next =;
    head =;
}

int pop()
{
}

/* 設問 2：キューの入出力関数 enterq, removeq を作成 */
void enterq (int data)
{
}

int removeq()
{

void display() /* 変更しない */
{
    int i;
    struct Element *p;
    for (i=0,p=head; p!=NULL; i++,p=p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

/* スタックを使用する場合には push(id);, id=pop(); の行，
   キューを使用する場合には enterq(id);, id=removeq(); の行
   のコメントを外す
 */
int main(void)
{
    int mode = 1, id;
    initialize();
    while (mode) {
        printf("list process ?input(1) or output(2) = ");
        scanf("%d", &mode);
        if(mode == 1){
            printf("?id = ");
            scanf("%d", &id);
            /* push(id); //スタック */
            /* enterq(id); //キュー */
        }else if(mode == 2){
            /* id = pop(); //スタック */
            /* id = removeq(); //キュー */
            if(id == -1){  // 取り出し失敗
                printf("empty\n");
            }else{
                printf("id = %d was picked\n", id);
            }
        }

        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/* スタック，キュー の動作が確認ができる出力結果を貼る */