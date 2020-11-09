#include <stdio.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE]; /* Queue Area */
int head, tail;         /* Queue in:out Point */
int count;             /* count of Queue member */

// 設問１：enterqの完成
void enterq(int data) {
    if (count < QUEUE_SIZE) {
        queue[tail++] = data;
        if (tail == QUEUE_SIZE)
            tail = 0;
        count++;
    } else
        printf("Queueが最大です\n");
}

// 設問２：removeqの完成
int removeq() {
    int tmp;

    if (count > 0) {
        tmp = queue[head++];
        if (head == QUEUE_SIZE)
            head = 0;
        count--;
        return tmp;
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

// 設問３：initializeの完成
void initialize() {
    head = 0;
    tail = 0;
    count = 0;
}

// 設問４：displayの完成
void display() {
    int i;
    // キューの(イメージ的に)左から右に for文を回す
    for (i = 0; i < QUEUE_SIZE; i++) {
        // haed の位置には head-> と出力．でなければスペース
        if (i == head)
            printf("head->");
        else
            printf("      ");
        // 要素番号とキューの値を出力
        printf("%6d:%6d", i, queue[i]);
        // tail の位置には <-tail と出力．でなければスペース
        if (i == tail)
            printf(" <-tail");
        else
            printf("       ");
        printf("\n");
    }
}

int main(void) {
    int mode = 1, id;

    initialize();
    while (mode) {
        printf("?enter(1) or remove(0) = ");
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問５：id の値をキューに入力
            enterq(id);
        } else if (mode == 0) {
            // 設問６：キューから値を出力し，id に代入
            id = removeq();
            if (id > 0)
                printf("id = %d was removed\n", id);
        }
        // 設問７：キューの中身を表示
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
    return 0;
}
