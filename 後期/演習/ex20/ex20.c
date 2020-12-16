/* 上級CプログラミングB 出題日：2020/12/16
   3I 番 氏名 提出日：忘れずに記入！！ */
/* ファイル名：ex20.c
   リストによる自己再編成探索
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char data[4];
    struct Element *next;
};
struct Element *head;

void initialize()
{
    head = NULL;
}

void display()
{
    int i;
    struct Element *p;
    for (i=0,p=head; p!=NULL; i++,p=p->next)
        printf("%3d: %s", i, p->data);
    printf("\n");
}

int main(void)
{
    initialize();
    /* 設問：探索用リストを構築
        "興", "鋼", "公", "校", "巧", "晃", "皇", "項", "高", "工"
    */

    /* 以下で自己再編成探索システムを記述 */
    int mode = 1, id;

    display();
    while(mode) {
        int i;
        struct Element *p, *q;

        printf("?id = ");
        // 設問：id の読み取り(この id つまり番号が変換したい漢字を指すことになる)
        scanf();

        /* 設問：自己再編成探索 */
        // p を 選択した候補，q をその一つ前まで移動させる（id 番目まで移動させる）
        for ();
        // 設問：変換結果（選択した候補のデータ部）の表示
        printf();
        if (){ // 選択した候補が既に先頭か，リストが空のとき，何もしない
        } else {
          // 設問：自己再編成探索．p と q の next, head をつなぎかえ
        }
        display();
        printf("?continue(1) or quit(0) = "); scanf("%d", &mode);
    }
}
