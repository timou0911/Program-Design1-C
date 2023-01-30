#include<stdio.h>

int main () {

    float xt, ht1 = 0;

    scanf("%f", &xt);

    for (int i = 0 ; i < 5 ; i++) {
        ht1 = 0.9 * xt + 0.1 * ht1 + (-51);
        xt = (-0.98) * ht1 + 153; // 用 xt 代替 yt1，作為下一天的 xt
        printf("%.1f ", xt);
    }


    return 0;
}
