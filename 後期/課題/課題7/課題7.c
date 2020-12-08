#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char data[30];
    struct Element *next;
};

struct Element *head, *tail;

void initialize() {
    head = NULL;
    tail = NULL;
}

void enter_str(char data[]) {
    struct Element *p;

    p = malloc(sizeof(struct Element));
    strcpy(p->data, data);

    if (head == NULL) {
        head = p;
        tail = p;

    } else {
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
}

void display() {
    if (head->next != NULL) {
        printf("%s", head->data);
        head = head->next;
        printf("\n");
    } else
        printf("ファイルの末尾まで到達した\n");
}

int main() {
    char words[30], word, flag;
    int i = 0;
    FILE *fp;

    fp = fopen("kadai7_input.txt", "r");
    while (fscanf(fp, "%c", &word) != EOF) {
        if (word == '\n') {
            enter_str(words);
            strcpy(words, "");
            i = 0;
        } else
            words[i++] = word;
    }
    enter_str(words);
    fclose(fp);

    while (1) {
        printf("n -> 表示, q -> 終了");
        scanf(" %c", &flag);
        if (flag == 'n')
            display();
        else if (flag == 'q')
            break;
        else
            continue;
    }
}
