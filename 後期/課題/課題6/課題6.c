#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 50

struct Element {
    int data;
    struct Element *next;
};

struct Element *head;

void display(struct Element *q) {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; i++, p = p->next) {
        printf("%6d: %p %6d %p", i, p, p->data, p->next);
        if (p == q)
            printf(" *****\n");
        else
            printf("\n");
    }
    printf("--------------------\n");
}

void add(int data) {
    struct Element *p;

    p = malloc(sizeof(struct Element));
    p->data = data;
    p->next = head;
    head = p;
    display(p);
}

void insert_sort(int data) {
    struct Element *p, *q, *r;
    if (head == NULL)
        add(data);
    else {
        // 挿入位置までp, q を動かす
        for (p = q = head; p != NULL && p->data > data; q = p, p = p->next);
        r = malloc(sizeof(struct Element));
        r->data = data;
        if (p == head) {
            r->next = head;
            head = r;

        } else {
            q->next = r;
            r->next = p;
        }
        display(r);
    }
}

void reverse_list() {
    struct Element *p, *q;

    p = q = head;
    while (p != NULL) {
        p = p->next;
        if (q == head)
            q->next = NULL;
        else
            q->next = head;
        head = q;
        q = p;
    }
    display(q);
}

int main() {
    int i, n;

    printf("配列のサイズを入力してください. ");
    scanf("%d", &n);

    srand((unsigned) time(NULL));
    for (i = 0; i < n; i++)
        insert_sort(rand() % (MAX_VALUE + 1));

    /* 問題3 */
    reverse_list();
}
