#include <stdio.h>

int main () {

    unsigned int temp = 0x00000000, n;
    int d1, d2, d3, d4;
    scanf("%d", &n);
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    // step. 2
    temp += (n << 8*(d1-1) >> 24) ^ (n << 8*(d2-1) >> 24);
    temp = temp << 8;
    // step. 3
    temp += (n << 8*(d2-1) >> 24) & (n << 8*(d3-1) >> 24);
    temp = temp << 8;
    // step. 4
    temp += (n << 8*(d3-1) >> 24) | (n << 8*(d1-1) >> 24);
    temp = temp << 8;
    // step. 5
    temp += ~(n << 8*(d4-1) >> 24) << 24 >> 24;
    // step. 6
    temp = (temp >> (d1+d2+d3+d4)) + (temp << (32-d1-d2-d3-d4));
    // step. 7
    int upper = temp >> 16;
    int lower = temp << 16 >> 16;
    printf("%d", upper ^ lower);

    return 0;
}