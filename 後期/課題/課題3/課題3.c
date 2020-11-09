#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int sp;

void push(int data) {
    if (sp < STACK_SIZE - 1)
        stack[++sp] = data;
    else
        printf("これ以上格納できません\n");
}

int pop() {
    if (sp > -1)
        return stack[sp--];
    else {
        printf("データが一つも格納されていません\n");
        return -1;
    }
}

void initialize() {
    sp = -1;
}

void display() {
    for (int i = STACK_SIZE - 1; i >= 0; i--) {
        if (i == sp)
            printf("SP->");
        else
            printf("    ");
    printf("%d: %6d\n", i, stack[i]);
    }
}

int c2i(char c) {
    return c - '0';
}

int calculation(char c) {
    int second = pop();
    int first = pop();

    if (c == '+')
        return first + second;

    else if (c == '-')
        return first - second;

    else if (c == '*')
        return first * second;

    else
        return first / second;
}

int main(void) {
    char word;
    FILE *fp;

    initialize();
    fp = fopen("formula.txt", "r");
    while (fscanf(fp, "%c", &word) != EOF) {
        if (isdigit(word)) {
            printf("number %c\n", word);
            push(c2i(word));

        } else if (word == '\n') {
            printf("result = %d\n", stack[sp]);
            pop();

        } else {
            printf("operator %c\n", word);
            push(calculation(word));
        }
        display();
    }
    fclose(fp);
}
