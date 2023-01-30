#include<stdio.h>

int main() {
    double p1, p2, p3, p4, p5, ans;

    scanf("%lf %lf %lf %lf %lf", &p1, &p2, &p3, &p4, &p5);

    ans = p1 * p2 * p3 * p4 * p5;
    printf("%.15f", ans);

    return 0;
}