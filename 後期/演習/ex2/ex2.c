#include <stdio.h>
#include <string.h>

int main() {
    /* 設問１：氏名(name)，身長(height)，体重(weight)を管理するための構造体を定義 */
    struct body {
        char name[20];
        int height;
        double weight;
    };

    /* 設問２：構造体変数 a を宣言し，
    各メンバに "高専太郎", 174, 64.2 を代入 */
    struct body a;

    strcpy(a.name, "高専太郎");
    a.height = 174;
    a.weight = 64.2;

    /* 設問３：「氏名：高専太郎，身長：174 cm 体重：64.2 kg」と出力 */
    printf("氏名：%s，身長：%d cm 体重：%.1lf kg\n", a.name, a.height, a.weight);

    /* 設問４：構造体ポインタ p を用いて，構造体 a の情報を設問３と同様に出力 */
    struct body *p;

    p = &a;
    printf("氏名：%s，身長：%d cm 体重：%.1lf kg\n", p->name, p->height, p->weight);

    /* 設問５：struct body 型の構造体配列 b (要素数3) を宣言し，
    0番目の要素に "高専太郎", 174, 64.2
    1番目の要素に "高専次郎", 163, 58.1
    2番目の要素に "高専三郎", 168, 70.3
    を代入 */
    struct body b[3] = {{"高専太郎", 174, 64.2},
                        {"高専次郎", 163, 58.1},
                        {"高専三郎", 168, 70.3},
            };

    /* 設問６：構造体配列の情報を設問３と同様に出力．for文を用いること */
    for (int i = 0; i < 3; i++)
        printf("氏名：%s，身長：%d cm 体重：%.1lf kg\n", b[i].name, b[i].height, b[i].weight);
}
