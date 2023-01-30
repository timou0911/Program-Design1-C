#include<stdio.h>

int main () {
    int w, h;
    float h1;
    scanf("%d %d", &h, &w);
    h1 = h / 100.;
    printf("%.6f", w/(h1*h1));
    return 0;
}