#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
    if (k == 0) {
        *f2k = 1;
        *f2k1 = 1;
        return;
    }

    uint64_t arr[k * 2 + 1];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2 ; i < k * 2 + 1 ; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    *f2k = arr[k * 2 - 1];
    *f2k1 = arr[k * 2];
}