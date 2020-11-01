#include <stdio.h>

#define STACK_SIZE 5   /* Stack Size */
int stack[STACK_SIZE]; /* Stack Area */
int sp;                /* Stack Point */

// 設問１：push()の完成
void push(int data) {
    if (sp < STACK_SIZE - 1)
        stack[++sp] = data;
    else
        printf("これ以上格納できません\n");
}

// 設問２：pop()の完成
int pop() {
    if (sp > -1)
        return stack[sp--];
    else {
        printf("データが一つも格納されていません\n");
        return -1;
    }
}

// 設問３：initialize()の完成
void initialize() {
    // sp の値を初期化
    sp = -1;
}

// 設問４：display()の完成
void display() {
    int i;
    for (i = STACK_SIZE - 1; i >= 0; i--) { // スタックの上から下に for文を回す
        if (i == sp) // スタックポインタの位置のとき SP-> を出力
            printf("SP->");
        else
            printf("    ");
    // 要素番号とスタックの値を出力
    printf("%d: %6d\n", i, stack[i]);
    }
}

int main(void) {
    int mode = 1, id;
    // 設問５：スタックを初期化
    initialize();
    while (mode) {
        printf("?push(1) or pop(0) = ");
        scanf("%d", &mode);
        if (mode == 1) {
            printf("?id = ");
            scanf("%d", &id);
            // 設問６：id の値をスタックに入力
            push(id);
        } else if (mode == 0) {
            // 設問７：スタックから値を出力し id に代入
            id = pop();
            if (id > 0)
                printf("id = %d was picked\n", id);
        }
        // 設問８：スタックの中身を表示
        display();
        printf("?continue(1) or quit(0) = ");
        scanf("%d", &mode);
    }
}

/*
?push(1) or pop(0) = 1
?id = 10
    4:      0
    3:      0
    2:      0
    1:      0
SP->0:     10
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 1
?id = 20
    4:      0
    3:      0
    2:      0
SP->1:     20
    0:     10
?continue(1) or quit(0) = 1
?push(1) or pop(0) = 0
id = 20 was picked
    4:      0
    3:      0
    2:      0
    1:     20
SP->0:     10
?continue(1) or quit(0) = 0
*/
