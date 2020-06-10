#include <stdio.h>
#include <math.h>
#define N 5

struct node {
    double x;
    double y;
    double dist;
};

int main(void) {
    struct node xy[N];
    int i;

    for (i = 0; i < N; i++) {
        printf("point[%d] (x, y) = ", i);
        scanf("%lf %lf", &xy[i].x, &xy[i].y);
    }

    for (i = 0; i < N - 1; i++) {
        xy[i].dist = sqrt(pow(xy[i].x - xy[i + 1].x, 2.0) + pow(xy[i].y - xy[i + 1].y, 2.0));
        printf("Location(%.2lf, %.2lf) - (%.2lf, %.2lf), ", xy[i].x, xy[i].y, xy[i + 1].x, xy[i + 1].y);
        printf("dist = %.2lf\n", xy[i].dist);
    }
}
