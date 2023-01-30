#include<stdio.h>
#define SQUARED3 1.7320508f

int main () {
    int a;
    scanf("%d", &a);
    printf("%.3f", SQUARED3 / 4 * a * a);
    return 0;
}