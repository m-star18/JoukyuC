#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

void node_display(struct Element *p, struct Element *q) {
    int j;
    struct Element *r;

    for (j = 0, r = head; r != NULL; j++, r = r->next) {
        printf("%6d: %p %6d %p", j, r, r->data, r->next);
        if (r == p && r == q)
            printf(" <-p, q¥n");
        else if (r == p)
            printf(" <-p¥n");
        else if (r == q)
            printf(" <-q¥n");
        else
            printf("¥n");
    }
}

void add(int data) {
    struct Element *p;

    p = malloc(sizeof(struct Element));
    p->data = data;
    p->next = head;
    head = p;
}

int delete(int data) {
    int i;
    struct Element *p, *q;

    for (i = 0, p = q = head; p != NULL; i++, q = p, p = p->next) {
        node_display(p, q);
        if (p->data == data) {
            if (p == head) {
                head = p->next;
                free(p);
            } else {
                q->next = p->next;
                free(p);
            }
            return i;
        }
    }
    return -1;
}

void insert(int index, int data) {
    if (index <= 0 || head == NULL)
        add(data);
    else {
        int i;
        struct Element *p, *q, *r;

        for (i = 0, p = q = head; i < index && p->next != NULL; i++, q = p, p = p->next) {
            node_display(p, q);
            r = malloc(sizeof(struct Element));
            r->data = data;
            if (i == index) {
                q->next = r;
                r->next = p;

            } else {
                p->next = r;
                r->next = NULL;
            }
        }
        node_display(p, q);
    }
}

void display(struct Element *q) {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; i++, p = p->next) {
        printf("%6d: %p %6d %p", i, p, p->data, p->next);
        if (p == q)
            printf(" *****¥n");
        else
            printf("¥n");
    }
}
