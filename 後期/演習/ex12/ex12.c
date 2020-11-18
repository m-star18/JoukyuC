#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element *next;
};
struct Element *head;

/* 設問 １：リストの基本処理のための関数を作成 */
void initialize() {
    head = NULL;
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
    }
}

int search(int data) {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; p = p->next, i++) {
        if (p->data == data)
            return i;
    }
    return -1;
}

/* displayは変更の必要はない */
void display() {
    int i;
    struct Element *p;

    for (i = 0, p = head; p != NULL; i++, p = p->next)
        printf("%6d: %p %6d %p\n", i, p, p->data, p->next);
}

int main(void) {
    int mode = 1, id;
    // 線形リストの初期化
    initialize();

    while (mode) {
        printf("list process ?add(1), insert(2), search(3) or delete(0) = "); 
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?data = ");
            scanf("%d", &id);
            // 設問２：ノードの追加を実行
            add(id);

        } else if (mode == 2) {
            int data;
            printf("?index = ");
            scanf("%d", &id);
            printf("?data = ");
            scanf("%d", &data);
            // 設問３：ノードの挿入を実行
            insert(id, data);

        } else if (mode == 3) {
            int index;

            printf("?data = ");
            scanf("%d", &id);
            // 設問４：ノードの探索を実行（index = ??;）
            index = search(id);

            if (index == -1)
                printf("data = %d was not found\n", id);
            else
                printf("data = %d was found at %d\n", id, index);

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
