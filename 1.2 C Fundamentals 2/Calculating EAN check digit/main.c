#include <stdio.h>

int main(void) {
    long long int num, q;
    scanf("%lld", &num);
    int s = 0, i = 0, a = 0, b = 0;
    int x = 0;

    for(long long int q = 100000000000;q >= 1; q/=10) {
        int t = (num - num % q) / q - s;
        if (i % 2) {
            a += t;
        }
        else {
            b += t;
        }
        i++;
        s = 10 * (num - num % q) / q;
    }

    x = 9 - ((a * 3 + b - 1) % 10);
    printf("%d", x);

    return 0;
}
