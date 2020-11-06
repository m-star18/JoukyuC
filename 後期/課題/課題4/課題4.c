#include <stdio.h>

# define QUEUE_SIZE 5

/* 問題1 */
typedef struct queue {
    int queue[QUEUE_SIZE];
    int head;
    int tail;
    int conut;
} Queue_kouzou;

void enterq(int data, Queue_kouzou *q) {
    if (q->conut < QUEUE_SIZE) {
        q->queue[q->tail++] = data;
        if (q->tail == QUEUE_SIZE)
            q->tail = 0;
        q->conut++;

    } else
        printf("Queueが最大です\n");
}

int removeq(Queue_kouzou *q) {
    int tmp;

    if (q->conut > 0) {
        tmp = q->queue[q->head++];
        if (q->head == QUEUE_SIZE)
            q->head = 0;
        q->conut--;
        return tmp;

    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

void initialize(Queue_kouzou *q) {
    q->head = 0;
    q->tail = 0;
    q->conut = 0;
}

void display(Queue_kouzou *q) {
    for (int i = 0; i < QUEUE_SIZE; i++) {
        if (i == q->head)
            printf("head->");
        else
            printf("      ");

        printf("%6d:%6d", i, q->queue[i]);

        if (i == q->tail)
            printf(" <-tail");
        else
            printf("       ");
        printf("\n");
    }
}

int main() {
    int price[] = {200, 400, 800, 100, 900, 600, 500, 300, 700, 100};
    int i = 0, value;
    int sum_a = 0, sum_b = 0;
    char word;
    FILE *fp;

    Queue_kouzou a;
    Queue_kouzou b;

    initialize((Queue_kouzou *) &a);
    initialize((Queue_kouzou *) &b);

    fp = fopen("list.txt", "r");
    while (fscanf(fp, "%c", &word) != EOF) {
        if (word == 'a')
            enterq(price[i++], (Queue_kouzou *) &a);
        else if (word == 'b')
            enterq(price[i++], (Queue_kouzou *) &b);
    }

    display((Queue_kouzou *) &a);
    display((Queue_kouzou *) &b);

    while (1) {
        value = removeq((Queue_kouzou *) &a);
        if (value == -1)
            break;
        sum_a += value;
    }

    while (1) {
        value = removeq((Queue_kouzou *) &b);
        if (value == -1)
            break;
        sum_b += value;
    }

    printf("aの合計金額: %d\nbの合計金額: %d\n", sum_a, sum_b);
    display((Queue_kouzou *) &a);
    display((Queue_kouzou *) &b);

    fclose(fp);
}
