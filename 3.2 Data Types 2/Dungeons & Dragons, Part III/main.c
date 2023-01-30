#include <stdio.h>
#define NUMBER_1  0x38E38E38E38E3800LLU
#define NUMBER_2  0x2AAAAAAAAAAAAAAALLU
#define NUMBER_3  0x1C71C71C71C71C71LLU
#define MOD 0x7CE66C50E2840000LLU

int main () {

    int d1, d2, d3;

    scanf("%d %d %d", &d1, &d2, &d3);

    printf("%llu", (((NUMBER_1*d1 % MOD) + (NUMBER_2*d2 % MOD)) % MOD + (NUMBER_3*d3 % MOD)) % MOD);

    return 0;
}