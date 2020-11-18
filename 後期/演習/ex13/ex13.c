#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head, *tail;

void initialize() {
    head = NULL;
    tail = NULL;
}

/* 設問 １：スタックの入出力関数 push, pop を作成 */
void push(int data) {
    struct Element *p;

    p = malloc(sizeof(struct Element));
    p->data = data;
    p->next = head;
    head = p;
}

int pop() {
    if (head == NULL)
        return -1;

    else {
        int data;
        struct Element *p;

        p = head;
        data = p->data;
        head = p->next;
        free(p);
        return data;
    }
}

/* 設問 2：キューの入出力関数 enterq, removeq を作成 */
void enterq (int data) {
    struct Element *p;

    p = malloc(sizeof(struct Element));
    p->data = data;

    if (head == NULL) {
        head = p;
        tail = p;

    } else {
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
}

int removeq() {
    if (head == NULL)
        return -1;

    else {
        int data;
        struct Element *p;

        p = head;
        data = p->data;
        head = p->next;
        free(p);
        return data;
    }
}

void display() {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main(void) {
    int mode = 1, id, flag;

    printf("stack: 1 queue: 2 ");
    scanf("%d", &flag);

    initialize();
    while (mode) {
        printf("list process ?input(1) or output(2) = ");
        scanf("%d", &mode);

        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);

            if (flag == 1)
                push(id);
            else
                enterq(id);

        } else if (mode == 2) {
            if (flag == 1)
                id = pop();
            else
                id = removeq();

            if (id == -1)  // 取り出し失敗
                printf("empty\n");
            else
                printf("id = %d was picked\n", id);
        }

        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}
