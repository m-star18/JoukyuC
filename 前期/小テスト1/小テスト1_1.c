#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 1000
#define Y 100

int main() {
    int data[Y];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < Y; i++)
        data[i] = rand() % X;
}
