#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char data[4];
    struct Element *next;
};
struct Element *head;

void add(char data[]) {
    struct Element *p;

    p = (struct Element *) malloc(sizeof(struct Element));
    strcpy(p->data, data);
    p->next = head;
    head = p;
}

void initialize() {
    head = NULL;

    add("興");
    add("鋼");
    add("公");
    add("校");
    add("巧");
    add("晃");
    add("皇");
    add("項");
    add("高");
    add("工");
}

void display() {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%3d: %s", i, p->data);
    printf("\n");
}

int main(void) {
    int mode = 1, id;

    /* 設問：探索用リストを構築 "興", "鋼", "公", "校", "巧", "晃", "皇", "項", "高", "工" */
    initialize();

    display();
    while (mode) {
        int i;
        struct Element *p, *q;

        printf("?id = ");
        // 設問：id の読み取り(この id つまり番号が変換したい漢字を指すことになる)
        scanf("%d", &id);

        /* 設問：自己再編成探索 */
        for (i = 0, p = q = head; i < id && p->next != NULL; i++, q = p, p = p->next);

        // 設問：変換結果（選択した候補のデータ部）の表示
        printf("%s\n", p->data);
        if (p != head && p != NULL) {
            // 設問：自己再編成探索．p と q の next, head をつなぎかえ
            q->next = p->next;
            p->next = head;
            head = p;
        }
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}
